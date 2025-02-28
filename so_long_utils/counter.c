/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:58:38 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/28 16:45:23 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	save_counter(t_game *game)
{
	int	img_x;
	int	img_y;

	game->counter.img.img = mlx_xpm_file_to_image
		(game->mlx, "texture/counter/counter.xpm", &img_x, &img_y);
	if (!game->counter.img.img)
	{
		ft_putstr(2, RED "Error: counter image not found !\n" RESET);
		free_all(game, 1);
	}
	game->counter.img.addr = mlx_get_data_addr(game->counter.img.img,
			&game->counter.img.b_p, &game->counter.img.len,
			&game->counter.img.endian);
	game->counter.tmp.img = mlx_new_image(game->mlx, 30, 30);
	game->counter.tmp.addr = mlx_get_data_addr(game->counter.tmp.img,
			&game->counter.tmp.b_p, &game->counter.tmp.len,
			&game->counter.tmp.endian);
}

void	draw_counter(t_game *game, int frame)
{
	t_index			in;
	char			*pixel;
	unsigned int	color;

	in.i = 0;
	while (in.i < 30)
	{
		in.j = 0;
		while (in.j < 30)
		{
			pixel = get_pixel(game->counter.tmp, in.j, in.i);
			color = get_color(game->counter.img, in.j + (frame * 30), in.i);
			in.j++;
			*(unsigned int *)pixel = color;
		}
		in.i++;
	}
}

void	put_counter(t_game *game)
{
	draw_counter(game, game->count % 10);
	mlx_put_image_to_window(game->mlx, game->win, game->counter.tmp.img,
		((game->map.col - 1) * 150) + 120, (game->map.row - 1) * 150 + 120);
	mlx_do_sync(game->mlx);
	draw_counter(game, game->count / 10);
	mlx_put_image_to_window(game->mlx, game->win, game->counter.tmp.img,
		((game->map.col - 1) * 150) + 90, (game->map.row - 1) * 150 + 120);
	mlx_do_sync(game->mlx);
	draw_counter(game, game->count / 100);
	mlx_put_image_to_window(game->mlx, game->win, game->counter.tmp.img,
		((game->map.col - 1) * 150) + 60, (game->map.row - 1) * 150 + 120);
	mlx_do_sync(game->mlx);
}

void	moves_counter(t_game *game)
{
	game->count = game->count + 1;
	put_counter(game);
	ft_putstr(1, "moves ");
	ft_putnbr_fd(game->count, 1);
	write(1, "\n", 1);
}
