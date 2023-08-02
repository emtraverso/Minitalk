/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:19:22 by etravers          #+#    #+#             */
/*   Updated: 2023/02/14 19:19:25 by etravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putnbr_fd(int nb, int fd)
{
	int	nbr;
	int	n_char;

	if (nb < 0)
	{
		printf_putchar_fd('-', fd);
		nbr = (unsigned int)(nb * -1);
		n_char = 1;
	}
	else
	{
		nbr = (unsigned int)nb;
		n_char = 0;
	}
	n_char += ft_putnbr_baseu_fd(nbr, fd);
	return (n_char);
}
