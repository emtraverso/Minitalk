/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:54:26 by etravers          #+#    #+#             */
/*   Updated: 2023/02/14 19:54:24 by etravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*print_string(char *message)
{
	if (*message)
	{
		ft_putstr_fd(message, 1);
		free(message);
	}
	ft_printf("\nMessage received\n");
	return (NULL);
}

char	*join_char(char c, char *str)
{
	int		i;
	char	*join;

	i = 0;
	if (!*str && c)
	{
		join = malloc(sizeof(char) * 2);
		join[0] = c;
		join[1] = '\0';
		return (join);
	}
	else if (*str && c)
	{
		i = ft_strlen(str);
		join = malloc(sizeof(char) * (i + 2));
		join = ft_memcpy(join, str, i);
		join[i] = c;
		join[i + 1] = '\0';
		free(str);
	}
	else
		return (NULL);
	return (join);
}

void	sigusr(int signal, siginfo_t *info, void *ptr)
{
	static char	c = 0;
	static int	bit = 7;
	static char	*s_str = "\0";

	(void) ptr;
	(void) info;
	if (signal == SIGUSR1)
		c = (c << 1) | 1;
	if (signal == SIGUSR2)
		c = (c << 1) | 0;
	if (bit-- == 0)
	{
		bit = 7;
		if (c)
			s_str = join_char(c, s_str);
		else
		{
			print_string(s_str);
			s_str = "\0";
		}
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			mask;
	int					pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sigusr;
	sigemptyset(&mask);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
