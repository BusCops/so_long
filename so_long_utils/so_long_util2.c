/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:05:22 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/26 18:08:33 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_event(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_all(game, 0);
	if (keycode == 65363)
	{
		if (game->map.map[game->plp.y][game->plp.x + 1] != '1')
		{
			//write()  write the count number of moves
			move_player_right(game);
		}
	}
	if (keycode == 65361)
	{
		if (game->map.map[game->plp.y][game->plp.x - 1] != '1')
		{
			// game->count = game->count + 1;
			// ft_putstr(1, "moves ");
			// ft_putnbr_fd(1, game->count);
			// write(1, "\n", 1);
			move_player_left(game);
		}
	}
	if (keycode ==  65364)
	{
		if (game->map.map[game->plp.y + 1][game->plp.x] != '1')
		{
			//write
			move_player_down(game);
		}
	}
	if (keycode == 65362)
	{
		if (game->map.map[game->plp.y - 1][game->plp.x] != '1')
		{
			//writ
			move_player_up(game);
		}
	}
	return (0);
}

int key_press(int keycode, t_game *game)
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

int key_release(int keycode, t_game *game)
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

void	moves_counter(t_game *game)
{
	game->count = game->count + 1;
	ft_putstr(1, "moves ");
	ft_putnbr_fd(game->count, 1);
	write(1, "\n", 1);
}

int game_loop(t_game *game)
{
    if (game->moving[0] && game->map.map[game->plp.y][game->plp.x + 1] != '1')
        {
			finish_game(game, game->plp.x + 1, game->plp.y);
			moves_counter(game);
			move_player_right(game);
			game->plp.x = game->plp.x + 1;
		}
    else if (game->moving[1] && game->map.map[game->plp.y][game->plp.x - 1] != '1')
	{
		finish_game(game, game->plp.x - 1, game->plp.y);
		moves_counter(game);
	    move_player_left(game);
		game->plp.x -= 1;
	}
	else if (game->moving[2] && game->map.map[game->plp.y + 1][game->plp.x] != '1')
        {
			finish_game(game, game->plp.x, game->plp.y + 1);
			moves_counter(game);
			move_player_down(game);
			game->plp.y += 1;
		}
    else if (game->moving[3] && game->map.map[game->plp.y - 1][game->plp.x] != '1')
	{
		finish_game(game, game->plp.x, game->plp.y - 1);
        moves_counter(game);
		move_player_up(game);
		game->plp.y -= 1;
	}
	else
	{
		fill_coin(game);
		custom_usleep();
	}
	if (game->cc == 0)
	{
		draw_exit(game);
	}
	return (0);
}