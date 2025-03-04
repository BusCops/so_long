/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:11:57 by abenzaho          #+#    #+#             */
/*   Updated: 2025/03/04 13:23:59 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_enemy(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->enemy.e)
	{
		draw_enemy(game, game->enemy.enp[i]->x, game->enemy.enp[i]->y, 0);
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.anim.img,
			150 * game->enemy.enp[i]->x, game->enemy.enp[i]->y * 150);
		i++;
	}
}

void	draw_enemy(t_game *game, int x, int y, int frame)
{
	t_index			in;
	unsigned int	color;
	char			*pixel_bg;
	char			*pixel_en;

	in.i = 0;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{
			pixel_bg = get_pixel(game ->bg.img, (150 * x) + in.j,
					(y * 150) + in.i);
			pixel_en = get_pixel(game->enemy.anim, in.j, in.i);
			color = get_color(game->enemy.img, in.j + (frame * 149), in.i);
			if (get_t(color))
				color = *(unsigned int *)pixel_bg;
			*(unsigned int *)pixel_en = color;
			in.j++;
		}
		in.i++;
	}
}

void	move_enemy(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy.e)
	{
		check_move(game, game->enemy.enp[i]->x, game->enemy.enp[i]->y, i);
		if (game->enemy.enp[i]->move == 1 && game->enemy.t == 200)
			move_en_left(game, game->enemy.enp[i]->x, game->enemy.enp[i]->y, i);
		if (game->enemy.enp[i]->move == 0 && game->enemy.t == 200)
			move_en_right(game, game->enemy.enp[i]->x,
				game->enemy.enp[i]->y, i);
		else if (game->enemy.enp[i]->move == 2)
		{
			draw_enemy(game, game->enemy.enp[i]->x, game->enemy.enp[i]->y, 0);
			mlx_put_image_to_window(game->mlx, game->win,
				game->enemy.anim.img,
				150 * game->enemy.enp[i]->x, game->enemy.enp[i]->y * 150);
			mlx_do_sync(game->mlx);
		}
		draw_animation_en(game, i);
		i++;
	}
	game->enemy.t += 10;
	if (game->enemy.t > 200)
		game->enemy.t = 0;
}

void	draw_animation_en(t_game *game, int i)
{
	static int	t;

	if (t == 20)
	{
		game->enemy.enp[i]->fr = (game->enemy.enp[i]->fr + 1) % 12;
		draw_enemy(game, game->enemy.enp[i]->x, game->enemy.enp[i]->y,
			game->enemy.enp[i]->fr);
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.anim.img,
			150 * game->enemy.enp[i]->x, game->enemy.enp[i]->y * 150);
		mlx_do_sync(game->mlx);
	}
	if (t == 20)
		t = 0;
	t = t + 10;
}
