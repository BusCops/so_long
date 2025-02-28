/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:03:50 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/27 09:54:54 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_player_moving(t_game *game, int x, int y, int p)
{
	t_index			in;
	unsigned int	color;
	char			*pixel_bg;
	char			*pixel_pl;
	int				j;

	j = (game->frame / 7) * 149;
	in.i = 0;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{
			pixel_bg = get_pixel(game->bg.img, (150 * x)
					+ p + in.j, (y * 150) + in.i);
			pixel_pl = get_pixel(game->pl.anim, in.j, in.i);
			color = get_color(game->pl.img,
					(game->frame * 150) + in.j, in.i + j);
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
	int	i;
	int	pixel;

	i = 0;
	game->frame = 21;
	pixel = 15;
	while (i < 10)
	{
		if (pixel == 75)
			coin_founded(game, game->plp.x + 1, game->plp.y);
		fill_coin(game);
		game->frame = (game->frame + 1) % 6 + 21;
		draw_player_moving(game, game->plp.x, game->plp.y, pixel);
		mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img,
			((game->plp.x) * 150 + pixel), game->plp.y * 150);
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
	while (i < 10)
	{
		if (pixel == -75)
			coin_founded(game, game->plp.x - 1, game->plp.y);
		fill_coin(game);
		game->frame = (game->frame + 1) % 6 + 15;
		draw_player_moving(game, game->plp.x, game->plp.y, pixel);
		mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img,
			((game->plp.x) * 150 + pixel), game->plp.y * 150);
		custom_usleep();
		pixel = pixel - 15;
		i++;
		mlx_do_sync(game->mlx);
	}
}

void	move_player_down(t_game *game)
{
	int	i;
	int	pixel;

	i = 0;
	game->frame = 0;
	pixel = 15;
	while (i < 10)
	{
		if (pixel == 45)
			coin_founded(game, game->plp.x, game->plp.y + 1);
		fill_coin(game);
		game->frame = (game->frame + 1) % 6;
		draw_player_moving(game, game->plp.x, game->plp.y,
			pixel * game->bg.img.len / 4);
		mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img,
			game->plp.x * 150, (game->plp.y * 150) + pixel);
		custom_usleep();
		pixel = pixel + 15;
		i++;
		mlx_do_sync(game->mlx);
	}
}

void	move_player_up(t_game *game)
{
	int	i;
	int	pixel;

	i = 0;
	game->frame = 8;
	pixel = -15;
	while (i < 10)
	{
		if (pixel == -45)
			coin_founded(game, game->plp.x, game->plp.y - 1);
		fill_coin(game);
		game->frame = (game->frame + 1) % 6 + 8;
		draw_player_moving(game, game->plp.x, game->plp.y,
			pixel * game->bg.img.len / 4);
		mlx_put_image_to_window(game->mlx, game->win, game->pl.anim.img,
			game->plp.x * 150, (game->plp.y * 150) + pixel);
		custom_usleep();
		pixel = pixel - 15;
		i++;
		mlx_do_sync(game->mlx);
	}
}
