/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:19:08 by etravers          #+#    #+#             */
/*   Updated: 2023/02/14 19:19:12 by etravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	ft_putnbr_base_fd_internal(unsigned int nbr, int fd, char *base)
{
	unsigned long int	nb;
	int					n_char;	

	nb = nbr;
	if (nb >= 16)
	{
		n_char = ft_putnbr_base_fd_internal((nb / 16), fd, base);
		n_char += ft_putnbr_base_fd_internal((nb % 16), fd, base);
		return (n_char);
	}
	else
		return (printf_putchar_fd(base[nb], fd));
}

int	ft_putnbr_basex_fd(unsigned int nbr, int fd, int lowercase)
{
	if (lowercase == 1)
		return (ft_putnbr_base_fd_internal(nbr, fd, "0123456789abcdef"));
	else
		return (ft_putnbr_base_fd_internal(nbr, fd, "0123456789ABCDEF"));
}

int	ft_putnbr_baseu_fd(unsigned int nbr, int fd)
{
	unsigned int		nb;
	int					n_char;	

	nb = nbr;
	if (nb >= 10)
	{
		n_char = ft_putnbr_baseu_fd((nb / 10), fd);
		n_char += ft_putnbr_baseu_fd((nb % 10), fd);
		return (n_char);
	}
	else
		return (printf_putchar_fd((nb + '0'), fd));
}

int	ft_putnbr_basep_fd(unsigned long int nbr, int fd, char *base)
{
	unsigned long int	nb;
	int					n_char;

	nb = nbr;
	if (nb >= 16)
	{
		n_char = ft_putnbr_basep_fd((nb / 16), fd, base);
		n_char += ft_putnbr_basep_fd((nb % 16), fd, base);
		return (n_char);
	}
	else
		return (printf_putchar_fd(base[nb], fd));
}
