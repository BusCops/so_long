/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:55:07 by abenzaho          #+#    #+#             */
/*   Updated: 2025/03/04 13:22:59 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_count(t_game *game)
{
	t_index	in;

	in.i = 0;
	while (game->map.map[in.i])
	{
		in.j = 0;
		while (game->map.map[in.i][in.j])
		{
			if (game->map.map[in.i][in.j] == 'W')
				game->enemy.e++;
			in.j++;
		}
		in.i++;
	}
}

void	allocate_en_pos(t_game *game)
{
	int	i;

	i = 0;
	game->enemy.enp = (t_enp **)malloc(sizeof(t_enp *) * game->enemy.e);
	if (!game->enemy.enp)
	{
		ft_putstr(2, "allocation fail");
		free_all(game, 1);
	}
	while (i < game->enemy.e)
	{
		game->enemy.enp[i] = (t_enp *)malloc(sizeof(t_enp));
		i++;
	}
}

void	search_enemy_and_save(t_game *game, char **map)
{
	t_index	in;
	int		e;

	in.i = 0;
	e = 0;
	while (map[in.i])
	{
		in.j = 0;
		while (map[in.i][in.j])
		{
			if (map[in.i][in.j] == 'W')
			{
				game->enemy.enp[e]->x = in.j;
				game->enemy.enp[e]->y = in.i;
				game->enemy.enp[e]->fr = 0;
				e++;
			}
			in.j++;
		}
		in.i++;
	}
}

void	check_for_enemy(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->enemy.e)
	{
		if (game->enemy.enp[i]->x == x && game->enemy.enp[i]->y == y)
		{
			ft_putstr(1, "You Lost !\n");
			free_all(game, 0);
		}
		i++;
	}
}

void	check_move(t_game *game, int x, int y, int i)
{
	if ((game->map.map[y][x + 1] == '1' || game->map.map[y][x + 1] == 'C'
		|| game->map.map[y][x + 1] == 'E') && (game->map.map[y][x - 1] == '1'
		|| game->map.map[y][x - 1] == 'C' || game->map.map[y][x - 1] == 'E'))
	{
		game->enemy.enp[i]->move = 2;
	}
	else if (game->map.map[y][x + 1] == '1'
		|| game->map.map[y][x + 1] == 'C' || game->map.map[y][x + 1] == 'E')
		game->enemy.enp[i]->move = 1;
	else if (game->map.map[y][x - 1] == '1' ||
		game->map.map[y][x - 1] == 'C' || game->map.map[y][x - 1] == 'E')
		game->enemy.enp[i]->move = 0;
}
