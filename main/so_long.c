/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:48:45 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/06 15:00:35 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	void	*mlx;
	
	args_checker(ac, av);
	mlx = mlx_init();
	if (!mlx)
	{
		ft_putstr(2, "Error: MLX failed! 🖥️ Did the X server take a nap? 😴\n");
		return (1);
	}
	mlx_destroy_display(mlx);
    free(mlx);
	return (0);	
}
