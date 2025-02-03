/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:02:25 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/03 17:20:00 by abenzaho         ###   ########.fr       */
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
	str = (char **)malloc(sizeof(char *) * ft_lstsize(*list) + 1);
	if (!str)
		return (NULL);
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

void	check_map_valid_chape_and_content(char **av)
{
	char	**map;

	map = get_the_content_of_the_map(av);
	ft_free(map);
}
