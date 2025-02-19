/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:58:38 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/19 13:20:30 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_with_wall(t_game *game, int x, int y, t_map map)
{
	int				k;
	t_index			in;
	char			*pixel;
	unsigned int	color;

	in.i = 0;
	k = wich_wall(x, y, map.col - 1, map.row - 1);
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{
			pixel = get_pixel_in_bg(game->bg.img, x, y, in);
			color = get_color(game->walls.img, (k * 150) + in.j, in.i);
			*(unsigned int *)pixel = color;
			in.j++;
		}
		in.i++;
	}
}

void	fill_with_ground(t_game *game, int x, int y, int c)
{
	int				k;
	t_index			in;
	char			*pixel;
	unsigned int	color;

	in.i = 0;
	if (c == 'E')
		k = 0;
	else
		k = rand() % 3;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{
			pixel = get_pixel_in_bg(game->bg.img, x, y, in);
			color = get_color(game->ground.img, (k * 150) + in.j, in.i);
			*(unsigned int *)pixel = color;
			in.j++;
		}
		in.i++;
	}
}

void	save_coin_image(t_game *game)
{
	int	img_x;
	int	img_y;

	img_x = 450;
	img_y = 150;
	game->coin.img.img = mlx_xpm_file_to_image
		(game->mlx, "texture/coin/coin.xpm", &img_x, &img_y);
	if (!game->coin.img.img)
	{
		ft_putstr(2, RED "ERROR: Diamond image failed! 💎 No "
			"diamonds, no glory... just disappointment. 😢" RESET);
		free_all(game, 1);
	}
	game->coin.img.addr = mlx_get_data_addr(game->coin.img.img,
			&game->coin.img.b_p, &game->coin.img.len,
			&game->coin.img.endian);
}

void	draw_coin_image(t_game *game, int k, int pos)
{
	t_index			in;
	unsigned int	color;
	char			*pixel_bg;
	char			*pixel_cn;
	
	in.i = 0;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{
			pixel_bg = get_pixel_in_bg(game->bg.img, game->coin.cpos[pos]->x, game->coin.cpos[pos]->y, in);
			pixel_cn = get_pixel_from_image(game->coin.anim, in.j, in.i);
			color = get_color(game->coin.img, (k * 150) + in.j, in.i);
            if (color == 4278190080)
            {
                color = *(unsigned int *)pixel_bg;
            }
			*(unsigned int *)pixel_cn = color;
			in.j++;
		}
		in.i++;
	}
}

int	fill_coin(t_game *game)
{
	int	i;
	int	j;
	
	j = 0;
	while(j < 6)
	{
		i = 0;
		while (i < game->map.c)
		{
			if (game->coin.cpos[i]->exist == 1)
			{
				draw_coin_image(game, j, i);
				mlx_put_image_to_window(game->mlx, game->win, game->coin.anim.img, game->coin.cpos[i]->x * 150, game->coin.cpos[i]->y * 150);
			}
			i++;
		}
		usleep(100000);
		j++;
	}
	return (0);
}

void	search_coin_and_save(t_game *game, char **map)
{
	t_index	in;
	int		c;

	in.i = 0;
	c = 0;
	while (map[in.i])
	{
		in.j = 0;
		while (map[in.i][in.j])
		{
			if (map[in.i][in.j] == 'C')
			{
				game->coin.cpos[c]->x = in.j;
				game->coin.cpos[c]->y = in.i;
				game->coin.cpos[c]->exist = 1;
				c++;
			}
			in.j++;
		}
		in.i++;
	}
}

void	allocate_coin_pos(t_game *game)
{
	int	i;

	i = 0;
	game->coin.cpos = (t_cpos **)malloc(sizeof(t_cpos *) * game->map.c);
	if (!game->coin.cpos)
	{
		ft_putstr(2, "allocation fail");
		free_all(game, 1);
	}
	while (i < game->map.c)
	{
		game->coin.cpos[i] = (t_cpos *)malloc(sizeof(t_cpos));
		i++;
	}
}

void	get_and_put_coin(t_game *game)
{
	save_coin_image(game);
	game->coin.anim.img = mlx_new_image(game->mlx, 150, 150);
	game->coin.anim.addr = mlx_get_data_addr(game->coin.anim.img,
	 	&game->coin.anim.b_p, &game->coin.anim.len,
	 	&game->coin.anim.endian);
	allocate_coin_pos(game);
	search_coin_and_save(game, game->map.map);
	fill_coin(game);
	mlx_loop_hook(game->mlx, fill_coin, game);
}
