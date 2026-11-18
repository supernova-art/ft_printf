/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <yait-elm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:54:00 by yait-elm          #+#    #+#             */
/*   Updated: 2026/11/18 10:23:42 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_next(const char *format, int *i, va_list *list)
{
	if (format[*i] != '%')
		return (ft_putchar(format[*i]));
	if (format[*i + 1] == '\0')
		return (-1);
	(*i)++;
	return (format_handler(list, format[*i]));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		tmp;
	int		chars;
	va_list	ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	chars = 0;
	while (format[i])
	{
		tmp = print_next(format, &i, &ap);
		if (tmp == -1)
		{
			chars = -1;
			break ;
		}
		chars += tmp;
		i++;
	}
	va_end(ap);
	return (chars);
}
