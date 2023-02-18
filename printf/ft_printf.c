/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:58:28 by mredkole          #+#    #+#             */
/*   Updated: 2023/02/15 18:08:55 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pointer_check(unsigned long long num, int *len)
{
	if (num == 0)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	else
	{
		ft_putstr("0x", len);
		ft_conv_hexa(num, 'x', len);
	}
}

void	ft_format_check(va_list *ap, int *len, char format)
{
	if (format == 'c')
		ft_putchar(va_arg(*ap, int), len);
	else if (format == 's')
		ft_putstr(va_arg(*ap, char *), len);
	else if (format == 'p')
		pointer_check(va_arg(*ap, unsigned long long), len);
	else if (format == 'd' || format == 'i')
		ft_num(va_arg(*ap, int), len);
	else if (format == 'u')
		ft_num_unsigned(va_arg(*ap, unsigned int), len);
	else if (format == 'x')
		ft_conv_hexa(va_arg(*ap, unsigned int), format, len);
	else if (format == 'X')
		ft_conv_hexa(va_arg(*ap, unsigned int), format, len);
	else if (format == '%')
		ft_putchar('%', len);
}	

int	ft_printf(const char *placeholder, ...)
{
	int		len;
	int		i;
	va_list	ap;

	len = 0;
	i = 0;
	va_start(ap, placeholder);
	while (placeholder[i])
	{
		if (placeholder[i] == '%')
		{
			ft_format_check(&ap, &len, placeholder[i + 1]);
			i++;
		}
		else
			ft_putchar((char)placeholder[i], &len);
		i++;
	}
	va_end(ap);
	return (len);
}
/*int	main(void)
{
	char	*arr;
	int	n, res1, res2;
	char	c;
	unsigned int	p;
	arr = " fghjghj se 235y: dr`";
 	n = -2647678;
	c = 'D';
	p  = 234;
	res1 = ft_printf("%s", arr);
	res2 = printf("%s", arr);
	res1 = ft_printf("deci prosim  %d\t \n", n);
	res2 = printf("deci prosim  %d\t \n", n);
	res1 = ft_printf("chacha %c\n", c);
	res2 = printf("chacha %c\n", c);
	res1 = ft_printf("int %i\n", n);
	res2 = printf("int %i\n", n);
	res1 = ft_printf("unsigned %u\n", p);
	res2 = printf("unsigned %u\n", p);
	res1 = ft_printf("hex %X\n", p);
	res2 = printf("hex %X\n", p);
	res1 = ft_printf("hexaaaaaaaaaaa %x\n", p);
	res2 = printf("hexaaaaaaaaaaa %x\n", p);
	res1 = ft_printf("percent %%\n");
	res2 = printf("percent %%\n");
	res1 = ft_printf("void*: %p %p\n", 0, 0);
	res2 = printf("void*: %p %p\n", 0, 0);
	printf ("%i - %i\n", res1, res2);
}*/
