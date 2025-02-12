/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:48:45 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/12 14:48:11 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	turn_the_display_on(t_vars *mlxvar, t_game *game)
{
	game->imgs = (t_img *)malloc(sizeof(t_img));
	walls(150, mlxvar->mlx, game->imgs);
	mlxvar->win = mlx_new_window(mlxvar->mlx, ft_strlen(game->map->map[0]) * 150, ft_pointer_counter(game->map->map) * 150, "so_long");
	put_walls(mlxvar->mlx, mlxvar->win, game->map, game->imgs);
}

void	lets_build_the_thing(void *mlx, t_game *game)
{
	turn_the_display_on(mlx, game);
}
 
int	main(int ac, char **av)
{
	t_vars	*mlxvar;
	t_game	*game;
	t_map	*map;
	
	map = args_checker(ac, av);
	game = (t_game *)malloc(sizeof(t_game));
	game->map = map;
	mlxvar = (t_vars *)malloc(sizeof(t_vars));
	mlxvar->mlx = mlx_init();
	if (!mlxvar->mlx)
	{
		ft_putstr(2, "Error: MLX failed! 🖥️ Did the X server take a nap? 😴\n");
		ft_free(game->map->map);
		free(game->map);
		return (1);
	}
	lets_build_the_thing(mlxvar, game);
	mlx_key_hook(mlxvar->win, key_event, mlxvar);
	mlx_loop(mlxvar->mlx);
	return (0);	
}
