/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:48:17 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/06/06 09:58:08 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_command	*init_cmd(void)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	cmd->cmd = NULL;
	cmd->heredoc = 0;
	cmd->app = 0;
	cmd->append = NULL;
	cmd->limiter = NULL;
	cmd->args = NULL;
	cmd->in_fd = 0;
	cmd->in_files = NULL;
	cmd->out_fd = 1;
	cmd->out_files = NULL;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

void	comm_addback(t_command **head, t_command *new)
{
	t_command	*aux;

	aux = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
		new->prev = aux;
	}
}

void	scmd_free(t_command *cmd)
{
	cmd->out_fd = 0;
	cmd->in_fd = 0;
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->args)
		free_arr(cmd->args);
	if (cmd->limiter)
		free_arr(cmd->limiter);
	if (cmd->append)
		free(cmd->append);
	if (cmd->in_files != NULL)
		redir_free(cmd->in_files);
	if (cmd->out_files != NULL)
		redir_free(cmd->out_files);
	free(cmd);
}

void	cmd_free(t_command *cmd)
{
	if (cmd)
	{
		while (cmd->next)
		{
			cmd = cmd->next;
			scmd_free(cmd->prev);
			cmd->prev = NULL;
		}
		scmd_free(cmd);
	}
}

t_command	*skip_cmd(t_command *cmd)
{
	t_command	*prev;
	t_command	*next;

	prev = cmd->prev;
	next = cmd->next;
	if (cmd->next)
	{
		cmd = next;
		scmd_free(cmd->prev);
		cmd->prev = prev;
		if (cmd->prev)
			cmd->prev->next = cmd;
	}
	else if (!cmd->next && cmd->prev)
	{
		while (cmd->prev)
			cmd = cmd->prev;
		cmd_free(cmd);
		cmd = NULL;
	}
	return (cmd);
}
