/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:50:28 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/18 16:45:02 by abenzaho         ###   ########.fr       */
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

typedef struct s_cpos
{
	int	x;
	int	y;
	int	exist;
}	t_cpos;

typedef struct s_index
{
	int	i;
	int	j;
}	t_index;


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		b_p;
	int		len;
	int		endian;
}	t_img;

typedef struct	s_walls
{
	t_img img;
}	t_walls;	

typedef struct	s_ground
{
	t_img img;
}	t_ground;

typedef struct s_background
{
	t_img img;
}	t_background;

typedef struct s_coin
{
	t_img	img;
	t_img	anim;
	t_cpos	**cpos;
}	t_coin;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_walls			walls;
	t_ground		ground;
	t_coin			coin;
	t_background	bg;
	t_map			map;
}	t_game;

void			reset_all(t_game *game);
void			free_all(t_game *game, int exit_stat);
void			lets_run_win_and_put_env(t_game *game);
void			save_walls_img(t_game *game);
void			save_ground_img(t_game *game);
int				key_event(int keycode, t_game *game);
void			creat_image_and_fill(t_game *game);
void			fill_image(t_game *game, char **map);
void			fill_with_wall(t_game *game, int x, int y, t_map map);
unsigned int	get_color(t_img img, int x, int y);
int				wich_wall(int x, int y, int col, int row);
char			*get_pixel_in_bg(t_img img, int x, int y, t_index in);
void			fill_with_ground(t_game *game, int x, int y, int c);
void			save_coin_image(t_game *game);
void			get_and_put_coin(t_game *game);
void			put_coin(t_game *game, char **map);
void 			free_coin_positions(t_game *game);
char			*get_pixel_from_image(t_img img, int x, int y);
// void	save_imgs(int img_scale, t_img *imgs, t_vars *mlx);
// void	start_puting_walls(t_map *map, t_img *imgs, void *mlx, void *win);
// void	start_puting_ground(t_map *map, t_img *imgs, void *mlx, void *win);
// int		key_event(int keycode, t_vars *mlxvar);
// void	mlx_error(t_game *game, t_vars *mlxvar);

#endif
