/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:08:24 by abenzaho          #+#    #+#             */
/*   Updated: 2025/03/04 13:26:22 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	reset_all(t_game *game)
{
	game->enemy.e = 0;
	game->enemy.t = 0;
	game->enemy.fr = 0;
	game->moving[0] = 0;
	game->moving[1] = 0;
	game->moving[2] = 0;
	game->moving[3] = 0;
	game->walls.img.img = NULL;
	game->bg.img.img = NULL;
	game->bg.tmp.img = NULL;
	game->ground.img.img = NULL;
	game->coin.cpos = NULL;
	game->coin.img.img = NULL;
	game->coin.anim.img = NULL;
	game->pl.anim.img = NULL;
	game->pl.img.img = NULL;
	game->exit.img.img = NULL;
	game->exit.anim.img = NULL;
	game->counter.img.img = NULL ;
	game->counter.tmp.img = NULL ;
	game->enemy.img.img = NULL;
	game->enemy.enp = NULL;
	game->enemy.anim.img = NULL;
	game->mlx = NULL;
	game->win = NULL;
}

void	free_all(t_game *game, int exit_stat)
{
	ft_free(game->map.map);
	mlx_destroy_image(game->mlx, game->ground.img.img);
	mlx_destroy_image(game->mlx, game->walls.img.img);
	mlx_destroy_image(game->mlx, game->bg.img.img);
	mlx_destroy_image(game->mlx, game->coin.img.img);
	mlx_destroy_image(game->mlx, game->coin.anim.img);
	mlx_destroy_image(game->mlx, game->counter.tmp.img);
	mlx_destroy_image(game->mlx, game->counter.img.img);
	mlx_destroy_image(game->mlx, game->enemy.anim.img);
	mlx_destroy_image(game->mlx, game->enemy.img.img);
	mlx_destroy_image(game->mlx, game->bg.tmp.img);
	free_coin_positions(game);
	free_enemy_positions(game);
	mlx_destroy_image(game->mlx, game->pl.img.img);
	mlx_destroy_image(game->mlx, game->pl.anim.img);
	mlx_destroy_image(game->mlx, game->exit.img.img);
	mlx_destroy_image(game->mlx, game->exit.anim.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (exit_stat);
}

void	free_coin_positions(t_game *game)
{
	int	i;

	i = 0;
	if (game->coin.cpos)
	{
		while (i < game->map.c)
		{
			if (game->coin.cpos[i])
			{
				free(game->coin.cpos[i]);
				game->coin.cpos[i] = NULL;
			}
			i++;
		}
		free(game->coin.cpos);
		game->coin.cpos = NULL;
	}
}

void	free_enemy_positions(t_game *game)
{
	int	i;

	i = 0;
	if (game->enemy.enp)
	{
		while (i < game->enemy.e)
		{
			if (game->enemy.enp[i])
			{
				free(game->enemy.enp[i]);
				game->enemy.enp[i] = NULL;
			}
			i++;
		}
		free(game->enemy.enp);
		game->enemy.enp = NULL;
	}
}
