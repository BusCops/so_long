/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:41:39 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/26 17:46:59 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_image(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				fill_with_wall(game, j, i, game->map);
			else
				fill_with_ground(game, j, i, map[i][j]);
			j++;
		}
		i++;
	}
}

int	wich_wall(int x, int y, int col, int row)
{
	int	k;

	if ((!y && !x) || (!y && x == col)
		|| (!x && y == row) || (x == col && y == row))
		k = 0;
	else
	{
		k = rand() % 100;
		if (k < 75)
			k = 2;
		else
			k = 1;
	}
	return (k);
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
			pixel_bg = get_pixel_in_bg(game->bg.img,
					game->coin.cpos[pos]->x, game->coin.cpos[pos]->y, in);
			pixel_cn = get_pixel_from_image(game->coin.anim, in.j, in.i);
			*(unsigned int *)pixel_cn = *(unsigned int *)pixel_bg;
			in.j++;
		}
		in.i++;
	}
}
