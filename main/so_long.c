/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:48:45 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/13 18:25:08 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*void	turn_the_display_on(t_game *game, t_vars *mlxvar)
{
	mlxvar->win = mlx_new_window(mlxvar->mlx, ft_strlen(game->map->map[0]) * 150, ft_pointer_counter(game->map->map) * 150, "so_long");
}

void	put_walls_and_ground(t_game *game, t_vars *mlxvar)
{
	game->imgs = (t_img *)malloc(sizeof(t_img));
	save_imgs(150, game->imgs, mlxvar);
	start_puting_walls(game->map, game->imgs, mlxvar->mlx, mlxvar->win);
	start_puting_ground(game->map, game->imgs, mlxvar->mlx, mlxvar->win);
}

void	lets_build_the_thing(t_game *game, t_vars *mlxvar)
{
	turn_the_display_on(game, mlxvar);
	put_walls_and_ground(game, mlxvar);
}*/
 
void	lets_run_win_and_put_env(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map.col * 150, game->map.row * 150, "so_long");
	if (!game->win)
		win_error(game);
	save_walls_img(game);
	save_ground_img(game);
	//put_walls(game);
	
}

int	main(int ac, char **av)
{
	t_game	game;
	
	game.map = args_checker(ac, av);
	game.mlx = mlx_init();
	if (!game.mlx)
		mlx_error(&game);
	lets_run_win_and_put_env(&game);
	mlx_key_hook(game.win, key_event, &game);
	mlx_loop(game.mlx);
	return (0);
}
