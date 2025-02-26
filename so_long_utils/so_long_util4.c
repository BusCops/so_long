/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:45:45 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/25 15:45:20 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_pixel_in_bg(t_img img, int x, int y, t_index in)
{
	char	*pixel;

	pixel = img.addr + (img.len * (y * 150 + in.i))
		+ (x * (img.b_p / 8) * 150) + (in.j * 4);
	return (pixel);
}

unsigned int	get_color(t_img img, int x, int y)
{
	int	pixel;

	pixel = y * img.len + x * (img.b_p / 8);
	return (*(unsigned int *)(img.addr + pixel));
}

char	*get_pixel_from_image(t_img img, int x, int y)
{
	char	*pixel;

	pixel = img.addr + (img.len * y) + (x * (img.b_p / 8));
	return (pixel);
}

char	*get_pixel_in_bg_offset(t_img img, int x, int y, t_index in, int ofs)
{
	char	*pixel;

	pixel = img.addr + (img.len * (y * 150 + in.i))
		+ (x * (img.b_p / 8) * 150) + (in.j * 4) + ofs * 4;
	return (pixel);
}

char	*get_pixel_in_bg_offset_u(t_img img, int x, int y, t_index in, int ofs)
{
	char	*pixel;

	pixel = img.addr + (img.len * (y * 150 + in.i))
		+ (x * (img.b_p / 8) * 150) + (in.j * 4) + ofs;
	return (pixel);
}

char	*get_pixel(t_img img, int x, int y)
{
	char	*pixel;

	pixel = img.addr + (img.len * y) + x * (img.b_p / 8);
	return (pixel);
}

/*void	save_exit_image(t_game *game)
{

	int	img_x;
	int	img_y;

	game->exit.img.img = mlx_xpm_file_to_image
		(game->mlx, "texture/exit/exit.xpm", &img_x, &img_y);
	if (!game->exit.img.img)
	{
		ft_putstr(2, RED "ERROR: Well, the exit just decided to disappear. 😢\n" RESET);
		free_all(game, 1);
	}
	game->exit.img.img = mlx_get_data_addr(game->exit.img.img,
			&game->exit.img.b_p, &game->exit.img.len,
			&game->exit.img.endian);
}

void	get_exit(t_game *game)
{
	save_exit_image(game);
	game->exit.anim.img = mlx_new_image(game->mlx, 150, 150);
	game->exit.anim.img = mlx_get_data_addr(game->exit.anim.img,
	 	&game->exit.anim.b_p, &game->exit.anim.len,
	 	&game->exit.anim.endian);
}

void	draw_exit_helper(t_game *game, int x, int y)
{
	t_index			in;
	unsigned int	color;
	char			*pixel_bg;
	char			*pixel_e;
	int				j;

	j = (game->frame / 4) * 149;
	in.i = 0;
	while (in.i < 150)
	{
		in.j = 0;
		while (in.j < 150)
		{
			pixel_bg = get_pixel(game->bg.img, (150 * x) + in.j , (y * 150) + in.i);
			pixel_e = get_pixel_from_image(game->exit.anim, in.j, in.i);
			color = get_color(game->exit.img, (game->exit.frame * 150) + in.j, in.i + j);
            if (get_t(color))
                color = *(unsigned int *)pixel_bg;
			*(unsigned int *)pixel_e = color;
			in.j++;
		}
		in.i++;
	}
}

void	draw_exit(t_game *game)
{
	int	i;

	i = 0;
	game->exit.frame = 0;
	while(i < 23)
	{
		game->exit.frame++;
		draw_exit_helper(game, game->exit.x, game->exit.y);
		mlx_put_image_to_window(game->mlx, game->win, game->exit.anim.img, game->exit.x * 150, game->exit.y * 150);
		custom_usleep();
		i++;
		mlx_do_sync(game->mlx);
	}
}*/