/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:50:28 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/05 15:20:32 by abenzaho         ###   ########.fr       */
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
# include "../ft_get_next_line/get_next_line.h"
# include "../includes/so_long_args_check.h"
# include "../includes/helper_function.h"

typedef struct s_map
{
	int		c;
	int		e;
	int		xp;
	int		yp;
	char	**map;
}	t_map;

#endif
