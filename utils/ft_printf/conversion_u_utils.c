/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_u_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:58:31 by rgelin            #+#    #+#             */
/*   Updated: 2021/07/15 17:40:32 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_neg_direction_u(unsigned long nb, t_flag *p_flag,
								t_len *length)
{
	if (p_flag->minus == 1)
		print_u_neg(nb, p_flag, length);
	else
		print_u(nb, p_flag, length);
	return ;
}

unsigned long	print_zero_u(unsigned long nb, t_flag *p_flag,
								t_len *length)
{
	int	i;

	i = 0;
	if (p_flag->dot == 1 || p_flag->zero == 1)
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', 1);
			length->len++;
			nb = -nb;
			if (p_flag->zero == 1)
				i++;
		}
		while (i < (p_flag->precision - count_nbr_u(nb)))
		{
			ft_putchar_fd('0', 1);
			length->len++;
			i++;
		}
	}
	return (nb);
}

int	define_nb_space_u(unsigned long nb, t_flag *p_flag)
{
	int	nb_space;

	nb_space = 0;
	if (nb < 0 && p_flag->precision > count_nbr_u(nb))
		p_flag->size--;
	if (nb == 0 && p_flag->precision == 0 && p_flag->dot == 1)
	{
		nb_space = p_flag->size;
		return (nb_space);
	}
	if (p_flag->dot == 0 || p_flag->precision < count_nbr_u(nb))
		nb_space = p_flag->size - count_nbr_u(nb);
	else
		nb_space = p_flag->size - p_flag->precision;
	return (nb_space);
}

void	print_u(unsigned long nb, t_flag *p_flag, t_len *length)
{
	int	i;
	int	nb_space;

	i = 0;
	nb_space = define_nb_space_u(nb, p_flag);
	print_space(nb_space, length);
	if (nb == 0 && p_flag->precision == 0 && p_flag->dot == 1)
		return ;
	nb = print_zero_u(nb, p_flag, length);
	ft_putnbr_unsigned_fd(nb, 1);
	length->len += count_nbr_u(nb);
	return ;
}

void	print_u_neg(unsigned long nb, t_flag *p_flag, t_len *length)
{
	int	i;
	int	nb_space;

	nb_space = define_nb_space_u(nb, p_flag);
	i = 0;
	if (nb == 0 && p_flag->precision == 0 && p_flag->dot == 1)
		print_space(nb_space, length);
	else
	{
		nb = print_zero_u(nb, p_flag, length);
		ft_putnbr_unsigned_fd(nb, 1);
		length->len += count_nbr_u(nb);
		print_space(nb_space, length);
	}
	return ;
}
