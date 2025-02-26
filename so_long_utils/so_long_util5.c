/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:58:38 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/26 10:01:07 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	custom_usleep()
{
	int	i;

	i = 0;
	while(i < SPEED)
		i++;
}

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
			"diamonds, no glory... just disappointment. 😢\n" RESET);
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
		j = j + (k / 3) * 149;
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
		{
			draw_coin_image(game, frame, i);
		// if (game->coin.cpos[i]->exist == 0)
		//  	draw_bg(game, i);
			mlx_put_image_to_window(game->mlx, game->win, game->coin.anim.img, game->coin.cpos[i]->x * 150, game->coin.cpos[i]->y * 150);
		}
		i++;
		mlx_do_sync(game->mlx);
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
			if (map[in.i][in.j] == 'E')
			{
				game->exit.x = in.j;
				game->exit.y = in.i;
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
	game->cc = game->map.c;
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
                color = *(unsigned int *)pixel_bg;
			*(unsigned int *)pixel_pl = color;
			in.j++;
		}
		in.i++;
	}
}

void	put_player(t_game *game, int frame)
{
	game->frame = frame;
	draw_player_moving(game, game->plp.x, game->plp.y, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img, game->plp.x * 150, game->plp.y * 150);
	//mlx_do_sync(game->mlx);
	usleep(80000);
}

void	get_and_put_player(t_game *game)
{
	save_player_image(game);
	game->pl.anim.img = mlx_new_image(game->mlx, 150, 150);
	game->pl.anim.addr = mlx_get_data_addr(game->pl.anim.img,
	 	&game->pl.anim.b_p, &game->pl.anim.len,
	 	&game->pl.anim.endian);
	game->plp.x = game->map.yp;
	game->plp.y = game->map.xp;
}

int	put_all(t_game *game)
{
	fill_coin(game);
	return (0);
}

void	move_player_right(t_game *game)
{
	int	i;
	int	pixel;

	i = 0;
	game->frame = 21;
	pixel = 15;
	while(i < 10)
	{
		if (pixel == 75)
			coin_founded(game, game->plp.x + 1, game->plp.y);
		fill_coin(game);
		game->frame = (game->frame + 1) % 6 + 21;
		draw_player_moving(game, game->plp.x, game->plp.y , pixel);
		mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img, ((game->plp.x) * 150 + pixel), game->plp.y * 150);
		custom_usleep();
		pixel = pixel + 15;
		i++;
		mlx_do_sync(game->mlx);
	}
}

void	move_player_left(t_game *game)
{
	int	i;
	int	pixel;

	i = 0;
	game->frame = 15;
	pixel = -15;
	while(i < 10)
	{	
		if (pixel == -75)
			coin_founded(game, game->plp.x - 1, game->plp.y);
		fill_coin(game);
		game->frame = (game->frame + 1) % 6 + 15;
		draw_player_moving(game, game->plp.x, game->plp.y , pixel);
		mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img, ((game->plp.x) * 150 + pixel), game->plp.y * 150);
		custom_usleep();
		pixel = pixel - 15;
		i++;
		mlx_do_sync(game->mlx);
	}
	//game->plp.x = game->plp.x + -1;
	//put_player(game , 9);
}

void	move_player_down(t_game *game)
{
	int	i;
	int	pixel;

	i = 0;
	game->frame = 0;
	pixel = 15;
	while(i < 10)
	{
		if (pixel == 45)
			coin_founded(game, game->plp.x, game->plp.y + 1);
		fill_coin(game);
		game->frame = (game->frame + 1) % 6;
		draw_player_moving(game, game->plp.x , game->plp.y, pixel * game->bg.img.len / 4);
		mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img, game->plp.x * 150, (game->plp.y * 150) + pixel);
		//fill_coin(game);
		custom_usleep();
		pixel = pixel + 15;
		i++;
		mlx_do_sync(game->mlx);
	}
	//draw_player_moving_up_down(game, 3, game->plp.x, game->plp.y , pixel);
	//mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img, game->plp.x * 150, (game->plp.y * 150) + pixel - 14);
	//game->plp.y = game->plp.y + 1;
	//put_player(game , 3);
}

void	move_player_up(t_game *game)
{
	int	i;
	int	pixel;

	i = 0;
	game->frame = 8;
	pixel = -15;
	while(i < 10)
	{
		if (pixel == 30)
			coin_founded(game, game->plp.x, game->plp.y - 1);
		fill_coin(game);
		game->frame = (game->frame + 1) % 6 + 8;
		draw_player_moving(game, game->plp.x, game->plp.y , pixel * game->bg.img.len / 4);
		mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img, game->plp.x * 150, (game->plp.y * 150) + pixel);
		custom_usleep();
		pixel = pixel - 15;
		i++;
		mlx_do_sync(game->mlx);
	}
	//game->plp.y = game->plp.y - 1;
	//put_player(game , 6);
}

void	draw_player_moving(t_game *game, int x, int y,int p)
{
	t_index			in;
	unsigned int	color;
	char			*pixel_bg;
	char			*pixel_pl;
	int				j;

	(void)p;
	j = 0;
	j = j + (game->frame / 7) * 149;
	in.i = 0;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{
			pixel_bg = get_pixel(game->bg.img, (150 * x) + p + in.j , (y * 150) + in.i);
			pixel_pl = get_pixel_from_image(game->pl.anim, in.j, in.i);
			color = get_color(game->pl.img, (game->frame * 150) + in.j, in.i + j);
            if (get_t(color))
                color = *(unsigned int *)pixel_bg;
			*(unsigned int *)pixel_pl = color;
			in.j++;
		}
		in.i++;
	}
}

void	coin_founded(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->map.c)
	{
		if (game->coin.cpos[i]->x == x && game->coin.cpos[i]->y == y && game->coin.cpos[i]->exist == 1)
		{
			draw_bg(game, i);
			mlx_put_image_to_window(game->mlx, game->win, game->coin.anim.img, game->coin.cpos[i]->x * 150, game->coin.cpos[i]->y * 150);
			game->coin.cpos[i]->exist = 0;
			mlx_do_sync(game->mlx);
			game->cc--;
		}
		i++;
	}
}

void	save_exit_image(t_game *game)
{

	int	img_x;
	int	img_y;

	game->exit.img.img = mlx_xpm_file_to_image
		(game->mlx, "texture/exit/exit.xpm", &img_x, &img_y);
	if (!game->exit.img.img)
	{
		ft_putstr(2, RED "ERROR: Well, the exit just decided to disappear. 😢\n" RESET);
		free_all(game, 1);
	}
	game->exit.img.addr = mlx_get_data_addr(game->exit.img.img,
			&game->exit.img.b_p, &game->exit.img.len,
			&game->exit.img.endian);
}

void	get_exit(t_game *game)
{
	save_exit_image(game);
	game->exit.anim.img = mlx_new_image(game->mlx, 150, 150);
	game->exit.anim.addr = mlx_get_data_addr(game->exit.anim.img,
	 	&game->exit.anim.b_p, &game->exit.anim.len,
	 	&game->exit.anim.endian);
}

void	draw_exit_helper(t_game *game, int x, int y)
{
	t_index			in;
	unsigned int	color;
	char			*pixel_bg;
	char			*pixel_e;
	int				j;

	j = (game->exit.frame / 4) * 149;
	in.i = 0;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{
			pixel_bg = get_pixel(game->bg.img, (150 * x) + in.j , (y * 150) + in.i);
			pixel_e = get_pixel_from_image(game->exit.anim, in.j, in.i);
			color = get_color(game->exit.img, (game->exit.frame * 150) + in.j, in.i + j);
            if (get_t(color))
                color = *(unsigned int *)pixel_bg;
			*(unsigned int *)pixel_e = color;
			in.j++;
		}
		in.i++;
	}
}

void	draw_exit(t_game *game)
{
	int	i;

	i = 0;
	game->exit.frame = 0;
	while(i < 22)
	{
		game->exit.frame++;
		draw_exit_helper(game, game->exit.x, game->exit.y);
		mlx_put_image_to_window(game->mlx, game->win, game->exit.anim.img, game->exit.x * 150, game->exit.y * 150);
		custom_usleep();
		i++;
		mlx_do_sync(game->mlx);
	}
	game->cc = 20;
}