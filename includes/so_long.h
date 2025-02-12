/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:50:28 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/12 17:21:41 by abenzaho         ###   ########.fr       */
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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

void	save_imgs(int img_scale, t_img *imgs, void *mlx);
void	start_puting_walls(t_map *map, t_img *imgs, void *mlx, void *win);
void	start_puting_ground(t_map *map, t_img *imgs, void *mlx, void *win);
int		key_event(int keycode, t_vars *mlxvar, t_game *game);
void	mlx_error(t_game *game, t_vars *mlxvar);

#endif
