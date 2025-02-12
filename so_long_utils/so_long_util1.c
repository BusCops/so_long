/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:49:41 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/12 13:43:04 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	walls(int img_scale, void *mlx, t_img *imgs)
{
	imgs->walls = (void **)malloc(sizeof(void *) * 2);
	imgs->ground = (void **)malloc(sizeof(void *) / 4);
	imgs->walls[0] = mlx_xpm_file_to_image(mlx, "texture/walls/wall_3.xpm", &img_scale, &img_scale);
	imgs->walls[1] = mlx_xpm_file_to_image(mlx, "texture/walls/wall_1.xpm", &img_scale, &img_scale);
	imgs->walls[2] = mlx_xpm_file_to_image(mlx, "texture/walls/corner.xpm", &img_scale, &img_scale);
	imgs->ground[0] = mlx_xpm_file_to_image(mlx, "texture/ground/ground1.xpm", &img_scale, &img_scale);
	imgs->ground[1] = mlx_xpm_file_to_image(mlx, "texture/ground/ground2.xpm", &img_scale, &img_scale);
	imgs->ground[2] = mlx_xpm_file_to_image(mlx, "texture/ground/ground3.xpm", &img_scale, &img_scale);
}
void	put_walls(void *mlx, void *win,t_map *map, t_img *imgs)
{
	int	i;
	int	j;
	int	k;
	int	c;
	int	size1;
	int	size2;

	size1 = ft_strlen(map->map[0]) - 1;
	size2 = ft_pointer_counter(map->map) - 1;
	i = 0;
	k = 0;
	while (map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			k = rand() % 3 > 1;
			c = rand() % 3;
			if (map->map[i][j] == '1')
				{
					if ((!i && !j) || (!i && j == size1) || (!j && i == size2) || (j == size1 && i == size2))
						mlx_put_image_to_window(mlx, win, imgs->walls[2], j * 150, i * 150);
					else	
						mlx_put_image_to_window(mlx, win, imgs->walls[k], j * 150, i * 150);
				}			
			else if (map->map[i][j] == '0' || map->map[i][j] == 'C' || map->map[i][j] == 'E' || map->map[i][j] == 'P' || map->map[i][j] == 'W')
				mlx_put_image_to_window(mlx, win, imgs->ground[c], j * 150, i * 150);
			j++;
		}
		i++;
	}
}
