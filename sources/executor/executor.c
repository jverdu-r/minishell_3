/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:53:02 by daparici          #+#    #+#             */
/*   Updated: 2024/06/03 09:35:13 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_exit_status;

void	ft_executor(t_toolbox *tools)
{
	if (tools->cmd)
	{
		if (ft_lstsize_m(tools->cmd) > 1)
			ft_executor_loop(tools->cmd, tools);
		else
		{
			if (ft_is_builtin(tools->cmd) == 0)
				ft_is_builtin_2(tools, tools->cmd);
			else if (ft_is_builtin(tools->cmd) != 0 && tools->cmd->cmd)
				simple_command(tools, tools->cmd);
		}
	}
}

void	ret_exit(void)
{
	if (g_exit_status > 255)
		g_exit_status = g_exit_status / 256;
	if (g_exit_status == 2)
		g_exit_status = 130;
	if (g_exit_status == 256)
		g_exit_status = 1;
}

void	simple_command(t_toolbox *tools, t_command *cmd)
{
	cmd->pid = fork();
	if (cmd->pid < 0)
		(perror("minishell:"), exit(1));
	else if (cmd->pid == 0)
	{
		child_signals();
		manage_dups(cmd, NULL, NULL);
		if (cmd->heredoc && !cmd->args)
		{
			if (dup2(cmd->heredoc, 0) < 0)
				(perror("minishell"), exit(127));
			close(cmd->heredoc);
		}
		manage_params_child(tools, cmd);
	}
	else
	{
		father_workout();
		if (waitpid(cmd->pid, &g_exit_status, 0) == -1)
			(perror("minishell:"), exit(1));
		ret_exit();
	}
}

int	ft_is_builtin(t_command *cmd)
{
	if (cmd)
	{
		if (ft_strcmp(cmd->cmd, "pwd") == 0)
			return (0);
		else if (ft_strcmp(cmd->cmd, "echo") == 0)
			return (0);
		else if (ft_strcmp(cmd->cmd, "env") == 0)
			return (0);
		else if (ft_strcmp(cmd->cmd, "export") == 0)
			return (0);
		else if (ft_strcmp(cmd->cmd, "unset") == 0)
			return (0);
		else if (ft_strcmp(cmd->cmd, "cd") == 0)
			return (0);
		else if (ft_strcmp(cmd->cmd, "exit") == 0)
			return (0);
		else
			return (1);
	}
	return (1);
}

void	ft_is_builtin_2(t_toolbox *tools, t_command *cmd)
{
	if (ft_strcmp(cmd->cmd, "pwd") == 0)
		g_exit_status = ft_pwd();
	else if (ft_strcmp(cmd->cmd, "echo") == 0)
		g_exit_status = ft_echo(cmd);
	else if (ft_strcmp(cmd->cmd, "env") == 0)
		g_exit_status = ft_env(tools->env);
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		g_exit_status = ft_export(tools);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		g_exit_status = ft_unset(tools);
	else if (ft_strcmp(cmd->cmd, "cd") == 0)
		g_exit_status = ft_cd(tools);
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
		g_exit_status = m_exit(tools, cmd);
}
