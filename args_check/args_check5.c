/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:15:30 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/06 13:39:38 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ff_bfs(int x, int y, t_map *tmp)
{
	flood_fill_bfs(x + 1, y, tmp);
	flood_fill_bfs(x - 1, y, tmp);
	flood_fill_bfs(x, y + 1, tmp);
	flood_fill_bfs(x, y - 1, tmp);
}

void	flood_fill_bfs(int x, int y, t_map *tmp)
{
	if (tmp->map[x][y] == '1' || tmp->map[x][y] == 'V')
		return ;
	else if (tmp->map[x][y] == 'E')
	{
		tmp->e = 0;
		return ;
	}
	else if (tmp->map[x][y] == 'C')
	{
		tmp->map[x][y] = 'V';
		tmp->c--;
		ff_bfs(x, y, tmp);
		return ;
	}
	else
	{
		tmp->map[x][y] = 'V';
		ff_bfs(x, y, tmp);
	}
}

void	unreachable_error(char **tmp, char **map)
{
	ft_putstr(2, "\n       🚨🚨🚨 EMERGENCY!!! 🚨🚨🚨\n");
	ft_putstr(2, "========================================\n");
	ft_putstr(2, "   🔥 ERROR: I'M TRAPPED FOREVER! 🔥\n");
	ft_putstr(2, "========================================\n");
	ft_putstr(2, " 🧱 WALLS TOO HIGH, NO PARKOUR SKILLS!\n");
	ft_putstr(2, " 🔍 Searching for escape routes...\n");
	ft_putstr(2, " ❌ ERROR: NO LADDER, NO ROPE, NO HOPE.\n");
	ft_putstr(2, " ❌ ERROR: EXIT IS A GOVERNMENT LIE. 🏛️\n");
	ft_putstr(2, " ❌ ERROR: COLLECTIBLES? MORE LIKE BAIT.\n");
	ft_putstr(2, "========================================\n");
	ft_putstr(2, "            ⚠️ Possible Causes:\n");
	ft_putstr(2, "   - Dev has trust issues. 🤡\n");
	ft_putstr(2, "   - Map is cursed. 👹\n");
	ft_putstr(2, "   - I’m just bad at this. 🎮\n");
	ft_putstr(2, "========================================\n");
	ft_putstr(2, "            🛠️ Suggested Fixes:\n");
	ft_putstr(2, "   - Add a door. 🚪\n");
	ft_putstr(2, "   - Give me wings. 🕊️\n");
	ft_putstr(2, "   - Delete this nightmare. 🗑️\n");
	ft_putstr(2, "========================================\n");
	ft_putstr(2, "   🔄 RESTART? OR ACCEPT YOUR FATE. 😵\n");
	ft_putstr(2, "========================================\n");
	ft_free(tmp);
	ft_free(map);
	exit(1);
}
