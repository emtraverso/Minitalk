/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:36:05 by etravers          #+#    #+#             */
/*   Updated: 2023/02/14 19:33:21 by etravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	*g_data;

void	ft_free(t_data *data)
{
	free(data->str);
	free(data);
	printf("Message sent\n");
	exit(0);
}

void	ft_send_signals(t_data *data)
{
	data->c = (data->str[data->i] >> data->c_bit) & 1;
	if (data->c)
		kill(data->pid, SIGUSR1);
	else
		kill(data->pid, SIGUSR2);
}

void	send(int pid, char *str, t_data *data)
{
	if (pid)
		data->pid = pid;
	if (str)
		data->str = ft_strdup(str);
	if (!data->str[data->i])
	{
		if (send_null(data->pid) == 0)
			ft_free(data);
	}
	if (data->c_bit-- && data->str[data->i])
		ft_send_signals(data);
	if (data->c_bit == 0 && data->str[data->i])
	{
		data->i++;
		data->c_bit = BITS_PER_BYTE;
	}
	return ;
}

void	handler(int sign)
{
	if (sign == SIGUSR1)
		send(0, 0, data);
	else if (sign == SIGUSR2)
	{
		exit(0);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	data = malloc(sizeof(t_data));
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		ft_init(data);
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		send(pid, av[2], data);
		while (1)
			pause();
	}
	else
	{
		write(2, "Error! Invalid input\n", 22);
	}
}
