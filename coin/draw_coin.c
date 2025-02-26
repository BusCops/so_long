/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_coin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:09:51 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/26 17:28:57 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	fill_coin(t_game *game)
{
	int			i;
	static int	frame;

	frame = (frame + 1) % 6;
	i = 0;
	while (i < game->map.c)
	{
		if (game->coin.cpos[i]->exist == 1)
		{
			draw_coin_image(game, frame, i);
			mlx_put_image_to_window(game->mlx, game->win, game->coin.anim.img,
				game->coin.cpos[i]->x * 150, game->coin.cpos[i]->y * 150);
		}
		i++;
		mlx_do_sync(game->mlx);
	}
	return (0);
}

void	draw_coin_image(t_game *game, int k, int pos)
{
	t_index			in;
	unsigned int	color;
	char			*pixel_bg;
	char			*pixel_cn;
	int				j;

	j = (k / 3) * 149;
	in.i = 0;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{
			pixel_bg = get_pixel_in_bg(game->bg.img, game->coin.cpos[pos]->x,
					game->coin.cpos[pos]->y, in);
			pixel_cn = get_pixel_from_image(game->coin.anim, in.j, in.i);
			color = get_color(game->coin.img, (k * 150) + in.j, in.i + j);
			if (get_t(color))
				color = *(unsigned int *)pixel_bg;
			*(unsigned int *)pixel_cn = color;
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
		if (game->coin.cpos[i]->x == x && game->coin.cpos[i]->y == y
			&& game->coin.cpos[i]->exist == 1)
		{
			draw_bg(game, i);
			mlx_put_image_to_window(game->mlx, game->win, game->coin.anim.img,
				game->coin.cpos[i]->x * 150, game->coin.cpos[i]->y * 150);
			game->coin.cpos[i]->exist = 0;
			mlx_do_sync(game->mlx);
			game->cc--;
		}
		i++;
	}
}
