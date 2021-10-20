/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 00:47:14 by rgelin            #+#    #+#             */
/*   Updated: 2021/10/19 15:44:24 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	receive_length_str(int signal, char **str,
								int *bit, int *length_received)
{
	static int	length = 0;

	if (signal == SIGUSR2)
		length += ft_recursive_power(2, *bit);
	(*bit)++;
	if (*bit == 32)
	{
		*str = ft_calloc_modified((size_t)length + 1, sizeof(char));
		*bit = 0;
		*length_received = length;
		length = 0;
	}
}

static void	print_str(int signal, char **str, int *bit, int *length_received)
{
	static int	i = 0;
	static char	c = 0;

	if (signal == SIGUSR2)
		c += ft_recursive_power(2, *bit);
	(*bit)++;
	if (*bit == 8)
	{
		(*str)[i++] = c;
		if (i == *length_received)
		{
			ft_printf("%s\n", *str);
			*length_received = 0;
			i = 0;
			free (*str);
			*str = NULL;
		}
		c = 0;
		*bit = 0;
	}
}

static void	get_pid_client(int signal, int *bit, int *pid_client)
{
	static int	pid = 0;

	if (signal == SIGUSR2)
		pid += ft_recursive_power(2, *bit);
	(*bit)++;
	if (*bit == 32)
	{
		*bit = 0;
		*pid_client = pid;
		pid = 0;
	}
}

static void	signal_handler(int signal)
{
	static int	bit = 0;
	static int	length_received = 0;
	static char	*str = NULL;
	static int	pid_client = 0;

	if (!pid_client)
		get_pid_client(signal, &bit, &pid_client);
	else if (!length_received)
		receive_length_str(signal, &str, &bit, &length_received);
	else
	{
		print_str(signal, &str, &bit, &length_received);
		if (length_received == 0)
			pid_client = 0;
	}
	if (pid_client)
		kill((pid_t)pid_client, SIGUSR1);
}

int	main(void)
{
	ft_printf("%d\n", (int)getpid());
	if (signal(SIGUSR1, signal_handler) == SIG_ERR)
		exit(EXIT_FAILURE);
	if (signal(SIGUSR2, signal_handler) == SIG_ERR)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
