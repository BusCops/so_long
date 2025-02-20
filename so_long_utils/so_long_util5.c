/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:58:38 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/20 17:53:58 by abenzaho         ###   ########.fr       */
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

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

void	draw_coin_image(t_game *game, int k, int pos)
{
	t_index			in;
	unsigned int	color;
	char			*pixel_bg;
	char			*pixel_cn;
	int				j;

	j = 0;
		j = j + (k / 3) * 150;
	in.i = 0;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{		
			pixel_bg = get_pixel_in_bg(game->bg.img, game->coin.cpos[pos]->x, game->coin.cpos[pos]->y, in);
			pixel_cn = get_pixel_from_image(game->coin.anim, in.j, in.i);
			color = get_color(game->coin.img, (k * 150) + in.j, in.i + j);
            if (get_t(color))
            {
                color = *(unsigned int *)pixel_bg;
            }
			*(unsigned int *)pixel_cn = color;
			in.j++;
		}
		in.i++;
	}
}

void	draw_bg(t_game *game, int pos)
{
	t_index			in;
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
			*(unsigned int *)pixel_cn = *(unsigned int *)pixel_bg;
			in.j++;
		}
		in.i++;
	}
}

int	fill_coin(t_game *game)
{
	int	i;
	static int	frame;
	
	frame = (frame + 1) % 6;
	
	i = 0;
	while (i < game->map.c)
	{
		if (game->coin.cpos[i]->exist == 1)
			draw_coin_image(game, frame, i);
		else if (game->coin.cpos[i]->exist == 0)
		{
			draw_bg(game, i);
		}
		mlx_put_image_to_window(game->mlx, game->win, game->coin.anim.img, game->coin.cpos[i]->x * 150, game->coin.cpos[i]->y * 150);
		i++;
		mlx_do_sync(game->mlx);
	}
	usleep(80000);
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
}

void	save_player_image(t_game *game)
{
	int	img_x;
	int	img_y;

	img_x = 450;
	img_y = 150;
	game->pl.img.img = mlx_xpm_file_to_image
		(game->mlx, "texture/player/player.xpm", &img_x, &img_y);
	if (!game->pl.img.img)
	{
		ft_putstr(2,RED "Error: Player texture is missing! Did he rage quit? 🤔" RESET);
		free_all(game, 1);
	}
	game->pl.img.addr = mlx_get_data_addr(game->pl.img.img,
			&game->pl.img.b_p, &game->pl.img.len,
			&game->pl.img.endian);
}

void	draw_player_standing(t_game *game, int k, int x, int y)
{
	t_index			in;
	unsigned int	color;
	char			*pixel_bg;
	char			*pixel_pl;
	int				j;

	j = 0;
	j = j + (k / 4) * 150;
	in.i = 0;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{		
			pixel_bg = get_pixel_in_bg(game->bg.img, x, y, in);
			pixel_pl = get_pixel_from_image(game->pl.anim, in.j, in.i);
			color = get_color(game->pl.img, (k * 150) + in.j, in.i + j);
            if (get_t(color))
            {
                color = *(unsigned int *)pixel_bg;
            }
			*(unsigned int *)pixel_pl = color;
			in.j++;
		}
		in.i++;
	}
}

void	put_player(t_game *game, int frame)
{
	draw_player_standing(game, frame, game->pl.x_p, game->pl.y_p);
	mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img, game->pl.x_p * 150, game->pl.y_p * 150);
	mlx_do_sync(game->mlx);
	usleep(80000);
}

void	get_and_put_player(t_game *game)
{
	save_player_image(game);
	game->pl.anim.img = mlx_new_image(game->mlx, 150, 150);
	game->pl.anim.addr = mlx_get_data_addr(game->pl.anim.img,
	 	&game->pl.anim.b_p, &game->pl.anim.len,
	 	&game->pl.anim.endian);
	game->pl.x_p = game->map.yp;
	game->pl.y_p = game->map.xp;
}

int	put_all(t_game *game)
{
	fill_coin(game);
	return (0);
}

void	draw_player_moving(t_game *game,int k, int x, int y,int p)
{
	t_index			in;
	unsigned int	color;
	char			*pixel_bg;
	char			*pixel_pl;
	int				j;

	(void)p;
	j = 0;
	j = j + (k / 7) * 150;
	in.i = 0;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{
			pixel_bg = get_pixel_in_bg_offset(game->bg.img, x , y, in, p);
			pixel_pl = get_pixel_from_image(game->pl.anim, in.j, in.i);
			color = get_color(game->pl.img, (k * 150) + in.j, in.i + j);
            if (get_t(color))
                color = *(unsigned int *)pixel_bg;
			*(unsigned int *)pixel_pl = color;
			in.j++;
		}
		in.i++;
	}
}

void	move_player_right(t_game *game)
{
	int	frame;
	int	i;
	int	pixel;

	i = 0;
	frame = 21;
	pixel = 15;
	while(i < 10)
	{
		frame = (frame + 1) % 6 + 21;
		draw_player_moving(game, frame, game->pl.x_p, game->pl.y_p , pixel);
		mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img, ((game->pl.x_p) * 150 + pixel), game->pl.y_p * 150);
		usleep(80000);
		pixel = pixel + 15;
		i++;
		mlx_do_sync(game->mlx);
	}
	game->pl.x_p = game->pl.x_p + 1;
	put_player(game , 12);
}

void	move_player_left(t_game *game)
{
	int	frame;
	int	i;
	int	pixel;

	i = 0;
	frame = 15;
	pixel = -15;
	while(i < 10)
	{
		frame = (frame + 1) % 6 + 15;
		draw_player_moving(game, frame, game->pl.x_p, game->pl.y_p , pixel);
		mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img, ((game->pl.x_p) * 150 + pixel), game->pl.y_p * 150);
		usleep(80000);
		pixel = pixel - 15;
		i++;
		mlx_do_sync(game->mlx);
	}
	game->pl.x_p = game->pl.x_p + -1;
	put_player(game , 9);
}
void	draw_player_moving_up_down(t_game *game,int k, int x, int y,int p)
{
	t_index			in;
	unsigned int	color;
	char			*pixel_bg;
	char			*pixel_pl;
	int				j;

	(void)p;
	j = 0;
	j = j + (k / 7) * 150;
	in.i = 0;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{
			pixel_bg = get_pixel_in_bg_offset_u(game->bg.img, x , y, in, p * game->bg.img.len);
			pixel_pl = get_pixel_from_image(game->pl.anim, in.j, in.i);
			color = get_color(game->pl.img, (k * 150) + in.j, in.i + j);
            if (get_t(color))
                color = *(unsigned int *)pixel_bg;
			*(unsigned int *)pixel_pl = color;
			in.j++;
		}
		in.i++;
	}
}

void	move_player_down(t_game *game)
{
	int	frame;
	int	i;
	int	pixel;

	i = 0;
	frame = 0;
	pixel = 15;
	while(i < 10)
	{
		frame = (frame + 1) % 6;
		draw_player_moving_up_down(game, frame, game->pl.x_p, game->pl.y_p , pixel);
		mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img, game->pl.x_p * 150, (game->pl.y_p * 150) + pixel);
		usleep(80000);
		pixel = pixel + 15;
		i++;
		mlx_do_sync(game->mlx);
	}
	//draw_player_moving_up_down(game, 3, game->pl.x_p, game->pl.y_p , pixel);
	//mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img, game->pl.x_p * 150, (game->pl.y_p * 150) + pixel - 14);
	game->pl.y_p = game->pl.y_p + 1;
	put_player(game , 3);
}

void	move_player_up(t_game *game)
{
	int	frame;
	int	i;
	int	pixel;

	i = 0;
	frame = 8;
	pixel = -15;
	while(i < 10)
	{
		frame = (frame + 1) % 6 + 8;
		draw_player_moving_up_down(game, frame, game->pl.x_p, game->pl.y_p , pixel);
		mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img, game->pl.x_p * 150, (game->pl.y_p * 150) + pixel);
		usleep(80000);
		pixel = pixel - 15;
		i++;
		mlx_do_sync(game->mlx);
	}
	game->pl.y_p = game->pl.y_p - 1;
	put_player(game , 6);
}

/*void	save_player_image(t_game *game)
{
	int	img_x;
	int	img_y;

	img_x = 450;
	img_y = 150;
	game->en.img.img = mlx_xpm_file_to_image
		(game->mlx, "texture/enemy/standing.xpm", &img_x, &img_y);
	if (!game->en.img.img)
	{
		ft_putstr(2,RED "Error: Player texture is missing! Did he rage quit? 🤔" RESET);
		free_all(game, 1);
	}
	game->en.img.addr = mlx_get_data_addr(game->en.img.img,
			&game->en.img.b_p, &game->en.img.len,
			&game->en.img.endian);
}*/

/*void	save_enemy_image(t_game *game)
{
	get_enemy_position(game);
	save_enemy_image(game);
	game->en.anim.img = mlx_new_image(game->mlx, 150, 150);
	game->en.anim.addr = mlx_get_data_addr(game->en.anim.img,
	 	&game->en.anim.b_p, &game->en.anim.len,
	 	&game->en.anim.endian);
	game->pl.x_p = game->map.yp;
	game->pl.y_p = game->map.xp;
}*/