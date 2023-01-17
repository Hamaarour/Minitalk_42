/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:55:35 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/17 16:50:00 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	unsigned long	res;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (res > 9223372036854775807 && n == 1)
		return (-1);
	else if (res > 9223372036854775807 && n == -1)
		return (0);
	return (res * n);
}

void	send_bit(int pid, char c)
{
	int	i;
	int	*bit;

	bit = malloc(8 * sizeof(int));
	i = 7;
	while (i >= 0)
	{
		bit[i] = c % 2;
		c /= 2;
		i--;
	}
	i = 0;
	while (i < 8)
	{
		if (bit[i] == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i++;
	}
	free(bit);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		printf("Error: wrong format.\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		send_bit(pid, argv[2][i]);
		i++;
	}
	send_bit(pid, '\n');
	return (0);
}
