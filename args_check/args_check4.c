/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:51:13 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/05 15:21:00 by abenzaho         ###   ########.fr       */
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

void	calculate_c_and_e(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->c = 0;
	map->e = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->xp = i;
				map->yp = j;
			}
			if (map->map[i][j] == 'E')
				map->e++;
			if (map->map[i][j] == 'C')
				map->c++;
			j++;
		}
		i++;
	}
}

void	check_if_the_exit_collectibles_reachable(char **map)
{
	char	**tmp;
	t_map	tmp1;

	tmp = copy_double_pointer_array(map);
	if (!tmp)
		return (ft_free(map));
	tmp1.map = tmp;
	calculate_c_and_e(&tmp1);
	flood_fill_bfs(tmp1.xp, tmp1.yp, &tmp1);
	if (tmp1.e != 0 || tmp1.c != 0)
		unreachable_error(tmp, map);
	ft_free(tmp);
}
