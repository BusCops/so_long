/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:51:13 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/04 14:34:10 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	number_of_collectibles(int c, char **map)
{
	if (c == 0)
	{
		ft_putstr(2, " 🍪 ERROR: WHERE ARE THE COLLECTIBLES?! 🍪\n");
		ft_putstr(2, "===========================================\n");
		ft_putstr(2, " 😱 Oh no! There's nothing to collect!\n");
		ft_putstr(2, "              🔍 Searching...\n");
		ft_putstr(2, " ❌ Nope, no snacks found. 😭\n");
		ft_putstr(2, " ❌ How am I supposed to win?\n");
		ft_putstr(2, " 📜 Rule #1: A hero needs loot!\n");
		ft_putstr(2, "===========================================\n");
		ft_putstr(2, " 💡 Add some collectibles to the map!\n");
		ft_putstr(2, "===========================================\n");
		ft_free(map);
		exit(1);
	}
}

void	wrong_walls(char **map)
{
	ft_putstr(2, "       🚨 ERROR: MAP NOT ENCLOSED! 🚨\n");
	ft_putstr(2, "=============================================\n");
	ft_putstr(2, " 🧱 The walls have crumbled! 😱\n");
	ft_putstr(2, " ❌ Gaps detected! Monsters might invade! 👾\n");
	ft_putstr(2, " 🛠️ Please build a proper fortress!\n");
	ft_putstr(2, "=============================================\n");
	ft_putstr(2, " 💡 The entire map must be enclosed by walls.\n");
	ft_putstr(2, " 💡 No missing corners, no sneaky holes!\n");
	ft_putstr(2, "=============================================\n");
	ft_free(map);
	exit(1);
}

void	check_walls(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[ft_pointer_counter(map) - 1][i] != '1')
			wrong_walls(map);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			wrong_walls(map);
		i++;
	}
}
