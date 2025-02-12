/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:49:41 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/12 17:22:03 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	save_imgs(int img_scale, t_img *imgs, void *mlx)
{
	imgs->walls = (void **)malloc(sizeof(void *) * 4);
	imgs->ground = (void **)malloc(sizeof(void *) * 4);
	imgs->walls[0] = mlx_xpm_file_to_image(mlx, "texture/walls/wall_3.xpm", &img_scale, &img_scale);
	imgs->walls[1] = mlx_xpm_file_to_image(mlx, "texture/walls/wall_1.xpm", &img_scale, &img_scale);
	imgs->walls[2] = mlx_xpm_file_to_image(mlx, "texture/walls/corner.xpm", &img_scale, &img_scale);
	imgs->ground[0] = mlx_xpm_file_to_image(mlx, "texture/ground/ground1.xpm", &img_scale, &img_scale);
	imgs->ground[1] = mlx_xpm_file_to_image(mlx, "texture/ground/ground2.xpm", &img_scale, &img_scale);
	imgs->ground[2] = mlx_xpm_file_to_image(mlx, "texture/ground/ground3.xpm", &img_scale, &img_scale);
	imgs->ground[3] = NULL;
	imgs->walls[3] = NULL;
}

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
