/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:48:45 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/07 16:35:20 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	turn_the_display_on(void *mlx, t_map *map)
{
	void	*win;
	int		img_width = 64;
	int		img_height = 64;
	void	*img;

	win = mlx_new_window(mlx, ft_strlen(map->map[0]) * 64, ft_pointer_counter(map->map) * 64, "so_long");
	img = mlx_xpm_file_to_image(mlx, "texture/wall.xpm", &img_width, &img_height);
	if (!img)
		ft_putstr(2, "Error: Failed to load image!\n");
	mlx_put_image_to_window(mlx, win, img, 0 * 64, 0 * 64);

	mlx_loop(mlx);
}

void	lets_build_the_thing(void *mlx, t_map *map)
{
	turn_the_display_on(mlx, map);
}

int	main(int ac, char **av)
{
	void	*mlx;
	t_map	*map;
	
	map = args_checker(ac, av);
	mlx = mlx_init();
	if (!mlx)
	{
		ft_putstr(2, "Error: MLX failed! 🖥️ Did the X server take a nap? 😴\n");
		ft_free(map->map);
		free(map);
		return (1);
	}
	lets_build_the_thing(mlx, map);
	//win = mlx_new_window(mlx, 800, 600, "My Window");
	//mlx_loop(mlx);
	mlx_destroy_display(mlx);
	free(mlx);
	ft_free(map->map);
	free(map);
	return (0);	
}
