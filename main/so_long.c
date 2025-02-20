/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:48:45 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/20 17:39:32 by abenzaho         ###   ########.fr       */
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
	save_walls_img(game);
	save_ground_img(game);
	creat_image_and_fill(game);
	game->win = mlx_new_window(game->mlx, game->map.col * 150, game->map.row * 150, "so_long");
	if (!game->win)
	{
		ft_putstr(2, RED "ERROR: Window failed! 🪟 Guess I'll live in the terminal now... 🤡" RESET);
		free_all(game, 0);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->bg.img.img, 0, 0);
	get_and_put_coin(game);
	get_and_put_player(game);
	put_player(game, 0);
	//mlx_loop_hook(game->mlx, put_all, game);
}

int	main(int ac, char **av)
{
	t_game	game;
	
	game.map = args_checker(ac, av);
	reset_all(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_putstr(2, "Error: MLX failed! 🖥️ Did the X server take a nap? 😴\n");
		free_all(&game, 1);
	}
	lets_run_win_and_put_env(&game);
	game.moving[0] = game.moving[1] = game.moving[2] = game.moving[3] = 0;
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);    // Key press event
    mlx_hook(game.win, 3, 1L << 1, key_release, &game);  // Key release event
    mlx_loop_hook(game.mlx, game_loop, &game);          // Continuous update loop
	mlx_loop(game.mlx);
	return (0);
}
