/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:08:55 by abenzaho          #+#    #+#             */
/*   Updated: 2025/02/20 17:42:19 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_copy1(const char *src)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**copy_double_pointer_array(char **str)
{
	char	**s;
	int		i;

	i = 0;
	s = (char **)malloc(sizeof(char *) * (ft_pointer_counter(str) + 1));
	if (!s)
		return (NULL);
	while (str[i])
	{
		s[i] = ft_copy1(str[i]);
		if (s[i] == NULL)
			return (ft_free(str), ft_free(s), NULL);
		i++;
	}
	s[i] = NULL;
	return (s);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}