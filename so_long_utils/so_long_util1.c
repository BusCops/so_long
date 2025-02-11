/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:49:41 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/11 18:43:15 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	walls(int img_scale, void *mlx, t_img *imgs)
{
	imgs->walls = (void **)malloc(sizeof(void *) * 4);
	if (!imgs->walls)
	{
		printf("asdadas");
		exit(1);	
	}
	imgs->walls[0] = mlx_xpm_file_to_image(mlx, "texture/walls/wall_1.xpm", &img_scale, &img_scale);
	imgs->walls[1] = mlx_xpm_file_to_image(mlx, "texture/walls/wall_2.xpm", &img_scale, &img_scale);
	imgs->walls[2] = mlx_xpm_file_to_image(mlx, "texture/walls/wall_3.xpm", &img_scale, &img_scale);
	imgs->walls[3] = mlx_xpm_file_to_image(mlx, "texture/walls/wall_4.xpm", &img_scale, &img_scale);
	if (!imgs->walls[0] || !imgs->walls[1] || !imgs->walls[2] || !imgs->walls[3])
	{
		printf("error");
		exit(1);
		//handel the exit and the free
	}
}

void	put_walls(void *mlx, void *win,t_map *map, t_img *imgs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (map->map[i])
	{
		j = 0;
		while(map->map[i][j])
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, imgs->walls[k], j * 150, i * 150);
			j++;
			if (k == 3 && j % 2 == 0)
				k = 0;
			else if (j % 2 == 0 && k < 3)
				k++;
		}
		if (k != 3)
			k++;
		i++;
	}
}