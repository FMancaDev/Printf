/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:24:28 by fomanca           #+#    #+#             */
/*   Updated: 2025/10/28 16:53:46 by fomanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(const char *f, va_list args, unsigned int *c)
{
	void	*p;

	if (*f == 'c')
		*c += write(1, &(char){va_arg(args, int)}, 1);
	else if (*f == 's')
		ft_putstr(va_arg(args, char *), c);
	else if (*f == 'p')
	{
		p = va_arg(args, void *);
		if (!p)
			ft_putstr("(nil)", c);
		else
		{
			ft_putstr("0x", c);
			ft_puthexp((unsigned long)p, c);
		}
	}
	else if (*f == 'd' || *f == 'i')
		ft_putnbr(va_arg(args, int), c);
	else if (*f == 'u')
		ft_putunbr(va_arg(args, unsigned int), c);
	else if (*f == 'x' || *f == 'X')
		ft_puthex(va_arg(args, unsigned int), *f, c);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	result;

	if (!str)
		return (-1);
	result = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (str[1] == '%')
				result += write(1, "%", 1);
			else
				ft_flags(str + 1, args, &result);
			str++;
		}
		else
			result += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (result);
}
