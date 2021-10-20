/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 00:19:38 by rgelin            #+#    #+#             */
/*   Updated: 2021/09/28 19:06:27 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./utils/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <signal.h>

int		ft_atoi(const char *str);
int		ft_recursive_power(int nb, int power);
void	*ft_calloc_modified(size_t count, size_t size);
int		ft_isdigit(int c);

#endif
