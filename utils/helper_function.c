/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:21:51 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/03 16:04:35 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

t_list	*ft_lstnew(char *str)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->str = str;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	last = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	free_linked_list(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}