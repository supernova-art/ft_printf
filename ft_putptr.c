/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:47:09 by yait-elm          #+#    #+#             */
/*   Updated: 2026/11/13 09:47:10 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	int	chars;
	int	tmp;

	if (!p)
		return (ft_putstr("(nil)"));
	chars = 0;
	tmp = ft_putstr("0x");
	if (tmp == -1)
		return (-1);
	chars += tmp;
	tmp = ft_puthex((unsigned long)p, "0123456789abcdef");
	if (tmp == -1)
		return (-1);
	return (chars + tmp);
}
