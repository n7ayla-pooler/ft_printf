/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <abdnahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:06:04 by abdnahal          #+#    #+#             */
/*   Updated: 2025/10/31 11:14:36 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		print_p(void *p);
int		print_hexa_u(unsigned long nb);
int		print_hexa_l(unsigned long nb);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(const char *str, int fd);
int		ft_putchar_fd(char c, int fd);
int		print_u(unsigned int x);
int		check_hex(long x, char c);
size_t	ft_strlen(const char *s);

#endif
