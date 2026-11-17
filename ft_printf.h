/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <yait-elm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:51:48 by yait-elm          #+#    #+#             */
/*   Updated: 2026/11/13 09:51:51 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int i);
int	ft_putnbr(long long n);
int	ft_putstr(const char *s);
int	ft_puthex(unsigned long n, const char *base);
int	ft_putptr(void *p);
int	ft_printf(const char *format, ...);
int	format_handler(va_list *vl, char format);

#endif
