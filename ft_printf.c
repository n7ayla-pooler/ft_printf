/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:01:04 by abdnahal          #+#    #+#             */
/*   Updated: 2025/10/30 11:31:54 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     format_parser(const char *str, va_list args)
{
        int     count;

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

int     is_in(char c, char *s)
{
        int     i;

        i = 0;
        while (s[i])
        {
                if (s[i] == c)
                        return (1);
                i++;
        }
        return (0);
}

int     ft_printf(const char *s, ...)
{
        char    *str;
        int             count;
        int             i;
        va_list args;

        if (!s)
                return (write(1, "(null)", 6));
        str = "cspdiuxX%";
        count = 0;
        i = 0;
        va_start(args, s);
        while (s[i])
        {
                if (s[i] == '%')
                {
                        if (is_in(s[i + 1], str) && s[i + 1])
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

int main()

{
    int x = 0;
    printf("%d\n", printf("%p\n", &x));
    printf("%d\n", ft_printf("%p\n", &x));
}

// int main(void)
// {
//     int ret1, ret2;

//     printf("=== 🧩 FT_PRINTF TESTS ===\n\n");

//     // Characters
//     printf("1️⃣ Char test:\n");
//     ret1 = ft_printf("ft_printf: %c\n\n", 'A');
//     ret2 = printf("printf   : %c\n\n", 'A');
//     printf("Return values: ft_printf = %d | printf = %d\n\n", ret1, ret2);

//     // Strings
//     printf("2️⃣ String test:\n");
//     ret1 = ft_printf("ft_printf: %s\n\n", "Hello 42");
//     ret2 = printf("printf   : %s\n\n", "Hello 42");
//     printf("Return values: ft_printf = %d | printf = %d\n\n", ret1, ret2);

//     // NULL string
//     printf("3️⃣ NULL string:\n");
//     ret1 = ft_printf("ft_printf: %s\n\n", (char *)NULL);
//     ret2 = printf("printf   : %s\n\n", (char *)NULL);
//     printf("Return values: ft_printf = %d | printf = %d\n\n", ret1, ret2);

//     // Integers
//     printf("4️⃣ Integers:\n");
//     ret1 = ft_printf("%d|%i\n", 42, -42);
//     ret2 = printf("%d|%i\n", 42, -42);
//     printf("Return values: ft_printf = %d | printf = %d\n\n", ret1, ret2);

//     // Unsigned
//     printf("5️⃣ Unsigned:\n");
//     ret1 = ft_printf("ft_printf: %u\n\n", 4294967295u);
//     ret2 = printf("printf   : %u\n\n", 4294967295u);
//     printf("Return values: ft_printf = %d | printf = %d\n\n", ret1, ret2);

//     // Hexadecimal
//     printf("6️⃣ Hexadecimal:\n");
//     ret1 = ft_printf("ft_printf: %x | %X\n\n", 255, 255);
//     ret2 = printf("printf   : %x | %X\n\n", 255, 255);
//     printf("Return values: ft_printf = %d | printf = %d\n\n", ret1, ret2);

//     // Pointer
//     printf("7️⃣ Pointer:\n");
//     void *ptr = (void *)0x1234abcd;
//     ret1 = ft_printf("ft_printf: %p\n\n", ptr);
//     ret2 = printf("printf   : %p\n\n", ptr);
//     printf("Return values: ft_printf = %d | printf = %d\n\n", ret1, ret2);

//     // Percent sign
//     printf("8️⃣ Percent sign:\n");
//     ret1 = ft_printf("ft_printf: 100%% sure\n\n");
//     ret2 = printf("printf   : 100%% sure\n\n");
//     printf("Return values: ft_printf = %d | printf = %d\n\n", ret1, ret2);

//     // Mixed format
//     printf("9️⃣ Mixed format:\n");
//     ret1 = ft_printf("ft_printf: %c %s %d %u %x %p %%\n\n", 'A', "Hello", -42, 42, 255, ptr);
//     ret2 = printf("printf   : %c %s %d %u %x %p %%\n\n", 'A', "Hello", -42, 42, 255, ptr);
//     printf("Return values: ft_printf = %d | printf = %d\n\n", ret1, ret2);

//     printf("✅ Tests completed!\n");
//     return (0);
// }