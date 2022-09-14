/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:14:40 by vegret            #+#    #+#             */
/*   Updated: 2022/09/14 17:14:40 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	handle_conv(char c, va_list args)
{
	//if (c == 'c')
	//	ft_putchar(va_arg(args, char));
	//else if (c == 'd' || c == 'i')
	//	ft_putnbr(va_arg(args, int));
	//else if (c == '%')
	//	ft_putchar('%');
	//else if (c == 's')
	//	ft_putstr(va_arg(args, char *));
	//else if (c == 't')
	//	ft_putnbr(va_arg(args, int));
}

int	ft_printf(const char *format, ...)
{
	int				i;
	unsigned int	count;
	va_list			args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += handle_conv(format[i + 1], args);
			i++;
		}
		else
			//count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("%d\n", 0x2A);
	return 0;
}
