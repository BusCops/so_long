/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:50:28 by abenzaho          #+#    #+#             */
/*   Updated: 2025/03/04 13:24:53 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"
# define KEY_ESC 65307
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_UP 65362
# define SPEED 40000000

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <mlx.h>
# include "../ft_get_next_line/get_next_line.h"
# include "../includes/so_long_args_check.h"
# include "../includes/helper_function.h"

typedef struct s_cpos
{
	int	x;
	int	y;
	int	exist;
}	t_cpos;

typedef struct s_enp
{
	int	x;
	int	y;
	int	y_n;
	int	x_n;
	int	move;
	int	fr;
}	t_enp;

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

typedef struct s_walls
{
	t_img	img;
}	t_walls;	

typedef struct s_ground
{
	t_img	img;
}	t_ground;

typedef struct s_background
{
	t_img	img;
	t_img	tmp;
}	t_background;

typedef struct s_coin
{
	t_img	img;
	t_img	anim;
	t_cpos	**cpos;
}	t_coin;

typedef struct s_player
{
	t_img	img;
	t_img	anim;
}	t_player;

typedef struct s_enemy
{
	t_img	img;
	t_img	anim;
	t_enp	**enp;
	int		e;
	int		t;
	int		fr;

}	t_enemy;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_exit
{
	t_img	img;
	t_img	anim;
	int		frame;
	int		x;
	int		y;
}	t_exit;

typedef struct s_counter
{
	t_img	img;
	t_img	tmp;
}	t_counter;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_walls			walls;
	t_ground		ground;
	t_coin			coin;
	t_player		pl;
	t_enemy			en;
	t_background	bg;
	t_enemy			enemy;
	t_map			map;
	t_counter		counter;
	int				moving[4];
	int				count;
	t_pos			plp;
	int				frame;
	int				cc;
	t_exit			exit;
	int				finish;
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
void			free_coin_positions(t_game *game);
char			*get_pixel_from_image(t_img img, int x, int y);
int				fill_coin(t_game *game);
int				put_all(t_game *game);
void			get_and_put_player(t_game *game);
void			move_player_right(t_game *game);
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				game_loop(t_game *game);
int				update_game(int keycode, t_game *game);

//////////////TOOLS/////////////

void			custom_usleep(void);
int				get_t(int trgb);
char			*get_pixel(t_img img, int x, int y);

//////////////COUNTER////////////

void			save_counter(t_game *game);
void			put_counter(t_game *game);
void			moves_counter(t_game *game);
void			draw_counter(t_game *game, int frame);

//////////////ENEMY/////////////

void			enemy_count(t_game *game);
void			allocate_en_pos(t_game *game);
void			search_enemy_and_save(t_game *game, char **map);
void			save_enemy_image(t_game *game);
void			get_enemy(t_game *game);
void			draw_enemy(t_game *game, int x, int y, int p);
void			put_enemy(t_game *game);
void			check_for_enemy(t_game *game, int x, int y);
void			move_enemy(t_game *game);
void			move_en_right(t_game *game, int x, int y, int i);
void			move_en_left(t_game *game, int x, int y, int i);
void			check_move(t_game *game, int x, int y, int i);
void			draw_animation_en(t_game *game, int i);
void			free_enemy_positions(t_game *game);

//////////////UTILS/////////////
void			free_coin_positions(t_game *game);
void			reset_all(t_game *game);
//////////////WALLS//////////////

void			save_walls_img(t_game *game);
void			save_ground_img(t_game *game);
void			creat_image_and_fill(t_game *game);
void			fill_image(t_game *game, char **map);
int				wich_wall(int x, int y, int col, int row);
void			fill_with_wall(t_game *game, int x, int y, t_map map);
void			fill_with_ground(t_game *game, int x, int y, int c);
void			draw_bg(t_game *game, int pos);

//////////////COIN//////////////

void			save_coin_image(t_game *game);
void			get_and_put_coin(t_game *game);
void			allocate_coin_pos(t_game *game);
void			search_coin_and_save(t_game *game, char **map);
void			draw_coin_image(t_game *game, int k, int pos);
int				fill_coin(t_game *game);
void			coin_founded(t_game *game, int x, int y);

//////////////PLAYER//////////////

void			save_player_image(t_game *game);
void			get_and_put_player(t_game *game);
void			draw_player_moving(t_game *game, int x, int y, int p);
void			put_player(t_game *game, int frame);
void			move_player_left(t_game *game);
void			move_player_down(t_game *game);
void			move_player_up(t_game *game);
void			move_player_right(t_game *game);

//////////////EXIT//////////////

void			save_exit_image(t_game *game);
void			get_exit(t_game *game);
void			find_exit(t_game *game, char **map);
void			draw_exit_helper(t_game *game, int x, int y);
void			draw_exit(t_game *game);
void			finish_game(t_game *game, int x, int y);

#endif
