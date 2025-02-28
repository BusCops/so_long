/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:51:53 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/28 16:41:06 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
			pixel_bg = get_pixel(game->bg.img, (150 * x) + in.j,
					(y * 150) + in.i);
			pixel_e = get_pixel(game->exit.anim, in.j, in.i);
			color = get_color(game->exit.img,
					(game->exit.frame * 150) + in.j, in.i + j);
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
	while (i < 22)
	{
		game->exit.frame++;
		draw_exit_helper(game, game->exit.x, game->exit.y);
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.anim.img, game->exit.x * 150,
			game->exit.y * 150);
		custom_usleep();
		i++;
		mlx_do_sync(game->mlx);
	}
	game->cc = 20;
	game->finish = 1;
}

void	finish_game(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'E' && game->finish == 1)
		free_all(game, 0);
}
