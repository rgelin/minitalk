/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:25:15 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/16 15:08:33 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_print(va_list ap, const char *format, t_len *length)
{
	int		i;
	char	*flag;

	i = 0;
	flag = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			flag = extract_flag(format, i, length);
			if (flag == NULL)
				return ;
			while (!ft_strchr("cspdiuxX%", format[i]))
				i++;
			print_direction(ap, flag, length);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			length->len++;
		}
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	t_len	*length;

	va_list (ap);
	ret = 0;
	length = (t_len *)malloc(sizeof(t_len));
	if (!length)
		return (-1);
	va_start(ap, format);
	ini_struct_len(length);
	to_print(ap, format, length);
	va_end(ap);
	ret = length->len;
	free(length);
	return (ret);
}
