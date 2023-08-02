/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:36:34 by etravers          #+#    #+#             */
/*   Updated: 2023/02/13 19:36:35 by etravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_init( t_data *data)
{
	data->pid = 0;
	data->i = 0;
	data->c_bit = BITS_PER_BYTE;
}

int	send_null(int pid)
{
	static int	k = BITS_PER_BYTE;

	if (k-- != 0)
	{
		kill(pid, SIGUSR2);
		return (1);
	}
	return (0);
}
