/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:05:22 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/12 17:34:15 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all(t_game *game, t_vars *mlxvar)
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

int	key_event(int keycode, t_vars *mlxvar, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(mlxvar->mlx, mlxvar->win);
		free_all(game, mlxvar);
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
}