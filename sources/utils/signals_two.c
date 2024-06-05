/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:58:49 by jorge             #+#    #+#             */
/*   Updated: 2024/05/10 16:56:43 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	println(int sig)
{
	(void)sig;
	printf("\n");
	exit(0);
}

void	sig_heredoc(void)
{
	signal(SIGINT, println);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_ignire(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}
