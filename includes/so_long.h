/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:50:28 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/11 18:21:31 by abenzaho         ###   ########.fr       */
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
# include <mlx.h>
# include "../ft_get_next_line/get_next_line.h"
# include "../includes/so_long_args_check.h"
# include "../includes/helper_function.h"

typedef struct s_img
{
	void	**walls;
	void	*player;
	void	**ground;
	void	*enemy;
	void	*exit;
	void	*open;
}	t_img;

typedef struct s_game
{
	t_img	*imgs;
	t_map	*map;
}	t_game;

void	walls(int img_scale, void *mlx, t_img *imgs);
void	put_walls(void *mlx, void *win, t_map *map, t_img *imgs);

#endif
