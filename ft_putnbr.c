/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <yait-elm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:47:22 by yait-elm          #+#    #+#             */
/*   Updated: 2026/11/13 09:47:23 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long n)
{
	int	chars;
	int	tmp;

	chars = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n = n * -1;
		chars++;
	}
	if (n > 9)
	{
		tmp = ft_putnbr(n / 10);
		if (tmp == -1)
			return (-1);
		chars += tmp;
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	return (chars + 1);
}
