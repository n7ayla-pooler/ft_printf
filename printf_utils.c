/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:01:21 by abdnahal          #+#    #+#             */
/*   Updated: 2025/11/02 09:03:01 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_l(unsigned long nb)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (nb < 16)
		return (write(1, &base[nb], 1));
	else
	{
		count += print_hexa_l(nb / 16);
		write(1, &base[nb % 16], 1);
	}
	return (count + 1);
}

int	print_hexa_u(unsigned long nb)
{
	char	*base;
	char	c;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (nb < 16)
		return (write(1, &base[nb], 1));
	else
	{
		count += print_hexa_u(nb / 16);
		c = base[nb % 16];
		write(1, &c, 1);
	}
	return (count + 1);
}

int	print_u(unsigned int x)
{
	char	c;
	int		count;

	if (x <= 9)
	{
		c = x + '0';
		count = write(1, &c, 1);
		return (count);
	}
	else
	{
		count = print_u(x / 10);
		c = x % 10 + '0';
		write(1, &c, 1);
	}
	return (count + 1);
}

int	print_p(void *p)
{
	unsigned long	pr;
	int				count;

	if (!p)
		return (write(1, "(nil)", 5));
	pr = (unsigned long)p;
	count = write(1, "0x", 2);
	count += print_hexa_l(pr);
	return (count);
}

int	check_hex(long x, char c)
{
	if (c == 'X')
		return (print_hexa_u(x));
	else
		return (print_hexa_l(x));
}
