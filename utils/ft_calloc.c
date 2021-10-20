/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:05:06 by rgelin            #+#    #+#             */
/*   Updated: 2021/09/28 17:56:24 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	*ft_calloc_modified(size_t count, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	tab = malloc(size * count);
	if (!tab)
		exit(EXIT_FAILURE);
	while (i < count * size)
		((char *)tab)[i++] = 0;
	((char *)tab)[i] = '\0';
	return (tab);
}
