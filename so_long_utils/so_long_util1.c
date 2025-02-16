/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:49:41 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/15 19:20:20 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	save_walls_img(t_game *game)
{
	int	img_x;
	int	img_y;
	
	img_x = 450;
	img_y = 150;
	game->walls.img.img = mlx_xpm_file_to_image(game->mlx, "texture/walls/walls.xpm", &img_x, &img_y);
	if (!game->walls.img.img)
	{
		ft_putstr(2, RED "ERROR: Wall image failed! 🚧 Now it's just invisible walls... good luck! 🫥" RESET);
		free_all(game, 1);
	}
	game->walls.img.addr = mlx_get_data_addr(game->walls.img.img, &game->walls.img.b_p, &game->walls.img.len,&game->walls.img.endian);
}

void	save_ground_img(t_game *game)
{
	int	img_x;
	int	img_y;
	
	img_x = 450;
	img_y = 150;
	game->ground.img.img = mlx_xpm_file_to_image(game->mlx, "texture/ground/ground.xpm", &img_x, &img_y);
	if (!game->ground.img.img)
	{
		ft_putstr(2, RED "ERROR: Ground image failed! 🌍 Guess you’re floating in the void now... 🕳️" RESET);
		free_all(game, 1);
	}
	game->ground.img.addr = mlx_get_data_addr(game->ground.img.img, &game->ground.img.b_p, &game->ground.img.len,&game->ground.img.endian);
}

void	creat_image_and_fill(t_game *game)
{
	game->bg.img.img = mlx_new_image(game->mlx, game->map.col * 150, game->map.row * 150);
	if (!game->bg.img.img)
	{
		ft_putstr(2, RED "Error: Error creating background image" RESET);
		free_all(game, 1);
	}
	game->bg.img.addr = mlx_get_data_addr(game->bg.img.img, &game->bg.img.b_p, &game->bg.img.len, &game->bg.img.endian);
	fill_image(game, game->map.map);
}

void	fill_image(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == '1')
				fill_with_wall(game, j, i, game->map);
			//else
				//fill_with_ground(game, i, j);
			j++;
		}
		i++;
	}
}

void	fill_with_wall(t_game *game, int x, int y, t_map map)
{
	int 			k;
	int				i;
	int				j;
	char			*pixel;
	unsigned int	color;
	
	i = 0;
	k = wich_wall(x, y, map.col - 1, map.row - 1);
	while (i < 150)
	{
		j = 0;
		while(j < 150)
		{
			//pixel = game->bg.img.addr + game->bg.img.len *(y *  150 + i)  + (x * (game->bg.img.b_p /8) * 150) + j * 4;
			//color = game->walls.img.addr + (game->walls.img.len * i) + (k * 150 * 4) + j * 4;
			//*(unsigned int *)pixel = *(unsigned int *)color;
			pixel = get_pixel_in_bg(game->bg.img, x, y, i) + (j * 4);
			color = get_color(game->walls.img, (k * 150) + j, i);
			*(unsigned int *)pixel = color;
			j++;
		}
		i++;
	}
}

char	*get_pixel_in_bg(t_img img, int x, int y, int nmv)
{
	char	*pixel;
	
	pixel = img.addr + (img.len * (y * 150 + nmv)) + (x * (img.b_p / 8) * 150);
	return (pixel);
}

unsigned int	get_color(t_img img, int x, int y)
{
	int	pixel;
	
	pixel = y * img.len + x * (img.b_p / 8);
	return(*(unsigned int *)(img.addr + pixel));
}

int	wich_wall(int x, int y, int col, int row)
{
	int	k;

	if((!y && !x) || (!y && x == col) || (!x && y == row) || (x == col && y == row))
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

/*void	fill_with_ground(t_game *game, int x, int y)
{
	
}*/

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