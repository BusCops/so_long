/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:08:24 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/15 18:11:32 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	reset_all(t_game *game)
{
	game->walls.img.img = NULL;
	game->bg.img.img = NULL;
	game->ground.img.img = NULL;
	game->mlx = NULL;
	game->win = NULL;
}

void	free_all(t_game *game, int exit_stat)
{
	if(game->map.map)
		ft_free(game->map.map);
	if (game->ground.img.img)
		mlx_destroy_image(game->mlx, game->ground.img.img);
	if (game->walls.img.img)
		mlx_destroy_image(game->mlx, game->walls.img.img);
	if (game->bg.img.img)
		mlx_destroy_image(game->mlx, game->bg.img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit (exit_stat);
}