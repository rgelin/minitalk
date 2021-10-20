/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:29:19 by rgelin            #+#    #+#             */
/*   Updated: 2021/09/28 19:02:35 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_recursive_power(int nb, int power)
{
	int	nbr;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 0)
		power--;
	nbr = nb * ft_recursive_power(nb, power);
	return (nbr);
}
