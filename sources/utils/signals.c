/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:52:14 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/15 18:10:08 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_exit_status;

static void	signal_int(int code)
{
	(void)code;
	g_exit_status = 130;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	signal_father(int code)
{
	(void)code;
	if (code == SIGINT)
		printf("\n");
	else
	{
		g_exit_status = 131;
		printf("Quit: 3\n");
	}
}

void	father_workout(void)
{
	signal(SIGQUIT, signal_father);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGINT, signal_father);
}

void	signals_workout(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGINT, signal_int);
}

void	child_signals(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGCHLD, SIG_DFL);
	signal(SIGINT, signal_int);
}
