/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:48:45 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/12 17:37:34 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	turn_the_display_on(t_game *game, t_vars *mlxvar)
{
	mlxvar->win = mlx_new_window(mlxvar->mlx, ft_strlen(game->map->map[0]) * 150, ft_pointer_counter(game->map->map) * 150, "so_long");
}

void	put_walls_and_ground(t_game *game, t_vars *mlxvar)
{
	game->imgs = (t_img *)malloc(sizeof(t_img));
	save_imgs(150, game->imgs, mlxvar->mlx);
	start_puting_walls(game->map, game->imgs, mlxvar->mlx, mlxvar->win);
	start_puting_ground(game->map, game->imgs, mlxvar->mlx, mlxvar->win);
}

void	lets_build_the_thing(t_game *game, t_vars *mlxvar)
{
	turn_the_display_on(game, mlxvar);
	put_walls_and_ground(game, mlxvar);
}
 
int	main(int ac, char **av)
{
	t_vars	*mlxvar;
	t_game	*game;
	t_map	*map;
	
	map = args_checker(ac, av);
	game = (t_game *)malloc(sizeof(t_game));
	mlxvar = (t_vars *)malloc(sizeof(t_vars));
	game->map = map;
	mlxvar->mlx = mlx_init();
	if (!mlxvar->mlx)
		mlx_error(game, mlxvar);
	lets_build_the_thing(game, mlxvar);
	mlx_key_hook(mlxvar->win, key_event, mlxvar);
	mlx_loop(mlxvar->mlx);
	return (0);
}
