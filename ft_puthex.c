/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:47:01 by yait-elm          #+#    #+#             */
/*   Updated: 2026/11/13 09:47:03 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, const char *base)
{
	int	chars;
	int	tmp;

	chars = 0;
	if (n >= 16)
	{
		tmp = ft_puthex(n / 16, base);
		if (tmp == -1)
			return (-1);
		chars += tmp;
	}
	if (ft_putchar(base[n % 16]) == -1)
		return (-1);
	return (chars + 1);
}
