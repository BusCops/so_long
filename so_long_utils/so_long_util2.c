/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:05:22 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/13 19:01:11 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_error_g(t_game *game)
{
	ft_putstr(2, RED "ERROR: Ground image failed! 🌍 Guess you’re floating in the void now... 🕳️" RESET);
	ft_free(game->map.map);
	mlx_destroy_image(game->mlx, game->walls.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(1);
}

int	key_event(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		ft_free(game->map.map);
		mlx_destroy_image(game->mlx, game->walls.img);
		mlx_destroy_image(game->mlx, game->ground.img);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
	return (0);
}

/*void	put_walls(char **map, void *mlx, int row, int col)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i])
		{
			if (map[i][j] == '1')
			{
				if ((!i && !j) || (!i && j == col) || (!j && i == row) || (j == col && i == row))
					mlx_put_image_to_window(mlx, win, imgs->walls[2], j * 150, i * 150);
				else	
					mlx_put_image_to_window(mlx, win, imgs->walls[k], j * 150, i * 150);
				break ;
			}
			j++;
		}
		i++;
	}
}
*/
/*void	free_all(t_game *game, t_vars *mlxvar)
{
	//if (mlxvar->mlx)
	//	free(mlxvar->mlx);
	//if (mlxvar->win)
	//	free(mlxvar->win);
	//free(mlxvar);
	//(void)game;
	(void)mlxvar;
	ft_free(game->map->map);
	//free(game->map);
	//ft_free_void(game->imgs->ground);
	//ft_free_void(game->imgs->walls);
	//free(game->imgs);
	//free(game);
}

int	key_event(int keycode, t_vars *mlxvar)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(mlxvar->mlx, mlxvar->win);
		free_all(mlxvar->game, mlxvar);
		exit(0);
	}
	return (0);
}

void	mlx_error(t_game *game, t_vars *mlxvar)
{
		ft_putstr(2, "Error: MLX failed! 🖥️ Did the X server take a nap? 😴\n");
		ft_free(game->map->map);
		free(game->map);
		free(mlxvar);
		exit(1);
}*/