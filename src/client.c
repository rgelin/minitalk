/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 00:47:17 by rgelin            #+#    #+#             */
/*   Updated: 2021/10/14 14:57:44 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	g_signal_acknowledge = 0;

static int	check_error(int ac, char *av[])
{
	int	i;

	if (ac != 3)
		return (1);
	i = 0;
	while (av[1][i])
	{
		if (!ft_isdigit(av[1][i]))
			return (1);
		i++;
	}
	return (0);
}

static void	send_str(int pid, char *str)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{		
		j = 0;
		c = str[i++];
		while (j++ < 8)
		{
			if (c & 1)
				kill((pid_t)pid, SIGUSR2);
			else
				kill((pid_t)pid, SIGUSR1);
			c = c >> 1;
			usleep(100);
		}
	}
}

static void	send_length_str(int pid, int length)
{
	int	i;

	i = 0;
	while (i++ < 32)
	{
		if (length & 1)
			kill((pid_t)pid, SIGUSR2);
		else
			kill((pid_t)pid, SIGUSR1);
		length = length >> 1;
		usleep(100);
	}
}

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_signal_acknowledge = 1;
}

int	main(int ac, char *av[])
{
	int	pid;
	int	length;

	if (check_error(ac, av))
		return (-1);
	pid = ft_atoi(av[1]);
	length = ft_strlen(av[2]);
	if (signal(SIGUSR1, signal_handler) == SIG_ERR)
		exit(EXIT_FAILURE);
	send_length_str(pid, (int)getpid());
	send_length_str(pid, length);
	send_str(pid, av[2]);
	while (1)
	{
		if (g_signal_acknowledge == 1)
		{
			g_signal_acknowledge = 0;
			break ;
		}
		pause();
	}
	return (0);
}
