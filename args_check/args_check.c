/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:54:59 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/01 19:00:16 by abenzaho         ###   ########.fr       */
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
		write(2, "\n  🔥 CRITICAL ERROR: TOO MANY ARGUMENTS 🔥\n", 48);
		write(2, "===========================================\n", 44);
		write(2, "  😱 The game can only handle one map! 😱\n", 46);
		write(2, "===========================================\n", 44);
		write(2, "    🔍 Searching for the extra map...\n", 40);
		write(2, "  ❌ Even the game is confused now.\n", 37);
		write(2, "  ❌ More than one map? The chaos! 🤯\n", 41);
		write(2, "  ❌ The program can’t process this many.\n", 45);
		write(2, "===========================================\n", 44);
		write(2, "            ⚠️ Possible Causes:\n", 36);
		write(2, "  - You’re trying to break the game. 💥\n", 44);
		write(2, "  - You love maps too much. 🗺️❤️\n", 42);
		write(2, "  - The game is overwhelmed by choice. 😵\n", 44);
		write(2, "===========================================\n", 44);
		write(2, "            🚀 Suggested Fixes:\n", 34);
		write(2, "  - Only one map, please. 🙏\n", 31);
		write(2, "  - Remove the extra maps. 🗑️\n", 35);
		write(2, "  - Restart and try again with ONE map. 🔄\n", 45);
		write(2, "===========================================\n", 44);
		exit(1);
	}
}

void	args_checker(int ac, char **av)
{
	check_args_number1(ac);
	check_args_number2(ac);
	(void)av;
}
