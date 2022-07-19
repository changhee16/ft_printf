/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:30:47 by ccho              #+#    #+#             */
/*   Updated: 2022/07/19 14:19:45 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define SMALL_X 1
# define BIG_X 2

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_hex(unsigned int dec, int i);
int		ft_ptr(void *ptr);
int		ft_ptr_hex(unsigned long long dec);
int		ft_putnbr(int n);
int		ft_unsigned(int n);
int		ft_check(char c, va_list *ap);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *f, ...);

#endif