/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyujlee <kyujlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:57:50 by kyujlee           #+#    #+#             */
/*   Updated: 2021/09/26 14:41:38 by kyujlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	format_handler(va_list ap, char format)
{
	if (format == 'c')
		return (print_char(ap));
	else if (format == '%')
		return (ft_putchar('%'));
	else if (format == 's')
		return (print_str(ap));
	else if (format == 'd' || format == 'i')
		return (print_dec(ap));
	else if (format == 'u')
		return (print_u_dec(ap));
	else if (format == 'x' || format == 'X')
		return (print_hex(ap, format));
	else if (format == 'p')
		return (print_addr(ap));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		idx;
	int		ret;

	idx = 0;
	ret = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] != '%')
			ret += ft_putchar(str[idx]);
		else
		{
			if (format_handler(ap, str[++idx]) == -1)
				return (-1);
			ret += format_handler(ap, str[idx]);
		idx++;
	}
	va_end(ap);
	return (ret);
}
