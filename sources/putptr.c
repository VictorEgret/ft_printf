/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:44:33 by vegret            #+#    #+#             */
/*   Updated: 2022/11/15 00:00:26 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptrlen(void *ptr, t_flag *flag)
{
	int	len;

	if (!ptr)
		return (5);
	len = hexlen((unsigned long) ptr);
	if (flag && flag->flags & DOT && flag->precision > len)
		len = flag->precision;
	return (2 + len);
}

int	putptr(void *ptr, t_flag *flag)
{
	int	printed;

	printed = 0;
	if (!(flag && flag->flags & ZERO))
		printed = fill_before(flag, ptrlen(ptr, flag));
	if (!ptr)
		printed += write(1, "(nil)", 5);
	else
		printed += write(1, "0x", 2) + putul_hex((unsigned long) ptr, 0, NULL);
	return (printed);
}