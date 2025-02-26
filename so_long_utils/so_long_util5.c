/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:58:38 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/26 18:06:12 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	custom_usleep()
{
	int	i;

	i = 0;
	while(i < SPEED)
		i++;
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

void	finish_game(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'E' && game->finish == 1)
		free_all(game, 0);
}
