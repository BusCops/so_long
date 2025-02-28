/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_and_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:41:33 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/28 16:43:12 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	save_enemy_image(t_game *game)
{
	int	img_x;
	int	img_y;

	game->enemy.img.img = mlx_xpm_file_to_image
		(game->mlx, "texture/enemy/enemy.xpm", &img_x, &img_y);
	if (!game->enemy.img.img)
	{
		ft_putstr(2, RED "ERROR: enemy picture not working\n" RESET);
		free_all(game, 1);
	}
	game->enemy.img.addr = mlx_get_data_addr(game->enemy.img.img,
			&game->enemy.img.b_p, &game->enemy.img.len,
			&game->enemy.img.endian);
}

void	get_enemy(t_game *game)
{
	save_enemy_image(game);
	game->enemy.anim.img = mlx_new_image(game->mlx, 150, 150);
	game->enemy.anim.addr = mlx_get_data_addr(game->enemy.anim.img,
			&game->enemy.anim.b_p, &game->enemy.anim.len,
			&game->enemy.anim.endian);
}

void	put_enemy(t_game *game)
{
	t_index	in;

	in.i = 0;
	while (game->map.map[in.i])
	{
		in.j = 0;
		while (game->map.map[in.i][in.j])
		{
			if (game->map.map[in.i][in.j] == 'W')
			{
				draw_enemy(game, in.j, in.i);
				mlx_put_image_to_window(game->mlx, game->win,
					game->enemy.anim.img,
					150 * in.j, in.i * 150);
			}
			in.j++;
		}
		in.i++;
	}
}

void	draw_enemy(t_game *game, int x, int y)
{
	t_index			in;
	unsigned int	color;
	char			*pixel_bg;
	char			*pixel_en;

	in.i = 0;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{
			pixel_bg = get_pixel(game->bg.img, (150 * x)
					+ in.j, (y * 150) + in.i);
			pixel_en = get_pixel(game->enemy.anim, in.j, in.i);
			color = get_color(game->enemy.img, in.j, in.i);
			if (get_t(color))
				color = *(unsigned int *)pixel_bg;
			*(unsigned int *)pixel_en = color;
			in.j++;
		}
		in.i++;
	}
}

void	check_for_enemy(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'W')
	{
		ft_putstr(1, "You Lost !\n");
		free_all(game, 0);
	}
}
