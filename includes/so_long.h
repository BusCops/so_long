/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:50:28 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/03 17:19:44 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include "../get_next_line/get_next_line.h"

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

//helper function

void	ft_putstr(int fd, char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_free(char **str);
t_list	*ft_lstnew(char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	free_linked_list(t_list **lst);

//args checkers

void	args_checker(int ac, char **av);
void	check_map_valid_chape_and_content(char **av);

#endif
