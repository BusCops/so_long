/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:05:22 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/28 16:23:31 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		free_all(game, 0);
	if (keycode == KEY_RIGHT)
		game->moving[0] = 1;
	if (keycode == KEY_LEFT)
		game->moving[1] = 1;
	if (keycode == KEY_DOWN)
		game->moving[2] = 1;
	if (keycode == KEY_UP)
		game->moving[3] = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_RIGHT)
		game->moving[0] = 0;
	if (keycode == KEY_LEFT)
		game->moving[1] = 0;
	if (keycode == KEY_DOWN)
		game->moving[2] = 0;
	if (keycode == KEY_UP)
		game->moving[3] = 0;
	return (0);
}

void	right_left(t_game *game)
{
	if (game->moving[0] && game->map.map[game->plp.y][game->plp.x + 1] != '1')
	{
		check_for_enemy(game, game->plp.x + 1, game->plp.y);
		finish_game(game, game->plp.x + 1, game->plp.y);
		moves_counter(game);
		move_player_right(game);
		game->plp.x = game->plp.x + 1;
	}
	else if (game->moving[1]
		&& game->map.map[game->plp.y][game->plp.x - 1] != '1')
	{
		check_for_enemy(game, game->plp.x - 1, game->plp.y);
		finish_game(game, game->plp.x - 1, game->plp.y);
		moves_counter(game);
		move_player_left(game);
		game->plp.x -= 1;
	}
}

void	up_down(t_game *game)
{
	if (game->moving[2] && game->map.map[game->plp.y + 1][game->plp.x] != '1')
	{
		check_for_enemy(game, game->plp.x, game->plp.y + 1);
		finish_game(game, game->plp.x, game->plp.y + 1);
		moves_counter(game);
		move_player_down(game);
		game->plp.y += 1;
	}
	else if (game->moving[3]
		&& game->map.map[game->plp.y - 1][game->plp.x] != '1')
	{
		check_for_enemy(game, game->plp.x, game->plp.y - 1);
		finish_game(game, game->plp.x, game->plp.y - 1);
		moves_counter(game);
		move_player_up(game);
		game->plp.y -= 1;
	}
}

int	game_loop(t_game *game)
{
	if ((game->moving[0] && game->map.map[game->plp.y][game->plp.x + 1] != '1')
		|| (game->moving[1]
		&& game->map.map[game->plp.y][game->plp.x - 1] != '1'))
		right_left(game);
	else if ((game->moving[2]
			&& game->map.map[game->plp.y + 1][game->plp.x] != '1')
		|| (game->moving[3]
		&& game->map.map[game->plp.y - 1][game->plp.x] != '1'))
		up_down(game);
	else
	{
		fill_coin(game);
		custom_usleep();
	}
	if (game->cc == 0)
		draw_exit(game);
	return (0);
}
