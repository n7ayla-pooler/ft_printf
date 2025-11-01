/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:01:04 by abdnahal          #+#    #+#             */
/*   Updated: 2025/11/01 11:28:04 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_parser(const char *str, va_list args)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count += ft_putchar_fd(va_arg(args, int), 1);
	else if (*str == 's')
		count += ft_putstr_fd(va_arg(args, char *), 1);
	else if (*str == 'p')
		count += print_p(va_arg(args, void *));
	else if (*str == 'd' || *str == 'i')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	else if (*str == 'u')
		count += print_u(va_arg(args, unsigned int));
	else if (*str == 'x' || *str == 'X')
		count += check_hex(va_arg(args, unsigned int), (*str));
	else if (*str == '%')
		count += write(1, "%", 1);
	return (count);
}

int	is_in(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	char	*str;
	int		count;
	int		i;
	va_list	args;

	if (!s)
		return (-1);
	str = "cspdiuxX%";
	count = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] && is_in(s[i + 1], str))
			{
				count += format_parser(&s[i + 1], args);
				i++;
			}
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	len;

	len = printf("Hello %s, your score is %d out of %u. Hex: %x, Pointer: %p, Percent: %%\n", "Alice", -42, 100u, 255, &len);
	printf("Length printed: %d\n", len);
	return (0);
}