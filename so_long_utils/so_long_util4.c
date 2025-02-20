/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:45:45 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/20 16:26:59 by abenzaho         ###   ########.fr       */
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