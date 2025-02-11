/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:07:42 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/11 19:04:04 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	remove_new_line(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		i++;
	}
}

void	wrong_shape(char **map)
{
	ft_putstr(2, "     🚨 ERROR: INVALID MAP SHAPE! 🚨\n");
	ft_putstr(2, "=========================================\n");
	ft_putstr(2, " 😵 This map is all over the place!\n");
	ft_putstr(2, " 🧩 Rows are uneven! Chaos reigns! 🌀\n");
	ft_putstr(2, " ❌ Please ensure the map is rectangular.\n");
	ft_putstr(2, "=========================================\n");
	ft_putstr(2, " 💡 All rows must be the same width.\n");
	ft_putstr(2, " 💡 Try again with a properly shaped map.\n");
	ft_putstr(2, "=========================================\n");
	ft_free(map);
	exit(1);
}

void	check_shape(char **map)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != size)
			wrong_shape(map);
		i++;
	}
	if (size < i)
		wrong_shape(map);
	if (i < 4)
	{
		wrong_shape(map);
	}
}

void	check_character(char **map)
{
	int	e;
	int	p;
	int	c;

	e = 0;
	p = 0;
	c = 0;
	check_invalid_characters(map);
	check_player_and_exit(&c, &e, &p, map);
	number_of_exit_and_players(e, p, map);
	number_of_collectibles(c, map);
}

char	**check_map_valid_shape_and_content(char **av)
{
	char	**map;

	map = get_the_content_of_the_map(av);
	if (!map)
		exit(1);
	remove_new_line(map);
	check_character(map);
	check_shape(map);
	check_walls(map);
	check_if_the_exit_collectibles_reachable(map);
	if (!map)
	{
		ft_putstr(2, "Error : Allocation fail\n");
		exit(1);
	}
	return (map);
}
