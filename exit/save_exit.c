/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:49:54 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/28 16:38:52 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	save_exit_image(t_game *game)
{
	int	img_x;
	int	img_y;

	game->exit.img.img = mlx_xpm_file_to_image
		(game->mlx, "texture/exit/exit.xpm", &img_x, &img_y);
	if (!game->exit.img.img)
	{
		ft_putstr(2, RED "ERROR: Well, the exit just decided "
			"to disappear. 😢\n" RESET);
		free_all(game, 1);
	}
	game->exit.img.addr = mlx_get_data_addr(game->exit.img.img,
			&game->exit.img.b_p, &game->exit.img.len,
			&game->exit.img.endian);
}

void	get_exit(t_game *game)
{
	save_exit_image(game);
	find_exit(game, game->map.map);
	game->exit.anim.img = mlx_new_image(game->mlx, 150, 150);
	game->exit.anim.addr = mlx_get_data_addr(game->exit.anim.img,
			&game->exit.anim.b_p, &game->exit.anim.len,
			&game->exit.anim.endian);
}

void	find_exit(t_game *game, char **map)
{
	t_index	in;

	in.i = 0;
	while (map[in.i])
	{
		in.j = 0;
		while (map[in.i][in.j])
		{
			if (map[in.i][in.j] == 'E')
			{
				game->exit.x = in.j;
				game->exit.y = in.i;
			}
			in.j++;
		}
		in.i++;
	}
}
