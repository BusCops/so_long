/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:49:41 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/25 14:34:53 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	save_walls_img(t_game *game)
{
	int	img_x;
	int	img_y;

	game->walls.img.img = mlx_xpm_file_to_image
		(game->mlx, "texture/walls/walls.xpm", &img_x, &img_y);
	if (!game->walls.img.img)
	{
		ft_putstr(2, RED "ERROR: Wall image failed! 🚧 Now it's"
			" just invisible walls... good luck! 🫥\n" RESET);
		free_all(game, 1);
	}
	game->walls.img.addr = mlx_get_data_addr(game->walls.img.img,
			&game->walls.img.b_p, &game->walls.img.len,
			&game->walls.img.endian);
}

void	save_ground_img(t_game *game)
{
	int	img_x;
	int	img_y;

	game->ground.img.img = mlx_xpm_file_to_image
		(game->mlx, "texture/ground/ground.xpm", &img_x, &img_y);
	if (!game->ground.img.img)
	{
		ft_putstr(2, RED "ERROR: Ground image failed! 🌍 Guess you’re"
			" floating in the void now... 🕳️\n" RESET);
		free_all(game, 1);
	}
	game->ground.img.addr = mlx_get_data_addr(game->ground.img.img,
			&game->ground.img.b_p, &game->ground.img.len,
			&game->ground.img.endian);
}

void	creat_image_and_fill(t_game *game)
{
	game->bg.img.img = mlx_new_image
		(game->mlx, game->map.col * 150, game->map.row * 150);
	if (!game->bg.img.img)
	{
		ft_putstr(2, RED "Error: Error creating background image\n" RESET);
		free_all(game, 1);
	}
	game->bg.img.addr = mlx_get_data_addr(game->bg.img.img,
			&game->bg.img.b_p, &game->bg.img.len, &game->bg.img.endian);
	fill_image(game, game->map.map);
}

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
