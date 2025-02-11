/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:48:45 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/11 18:58:50 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	turn_the_display_on(void *mlx, t_game *game)
{
	void	*win;
	//int		img_width = 150;
	//int		img_height = 150;
	//void	*img;
	game->imgs = (t_img *)malloc(sizeof(t_img));
	walls(150, mlx, game->imgs);
///////////////////////////////////////
	win = mlx_new_window(mlx, ft_strlen(game->map->map[0]) * 150, ft_pointer_counter(game->map->map) * 150, "so_long");
	//img = mlx_xpm_file_to_image(mlx, "texture/walls/wall_1.xpm", &img_width, &img_height);
	//if (!img)
	//	ft_putstr(2, "Error: Failed to load image!\n");
	put_walls(mlx, win,game->map, game->imgs);
	//mlx_put_image_to_window(mlx, win, img, 0 * 64, 0 * 64);
	mlx_loop(mlx);
}

void	lets_build_the_thing(void *mlx, t_game *game)
{
	turn_the_display_on(mlx, game);
}

int	main(int ac, char **av)
{
	void	*mlx;
	t_game	*game;
	t_map	*map;
	
	//game = (t_game *)malloc(sizeof(t_game));
	map = args_checker(ac, av);
	game = (t_game *)malloc(sizeof(t_game));
	game->map = map;
	mlx = mlx_init();
	if (!mlx)
	{
		ft_putstr(2, "Error: MLX failed! 🖥️ Did the X server take a nap? 😴\n");
		ft_free(game->map->map);
		free(game->map);
		return (1);
	}
	lets_build_the_thing(mlx, game);
	//win = mlx_new_window(mlx, 800, 600, "My Window");
	//mlx_loop(mlx);
	mlx_destroy_display(mlx);
	free(mlx);
	ft_free(game->map->map);
	free(game->map);
	return (0);	
}
