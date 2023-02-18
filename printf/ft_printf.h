/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mredkole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:52:55 by mredkole          #+#    #+#             */
/*   Updated: 2023/02/15 17:30:33 by mredkole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *placeholder, ...);
void	ft_putchar(int c, int *len);
void	ft_putstr(char *ap, int *len);
void	ft_num_unsigned(unsigned int num, int *len);
void	ft_num(int num, int *len);
void	ft_conv_hexa(unsigned long long num, char format, int *len);
void	ft_format_check(va_list *ap, int *len, char format);

#endif
