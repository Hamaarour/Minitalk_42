/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:55:38 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/18 14:54:43 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bit(int sig)
{
	static int	bit;
	static char	res;
	int			j;

	if (sig == SIGUSR2)
		j = 0;
	else
		j = 1;
	res = res * 2 + j;
	bit++;
	if (bit == 8)
	{
		write(1, &res, 1);
		bit = 0;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("wrong argiment.\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID => %d\n", pid);
	ft_printf("Waiting  a message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, get_bit);
		signal(SIGUSR2, get_bit);
		pause();
	}
	return (0);
}
