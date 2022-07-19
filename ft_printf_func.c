/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 03:04:40 by ccho              #+#    #+#             */
/*   Updated: 2022/07/19 14:18:41 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		len += ft_putstr("-2147483648");
	else if (n < 0)
	{
		len += ft_putchar('-');
		len += ft_putnbr(-n);
	}
	else if (n < 10 && n >= 0)
	{
		len += ft_putchar(n + '0');
	}
	else if (n > 0)
	{
		len += ft_putnbr(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	return (len);
}

int	ft_hex(unsigned int dec, int i)
{
	int	len;

	len = 0;
	if (dec < 16)
	{
		if (dec < 10)
			len += ft_putchar(dec + '0');
		else
		{
			if (i == SMALL_X)
				len += ft_putchar(dec - 10 + 'a');
			else
				len += ft_putchar(dec - 10 + 'A');
		}
	}
	else
	{
		len += ft_hex(dec / 16, i);
		len += ft_hex(dec % 16, i);
	}
	return (len);
}

int	ft_ptr_hex(unsigned long long dec)
{
	int	len;

	len = 0;
	if (dec < 16)
	{
		if (dec < 10)
			len += ft_putchar(dec + '0');
		else
			len += ft_putchar(dec - 10 + 'a');
	}
	else
	{
		len += ft_ptr_hex(dec / 16);
		len += ft_ptr_hex(dec % 16);
	}
	return (len);
}

int	ft_ptr(void *ptr)
{
	int	len;

	len = 2;
	ft_putstr("0x");
	len += ft_ptr_hex((unsigned long long)ptr);
	return (len);
}

int	ft_unsigned(int n)
{
	int				len;
	unsigned int	u;

	len = 0;
	u = n;
	if (u < 10 && u >= 0)
	{
		len += ft_putchar(u + '0');
	}
	else if (u > 0)
	{
		len += ft_putnbr(u / 10);
		len += ft_putchar(u % 10 + '0');
	}
	return (len);
}
