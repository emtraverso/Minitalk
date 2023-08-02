/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:55:37 by etravers          #+#    #+#             */
/*   Updated: 2023/02/14 17:55:39 by etravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include	"printf/ft_printf.h"
# include	"libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# define BITS_PER_BYTE 8

typedef struct s_data
{
	char	c;
	int		c_bit;
	int		pid;
	char	*str;
	int		i;
}	t_data;
int		send_null(int pid);
void	ft_init(t_data *data);

#endif
