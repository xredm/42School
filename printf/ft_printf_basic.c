/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:42:21 by mredkole          #+#    #+#             */
/*   Updated: 2023/02/15 18:11:08 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(char *ap, int *len)
{
	int	i;

	i = 0;
	if (ap == 0)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	while (ap[i])
	{
		ft_putchar(ap[i], len);
		i++;
	}
}

void	ft_num(int num, int *len)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len += 11;
		return ;
	}
	if (num < 0)
	{
		ft_putchar('-', len);
		num *= -1;
		ft_num(num, len);
	}
	else
	{
		if (num > 9)
		{
			ft_num(num / 10, len);
		}
		ft_putchar(num % 10 + '0', len);
	}
}

void	ft_num_unsigned(unsigned int num, int *len)
{
	if (num > 9)
	{
		ft_num_unsigned(num / 10, len);
		ft_num_unsigned(num % 10, len);
	}
	else
		ft_putchar(num + '0', len);
}

void	ft_conv_hexa(unsigned long long num, char format, int *len)
{
	if (num >= 16)
	{
		ft_conv_hexa(num / 16, format, len);
		ft_conv_hexa(num % 16, format, len);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0', len);
		else
		{
			if (format == 'x')
				ft_putchar(num - 10 + 'a', len);
			if (format == 'X')
				ft_putchar(num - 10 + 'A', len);
		}
	}
}
