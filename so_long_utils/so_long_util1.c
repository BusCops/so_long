/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:49:41 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/11 21:13:41 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	walls(int img_scale, void *mlx, t_img *imgs)
{
	imgs->walls = (void **)malloc(sizeof(void *) * 2);
	imgs->ground = (void **)malloc(sizeof(void *) / 4);
	/*if (!imgs->walls)
	{
		printf("asdadas");
		exit(1);	
	}*/
	imgs->walls[0] = mlx_xpm_file_to_image(mlx, "texture/walls/wall_3.xpm", &img_scale, &img_scale);
	imgs->walls[1] = mlx_xpm_file_to_image(mlx, "texture/walls/wall_1.xpm", &img_scale, &img_scale);
	//imgs->walls[2] = mlx_xpm_file_to_image(mlx, "texture/walls/wall_3.xpm", &img_scale, &img_scale);
	//imgs->walls[3] = mlx_xpm_file_to_image(mlx, "texture/walls/wall_4.xpm", &img_scale, &img_scale);
	imgs->ground[0] = mlx_xpm_file_to_image(mlx, "texture/ground/ground1.xpm", &img_scale, &img_scale);
	imgs->ground[1] = mlx_xpm_file_to_image(mlx, "texture/ground/ground2.xpm", &img_scale, &img_scale);
	imgs->ground[2] = mlx_xpm_file_to_image(mlx, "texture/ground/ground3.xpm", &img_scale, &img_scale);
	//imgs->ground[3] = mlx_xpm_file_to_image(mlx, "texture/ground/ground4.xpm", &img_scale, &img_scale);

	if (!imgs->walls[0] || !imgs->walls[1])
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
	int	c;

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
				mlx_put_image_to_window(mlx, win, imgs->walls[k], j * 150, i * 150);
			else if (map->map[i][j] == '0' || map->map[i][j] == 'C' || map->map[i][j] == 'E' || map->map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, imgs->ground[c], j * 150, i * 150);
			j++;
		}
		i++;
	rand();
	}
}
