/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:18:46 by etravers          #+#    #+#             */
/*   Updated: 2023/02/14 19:18:48 by etravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	ft_print_c(char c)
{
	return (printf_putchar_fd(c, 1));
}

int	ft_print_s(char *c)
{
	if (!c)
	{
		return (printf_putstr_fd("(null)", 1));
	}
	else
	{
		return (printf_putstr_fd(c, 1));
	}
}

int	ft_print_p(unsigned long int ptr, int fd)
{
	int	n_char;

	n_char = 0;
	if (!ptr)
	{
		return (printf_putstr_fd("(nil)", fd));
	}
	n_char = printf_putstr_fd("0x", 1);
	n_char += ft_putnbr_basep_fd(ptr, fd, "0123456789abcdef");
	return (n_char);
}
