/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:01:04 by abdnahal          #+#    #+#             */
/*   Updated: 2025/11/03 09:42:24 by abdnahal         ###   ########.fr       */
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
	va_list	args;

	int count, (i);
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
				count += format_parser(&s[i + 1], args);
			i++;
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// int main()
// {

// 	int ret1, ret2;

// 	printf("===== BASIC TESTS =====\n");

// 	ret1 = printf("1: %d\n", 0);
// 	ret2 = ft_printf("1: %d\n", 0);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("2: %d\n", -42);
// 	ret2 = ft_printf("2: %d\n", -42);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("3: %i\n", 2147483647);
// 	ret2 = ft_printf("3: %i\n", 2147483647);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("4: %d\n", -2147483648);
// 	ret2 = ft_printf("4: %d\n", -2147483648);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("5: %u\n", 4294967295u);
// 	ret2 = ft_printf("5: %u\n", 4294967295u);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	printf("===== CHAR AND STRING =====\n");

// 	ret1 = printf("6: %c %c %c\n", 'A', 0, 'Z');
// 	ret2 = ft_printf("6: %c %c %c\n", 'A', 0, 'Z');
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("7: %s\n", "Hello");
// 	ret2 = ft_printf("7: %s\n", "Hello");
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("8: %s\n", "");
// 	ret2 = ft_printf("8: %s\n", "");
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("9: %s\n", NULL);
// 	ret2 = ft_printf("9: %s\n", NULL);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	printf("===== HEXADECIMAL =====\n");

// 	ret1 = printf("10: %x\n", 255);
// 	ret2 = ft_printf("10: %x\n", 255);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("11: %X\n", 255);
// 	ret2 = ft_printf("11: %X\n", 255);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	printf("===== POINTERS =====\n");

// 	ret1 = printf("12: %p\n", (void *)0);
// 	ret2 = ft_printf("12: %p\n", (void *)0);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("13: %p\n", (void *)1234);
// 	ret2 = ft_printf("13: %p\n", (void *)1234);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("14: %p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
// 	ret2 = ft_printf("14: %p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	printf("===== PERCENT SIGN =====\n");

// 	ret1 = printf("15: %%\n");
// 	ret2 = ft_printf("15: %%\n");
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("16: %%%% DONE\n");
// 	ret2 = ft_printf("16: %%%% DONE\n");
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	printf("===== MIXED & MULTIPLE =====\n");

// 	ret1 = printf("17: Hello %s, your score is %d/%u!\n", "Bob", 42, 100);
// 	ret2 = ft_printf("17: Hello %s, your score is %d/%u!\n", "Bob", 42, 100);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("18: Hex: %x, Unsigned: %u, Dec: %d\n", 255, 255, 255);
// 	ret2 = ft_printf("18: Hex: %x, Unsigned: %u, Dec: %d\n", 255, 255, 255);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("19: %d %s %c %p %%\n", 42, "test", '!', (void *)42);
// 	ret2 = ft_printf("19: %d %s %c %p %%\n", 42, "test", '!', (void *)42);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	printf("===== STRESS & EDGE =====\n");

// 	ret1 = printf("20: %d%d%d%d%d%d%d%d%d%d\n", 1,2,3,4,5,6,7,8,9,10);
// 	ret2 = ft_printf("20: %d%d%d%d%d%d%d%d%d%d\n", 1,2,3,4,5,6,7,8,9,10);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("21: %s\n", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
// 	ret2 = ft_printf("21: %s\n", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("22: %d %i %u %x %X\n", -1, -42, 4294967295u, -1, -42);
// 	ret2 = ft_printf("22: %d %i %u %x %X\n", -1, -42, 4294967295u, -1, -42);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	printf("===== INVALID & WEIRD =====\n");

// 	ret1 = printf("23: %q\n"); // invalid specifier
// 	ret2 = ft_printf("23: %q\n");
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("24: %s%s%s\n", NULL, NULL, "end");
// 	ret2 = ft_printf("24: %s%s%s\n", NULL, NULL, "end");
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	ret1 = printf("25: %p %p %p\n", NULL, NULL, NULL);
// 	ret2 = ft_printf("25: %p %p %p\n", NULL, NULL, NULL);
// 	printf("printf ret: %d | ft_printf ret: %d\n\n", ret1, ret2);

// 	printf("===== DONE =====\n");
// 	return (0);
// }