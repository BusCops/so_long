/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:17:49 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/04 14:27:25 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_FUNCTION_H
# define HELPER_FUNCTION_H

# include "../includes/so_long_args_check.h"

void	ft_putstr(int fd, char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_free(char **str);
t_list	*ft_lstnew(char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	free_linked_list(t_list **lst);
int		ft_pointer_counter(char **str);

#endif