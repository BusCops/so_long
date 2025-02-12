/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:05:22 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/12 14:44:57 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_event(int keycode, t_vars *mlxvar)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(mlxvar->mlx, mlxvar->win);
		exit(0);
	}
	return (0);
}
