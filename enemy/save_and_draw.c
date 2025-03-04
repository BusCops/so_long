/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_and_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:41:33 by abenzaho          #+#    #+#             */
/*   Updated: 2025/03/04 13:16:26 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_bg_n(t_game *game, int x, int y)
{
	t_index			in;
	char			*pixel_bg;
	char			*pixel;

	in.i = 0;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{
			pixel_bg = get_pixel_in_bg(game->bg.img, x, y, in);
			pixel = get_pixel(game->bg.tmp, in.j, in.i);
			*(unsigned int *)pixel = *(unsigned int *)pixel_bg;
			in.j++;
		}
		in.i++;
	}
}

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
	enemy_count(game);
	allocate_en_pos(game);
	search_enemy_and_save(game, game->map.map);
	save_enemy_image(game);
	game->enemy.anim.img = mlx_new_image(game->mlx, 150, 150);
	game->enemy.anim.addr = mlx_get_data_addr(game->enemy.anim.img,
			&game->enemy.anim.b_p, &game->enemy.anim.len,
			&game->enemy.anim.endian);
}

void	move_en_right(t_game *game, int x, int y, int i)
{
	draw_bg_n(game, x, y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->bg.tmp.img, x * 150, y * 150);
	mlx_do_sync(game->mlx);
	draw_enemy(game, x + 1, y, 0);
	mlx_put_image_to_window(game->mlx, game->win,
		game->enemy.anim.img, (x + 1) * 150, y * 150);
	mlx_do_sync(game->mlx);
	game->enemy.enp[i]->x++;
}

void	move_en_left(t_game *game, int x, int y, int i)
{
	draw_bg_n(game, x, y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->bg.tmp.img, x * 150, y * 150);
	mlx_do_sync(game->mlx);
	draw_enemy(game, x - 1, y, 0);
	mlx_put_image_to_window(game->mlx, game->win,
		game->enemy.anim.img, (x - 1) * 150, y * 150);
	mlx_do_sync(game->mlx);
	game->enemy.enp[i]->x--;
}
