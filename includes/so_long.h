/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:50:28 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/13 18:08:38 by abenzaho         ###   ########.fr       */
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

/*typedef struct t_img
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
	void	*walls;
	void	*player;
	void	*ground;
	void	*enemy;
	void	*exit;
	void	*open;
}	t_game;
*/

typedef struct	s_walls
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_walls;	

typedef struct	s_ground
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_ground;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_walls		walls;
	t_ground	ground;
	t_map		map;
}	t_game;

void	mlx_error(t_game *game);
void	win_error(t_game *game);
void	img_error_w(t_game *game);
void	img_error_g(t_game *game);
void	lets_run_win_and_put_env(t_game *game);
void	save_walls_img(t_game *game);
void	save_ground_img(t_game *game);
int		key_event(int keycode, t_game *game);
// void	save_imgs(int img_scale, t_img *imgs, t_vars *mlx);
// void	start_puting_walls(t_map *map, t_img *imgs, void *mlx, void *win);
// void	start_puting_ground(t_map *map, t_img *imgs, void *mlx, void *win);
// int		key_event(int keycode, t_vars *mlxvar);
// void	mlx_error(t_game *game, t_vars *mlxvar);

#endif
