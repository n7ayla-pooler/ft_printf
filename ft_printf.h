/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnahal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:06:04 by abdnahal          #+#    #+#             */
/*   Updated: 2025/10/29 17:16:18 by abdnahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
int		print_p(void *p);
// int count_num(long long nbr);
// int count_hex(long long nbr);
int		print_hexa_u(long long nb);
int		print_hexa_l(long long nb);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(const char *str, int fd);
int		ft_putchar_fd(char c, int fd);
int		print_u(unsigned int x);
int		check_hex(long x, char c);
size_t	ft_strlen(const char *s);

#endif
