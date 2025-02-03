/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:54:59 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/03 15:30:02 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_args_number1(int ac)
{
	if (ac < 2)
	{
		ft_putstr(2, RED "\n      🚨 CRITICAL ERROR 🚨\n" RESET);
		ft_putstr(2, "==================================\n");
		ft_putstr(2, YELLOW "     😱 NO MAP DETECTED! 😱\n" RESET);
		ft_putstr(2, "==================================\n");
		ft_putstr(2, "    🔍 Scanning for a map...\n");
		ft_putstr(2, " ❌ ERROR: No map found! 🕳️\n");
		ft_putstr(2, " ❌ The game refuses to start! 🤖\n");
		ft_putstr(2, " ❌ Where do you expect to go? 🧭\n");
		ft_putstr(2, "==================================\n");
		ft_putstr(2, " 💡 SOLUTION: Provide a map! 📜\n");
		ft_putstr(2, " 💡 Usage: ./so_long [map.ber]\n");
		ft_putstr(2, "==================================\n");
		ft_putstr(2, RED " 💀 SYSTEM FAILURE: EXITING... 💀\n" RESET);
		exit(1);
	}
}

void	check_args_number2(int ac)
{
	if (ac > 2)
	{
		ft_putstr(2, RED "\n      🚨 CRITICAL ERROR 🚨\n" RESET);
		ft_putstr(2, "==================================\n");
		ft_putstr(2, YELLOW "    🤯 TOO MANY ARGUMENTS! 🤯\n" RESET);
		ft_putstr(2, "==================================\n");
		ft_putstr(2, "     🔍 Processing input...\n");
		ft_putstr(2, " ❌ ERROR: Brain overload! 💥\n");
		ft_putstr(2, " ❌ The game is confused! 🌀\n");
		ft_putstr(2, " ❌ One map at a time, please! 🗺️\n");
		ft_putstr(2, "==================================\n");
		ft_putstr(2, " 💡 SOLUTION: Provide ONE map! 📜\n");
		ft_putstr(2, " 💡 Usage: ./so_long [map.ber]\n");
		ft_putstr(2, "==================================\n");
		ft_putstr(2, RED " 💀 SYSTEM FAILURE: EXITING... 💀\n" RESET);
		exit(1);
	}
}

void	check_if_valid_extension(char **av)
{
	int	i;

	i = 0;
	while (av[1][i] != '\0' && av[1][i] != '.')
		i++;
	if (ft_strcmp(av[1] + i, ".ber") != 0)
	{
		ft_putstr(2, RED "\n     🚨 ERROR: INVALID FILE TYPE 🚨\n" RESET);
		ft_putstr(2, "========================================\n");
		ft_putstr(2, YELLOW "     🤨 This is NOT a .ber file! 🤨\n" RESET);
		ft_putstr(2, "========================================\n");
		ft_putstr(2, "           🔍 Checking file...\n");
		ft_putstr(2, " ❌ ERROR: Unknown extension! ❓\n");
		ft_putstr(2, " ❌ The game only accepts .ber files! 🗺️\n");
		ft_putstr(2, " ❌ Your file is rejected! 🚫\n");
		ft_putstr(2, "========================================\n");
		ft_putstr(2, " 💡 SOLUTION: Use a .ber file 📜\n");
		ft_putstr(2, " 💡 Example: ./so_long map.ber\n");
		ft_putstr(2, "========================================\n");
		ft_putstr(2, RED "    💀 SYSTEM FAILURE: EXITING... 💀\n" RESET);
		exit(1);
	}
}

void	check_map_if_valid(char **av)
{
	check_if_valid_extension(av);
	check_map_valid_chape_and_content(av);
}

void	args_checker(int ac, char **av)
{
	check_args_number1(ac);
	check_args_number2(ac);
	check_map_if_valid(av);
}
