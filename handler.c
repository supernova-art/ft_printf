/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:31:59 by yait-elm          #+#    #+#             */
/*   Updated: 2026/11/16 11:32:01 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_unknown(char format)
{
	int	chars;
	int	i;

	chars = 0;
	i = ft_putchar('%');
	if (i == -1)
		return (-1);
	chars++;
	i = ft_putchar(format);
	if (i == -1)
		return (-1);
	return (chars + i);
}

int	format_handler(va_list *vl, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*vl, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*vl, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(*vl, int)));
	else if (format == 'x')
		return (ft_puthex(va_arg(*vl, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_puthex(va_arg(*vl, unsigned int), "0123456789ABCDEF"));
	else if (format == 'u')
		return (ft_putnbr(va_arg(*vl, unsigned int)));
	else if (format == 'p')
		return (ft_putptr(va_arg(*vl, void *)));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (print_unknown(format));
}
