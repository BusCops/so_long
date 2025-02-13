/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:49:41 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/13 18:12:44 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	mlx_error(t_game *game)
{
	ft_putstr(2, "Error: MLX failed! 🖥️ Did the X server take a nap? 😴\n");
	ft_free(game->map.map);
	exit(1);
}

void	win_error(t_game *game)
{
	ft_putstr(2, RED "ERROR: Window failed! 🪟 Guess I'll live in the terminal now... 🤡" RESET);
	ft_free(game->map.map);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

void	img_error_w(t_game *game)
{
	ft_putstr(2, RED "ERROR: Wall image failed! 🚧 Now it's just invisible walls... good luck! 🫥" RESET);
	ft_free(game->map.map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

void	save_walls_img(t_game *game)
{
	int	img_x;
	int	img_y;
	
	img_x = 450;
	img_y = 150;
	game->walls.img = mlx_xpm_file_to_image(game->mlx, "texture/walls/walls.xpm", &img_x, &img_y);
	if (!game->walls.img)
		img_error_w(game);
	game->walls.addr = mlx_get_data_addr(game->walls.img, &game->walls.bits_per_pixel, &game->walls.line_length,&game->walls.endian);
}

void	save_ground_img(t_game *game)
{
	int	img_x;
	int	img_y;
	
	img_x = 450;
	img_y = 150;
	game->ground.img = mlx_xpm_file_to_image(game->mlx, "texture/ground/ground.xpm", &img_x, &img_y);
	if (!game->ground.img)
		img_error_g(game);
	game->ground.addr = mlx_get_data_addr(game->ground.img, &game->ground.bits_per_pixel, &game->ground.line_length,&game->ground.endian);
}
/*
void	start_puting_walls(t_map *map, t_img *imgs, void *mlx, void *win)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			k = rand() % 3 > 1;
			if (map->map[i][j] == '1')
				{
					if ((!i && !j) || (!i && j == map->col) || (!j && i == map->row) || (j == map->col && i == map->row))
						mlx_put_image_to_window(mlx, win, imgs->walls[2], j * 150, i * 150);
					else	
						mlx_put_image_to_window(mlx, win, imgs->walls[k], j * 150, i * 150);
				}
			j++;
		}
		i++;
	}
}

void	start_puting_ground(t_map *map, t_img *imgs, void *mlx, void *win)
{
	int	i;
	int	j;
	int	c;
	(void)mlx;
	(void)win;
	(void)imgs;
	
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			c = rand() % 3;
			if (map->map[i][j] == '0' || map->map[i][j] == 'C' || map->map[i][j] == 'E' || map->map[i][j] == 'P' || map->map[i][j] == 'W')
				mlx_put_image_to_window(mlx, win, imgs->ground[c], j * 150, i * 150);
			j++;
		}
		i++;
	}
}
*/