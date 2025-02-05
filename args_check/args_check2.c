/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:02:25 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/04 15:12:58 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**fill_array(t_list **list)
{
	char	**str;
	t_list	*start;
	int		i;

	i = 0;
	start = *list;
	str = (char **)malloc(sizeof(char *) * (ft_lstsize(*list) + 1));
	if (!str)
		return (free_linked_list(list), NULL);
	while (*list)
	{
		str[i] = (*list)->str;
		*list = (*list)->next;
		i++;
	}
	str[i] = NULL;
	*list = start;
	free_linked_list(list);
	return (str);
}

char	**get_the_content_of_the_map(char **av)
{
	t_list	*map;
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	map = ft_lstnew(line);
	while (line)
	{
		line = get_next_line(fd);
		ft_lstadd_back(&map, ft_lstnew(line));
	}
	return (fill_array(&map));
}

void	number_of_exit_and_players(int e, int p, char **map)
{
	if (e == 0)
	{
		ft_putstr(2, "🚨 WHERE IS THE EXIT 🚪?!!\n");
		ft_putstr(2, "I guess I’ll just use the vent... 😩\n");
		ft_free(map);
		exit (1);
	}
	if (e > 1)
	{
		ft_putstr(2, "😱 I'm panicking! Which door should I choose...?\n");
		ft_free(map);
		exit (1);
	}
	if (p == 0)
	{
		ft_putstr(2, "Is it too much to ask for a living hero? 🤷\n");
		ft_free(map);
		exit (1);
	}
	if (p > 1)
	{
		ft_putstr(2, "❌ This is NOT a multiplayer game! ❌\n");
		ft_free(map);
		exit (1);
	}
}

void	check_invalid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
			{
				ft_putstr(2, "👽 What are those... ALIENS!? 👾\n");
				ft_putstr(2, "Invalid characters found! 😱\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_player_and_exit(int *c, int *e, int *p, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				(*p)++;
			if (map[i][j] == 'E')
				(*e)++;
			if (map[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
}
