/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:49:41 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/28 16:46:10 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	custom_usleep(void)
{
	int	i;

	i = 0;
	while (i < SPEED)
		i++;
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

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

char	*get_pixel(t_img img, int x, int y)
{
	char	*pixel;

	pixel = img.addr + (img.len * y) + x * (img.b_p / 8);
	return (pixel);
}
