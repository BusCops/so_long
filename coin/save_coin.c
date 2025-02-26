/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_coin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:18:03 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/26 17:30:02 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	allocate_coin_pos(t_game *game)
{
	int	i;

	i = 0;
	game->coin.cpos = (t_cpos **)malloc(sizeof(t_cpos *) * game->map.c);
	if (!game->coin.cpos)
	{
		ft_putstr(2, "allocation fail");
		free_all(game, 1);
	}
	while (i < game->map.c)
	{
		game->coin.cpos[i] = (t_cpos *)malloc(sizeof(t_cpos));
		i++;
	}
}

void	search_coin_and_save(t_game *game, char **map)
{
	t_index	in;
	int		c;

	in.i = 0;
	c = 0;
	while (map[in.i])
	{
		in.j = 0;
		while (map[in.i][in.j])
		{
			if (map[in.i][in.j] == 'C')
			{
				game->coin.cpos[c]->x = in.j;
				game->coin.cpos[c]->y = in.i;
				game->coin.cpos[c]->exist = 1;
				c++;
			}
			in.j++;
		}
		in.i++;
	}
}

void	save_coin_image(t_game *game)
{
	int	img_x;
	int	img_y;

	img_x = 450;
	img_y = 150;
	game->coin.img.img = mlx_xpm_file_to_image
		(game->mlx, "texture/coin/coin.xpm", &img_x, &img_y);
	if (!game->coin.img.img)
	{
		ft_putstr(2, RED "ERROR: Diamond image failed! 💎 No "
			"diamonds, no glory... just disappointment. 😢\n" RESET);
		free_all(game, 1);
	}
	game->coin.img.addr = mlx_get_data_addr(game->coin.img.img,
			&game->coin.img.b_p, &game->coin.img.len,
			&game->coin.img.endian);
}

void	get_and_put_coin(t_game *game)
{
	save_coin_image(game);
	game->coin.anim.img = mlx_new_image(game->mlx, 150, 150);
	game->coin.anim.addr = mlx_get_data_addr(game->coin.anim.img,
			&game->coin.anim.b_p, &game->coin.anim.len,
			&game->coin.anim.endian);
	allocate_coin_pos(game);
	search_coin_and_save(game, game->map.map);
	game->cc = game->map.c;
}
