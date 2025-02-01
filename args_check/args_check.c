/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:54:59 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/01 19:10:28 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_args_number1(int ac)
{
	if (ac < 2)
	{
		write(2, "\n  🔥 CRITICAL ERROR: MAP MISSING 🔥\n", 41);
		write(2, "=====================================\n", 38);
		write(2, "   😱 THE UNIVERSE IS COLLAPSING 😱 \n", 41);
		write(2, "=====================================\n", 38);
		write(2, "    🔍 Searching for solutions...\n", 36);
		write(2, " ❌ GPS? Lost in another dimension.\n", 37);
		write(2, " ❌ Compass? Pointing to Narnia.🦁\n", 38);
		write(2, " ❌ Google Maps? Says 'You're doomed.\n", 39);
		write(2, "=====================================\n", 38);
		write(2, "          ⚠️ Possible Causes:\n", 34);
		write(2, "    - Wormhole interference. 🌌\n", 34);
		write(2, "    - Gremlins stole it. 🦴\n", 30);
		write(2, "    - You trusted your memory. 🤡\n", 36);
		write(2, "=====================================\n", 38);
		write(2, "          🚀 Suggested Fixes:\n", 32);
		write(2, "    - Cry. 😭\n", 16);
		write(2, "    - Call Batman. 🦇\n", 24);
		write(2, "    - Accept your fate. 🕳️\n", 32);
		write(2, "=====================================\n", 38);
		exit(1);
	}
}

void	check_args_number2(int ac)
{
	if (ac > 2)
	{
		write(2, "\n\033[1;31m  🔥 CRITICAL ERROR: TOO MANY ARGUMENTS 🔥\033[0m\n", 59);
		write(2, "\033[1;33m===========================================\033[0m\n", 55);
		write(2, "\033[1;31m  😱 The game can only handle one map! 😱\033[0m\n", 64);
		write(2, "\033[1;33m===========================================\033[0m\n", 55);
		write(2, "\033[1;34m    🔍 Searching for the extra map...\033[0m\n", 51);
		write(2, "\033[1;31m  ❌ Even the game is confused now.\033[0m\n", 48);
		write(2, "\033[1;31m  ❌ More than one map? The chaos! 🤯\033[0m\n", 52);
		write(2, "\033[1;31m❌ The program can’t process this many.\033[0m\n", 50);
		write(2, "\033[1;33m===========================================\033[0m\n", 49);
		write(2, "\033[1;35m⚠️ Possible Causes:\033[0m\n", 34);
		write(2, "\033[1;35m- You’re trying to break the game. 💥\033[0m\n", 49);
		write(2, "\033[1;35m- You love maps too much. 🗺️❤️\033[0m\n", 47);
		write(2, "\033[1;35m- The game is overwhelmed by choice. 😵\033[0m\n", 49);
		write(2, "\033[1;33m===========================================\033[0m\n", 49);
		write(2, "\033[1;32m🚀 Suggested Fixes:\033[0m\n", 31);
		write(2, "\033[1;32m- Only one map, please. 🙏\033[0m\n", 36);
		write(2, "\033[1;32m- Remove the extra maps. 🗑️\033[0m\n", 40);
		write(2, "\033[1;32m- Restart and try again with ONE map. 🔄\033[0m\n", 50);
		write(2, "\033[1;33m===========================================\033[0m\n", 49);
		exit(1);
	}
}

void	args_checker(int ac, char **av)
{
	check_args_number1(ac);
	check_args_number2(ac);
	(void)av;
}
