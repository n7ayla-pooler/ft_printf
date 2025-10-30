/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:01:40 by abdnahal          #+#    #+#             */
/*   Updated: 2025/10/30 11:37:52 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		count;

	if (n == -2147483648)
	{
		count = write(fd, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count = write(fd, "-", 1);
		n = -n;
	}
	if (n <= 9)
	{
		c = n + '0';
		count = write(fd, &c, 1);
	}
	else
	{
		count = ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
	return (count + 1);
}

int	ft_putstr_fd(const char *s, int fd)
{
	int	count;

	if (!s)
		return (write(fd, "(null)", 6));
	count = write(fd, s, ft_strlen(s));
	return (count);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
