/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:37:31 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/27 15:43:59 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	save_player_image(t_game *game)
{
	int	img_x;
	int	img_y;

	game->pl.img.img = mlx_xpm_file_to_image
		(game->mlx, "texture/player/player.xpm", &img_x, &img_y);
	if (!game->pl.img.img)
	{
		ft_putstr(2, RED "Error: Player texture is missing! "
			"Did he rage quit? 🤔" RESET);
		free_all(game, 1);
	}
	game->pl.img.addr = mlx_get_data_addr(game->pl.img.img,
			&game->pl.img.b_p, &game->pl.img.len,
			&game->pl.img.endian);
}

void	get_and_put_player(t_game *game)
{
	save_player_image(game);
	game->pl.anim.img = mlx_new_image(game->mlx, 150, 150);
	game->pl.anim.addr = mlx_get_data_addr(game->pl.anim.img,
			&game->pl.anim.b_p, &game->pl.anim.len,
			&game->pl.anim.endian);
	game->plp.x = game->map.yp;
	game->plp.y = game->map.xp;
}

void	put_player(t_game *game, int frame)
{
	game->frame = frame;
	draw_player_moving(game, game->plp.x, game->plp.y, 0);
	mlx_put_image_to_window(game->mlx, game->win,
		game->pl.anim.img, game->plp.x * 150, game->plp.y * 150);
	custom_usleep();
}
