/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_args_check.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:11:21 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/07 16:38:08 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_ARGS_CHECK_H
# define SO_LONG_ARGS_CHECK_H

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*path;
	void	*enemy;
	void	*exit;
	void	*open;
}	t_img;

typedef struct s_map
{
	int		c;
	int		e;
	int		xp;
	int		yp;
	char	**map;
}	t_map;

void	check_args_number1(int ac);
void	check_args_number2(int ac);
void	check_if_valid_extension(char **av);
t_map	*args_checker(int ac, char **av);
char	**check_map_valid_shape_and_content(char **av);
void	check_character(char **map);
void	check_player_and_exit(int *c, int *e, int *p, char **map);
void	check_invalid_characters(char **map);
void	number_of_exit_and_players(int e, int p, char **map);
char	**get_the_content_of_the_map(char **av);
char	**fill_array(t_list **list);
void	remove_new_line(char **map);
void	number_of_collectibles(int c, char **map);
void	check_shape(char **map);
void	wrong_shape(char **map);
void	check_walls(char **map);
void	wrong_walls(char **map);
void	check_if_the_exit_collectibles_reachable(char **map);
void	flood_fill_bfs(int x, int y, t_map *tmp);
void	ff_bfs(int x, int y, t_map *tmp);
void	calculate_c_and_e(t_map *map);
void	unreachable_error(char **tmp, char **map);

#endif
