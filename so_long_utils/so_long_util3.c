/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:08:24 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/25 16:04:33 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	reset_all(t_game *game)
{
	game->count = 0;
	game->walls.img.img = NULL;
	game->bg.img.img = NULL;
	game->ground.img.img = NULL;
	game->coin.cpos = NULL;
	game->coin.img.img = NULL;
	game->coin.anim.img = NULL;
	game->pl.anim.img = NULL;
	game->pl.img.img = NULL;
	game->exit.img.img = NULL;
	game->exit.anim.img = NULL;
	game->mlx = NULL;
	game->win = NULL;
}

void	free_all(t_game *game, int exit_stat)
{
	if (game->map.map)
		ft_free(game->map.map);
	if (game->ground.img.img)
		mlx_destroy_image(game->mlx, game->ground.img.img);
	if (game->walls.img.img)
		mlx_destroy_image(game->mlx, game->walls.img.img);
	if (game->bg.img.img)
		mlx_destroy_image(game->mlx, game->bg.img.img);
	if (game->coin.img.img)
		mlx_destroy_image(game->mlx, game->coin.img.img);
	if (game->coin.anim.img)
		mlx_destroy_image(game->mlx, game->coin.anim.img);
	if (game->coin.cpos)
		free_coin_positions(game);
	if (game->pl.img.img)
		mlx_destroy_image(game->mlx, game->pl.img.img);
	if (game->pl.anim.img)
		mlx_destroy_image(game->mlx, game->pl.anim.img);
	if (game->exit.img.img)
		mlx_destroy_image(game->mlx, game->exit.img.img);
	if (game->exit.anim.img)
		mlx_destroy_image(game->mlx, game->exit.anim.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit (exit_stat);
}

void free_coin_positions(t_game *game)
{
    int i;

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