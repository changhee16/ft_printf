/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:17:58 by ccho              #+#    #+#             */
/*   Updated: 2022/07/19 14:18:28 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
	{
		i += ft_putstr("(null)") + 1;
		return (i);
	}
	while (s[++i])
	{
		ft_putchar(s[i]);
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (c == s[i])
			return ((char *)s + i);
		i++;
	}
	return (0);
}

int	ft_check(char c, va_list *ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(*ap, int));
	else if (c == 's')
		len += ft_putstr(va_arg(*ap, char *));
	else if (c == 'p')
		len += ft_ptr(va_arg(*ap, void *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(*ap, int));
	else if (c == 'u')
		len += ft_unsigned(va_arg(*ap, int));
	else if (c == 'x')
		len += ft_hex(va_arg(*ap, int), SMALL_X);
	else if (c == 'X')
		len += ft_hex(va_arg(*ap, int), BIG_X);
	return (len);
}

int	ft_printf(const char *f, ...)
{
	va_list	ap;
	int		cnt;
	int		len;

	va_start(ap, f);
	cnt = -1;
	len = 0;
	while (f[++cnt])
	{
		if ((f[cnt] == '%') && (ft_strchr("cspdiuxX%", f[cnt + 1])))
		{
			if (f[++cnt] == '%')
				len += ft_putchar('%');
			else
				len += ft_check(f[cnt], &ap);
		}
		else
			len += ft_putchar(f[cnt]);
	}
	va_end(ap);
	return (len);
}
