/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:23:21 by davidaparic       #+#    #+#             */
/*   Updated: 2024/05/28 19:50:51 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_exit_status;

void	ft_executor_loop(t_command *cmd, t_toolbox *tools)
{
	int			ac_pipe[2];
	t_command	*cmd_aux;

	cmd_aux = cmd;
	pipe(ac_pipe);
	recursive_ex(ac_pipe, cmd_aux, tools);
	close(ac_pipe[0]);
	close(ac_pipe[1]);
	father_workout();
	while (cmd_aux)
	{
		if (waitpid(cmd_aux->pid, &g_exit_status, 0) == -1)
			(perror("minishell:"), exit(1));
		if (cmd_aux->next)
			cmd_aux = cmd_aux->next;
		else
			break ;
	}
	ret_exit();
}

void	recursive_ex(int *pre_pipe, t_command *cmd, t_toolbox *tools)
{
	int		ac_pipe[2];

	pipe(ac_pipe);
	cmd->pid = fork();
	if (cmd->pid < 0)
		(perror("minishell:"), exit(1));
	else if (cmd->pid == 0)
	{
		child_signals();
		heredoc_child(pre_pipe, ac_pipe, cmd);
		if (ft_is_builtin(cmd) == 0)
			(ft_is_builtin_2(tools, cmd), exit(0));
		else
			manage_params_child(tools, cmd);
	}
	else
	{
		if (cmd->next)
		{
			(close(pre_pipe[0]), close(pre_pipe[1]));
			recursive_ex(ac_pipe, cmd->next, tools);
			(close(ac_pipe[0]), close(ac_pipe[1]));
		}
	}
}

void	manage_dups(t_command *cmd, int *pre_pipe, int *ac_pipe)
{
	if (cmd->prev)
	{
		if (dup2(pre_pipe[0], 0) < 0)
			(perror("minishell:"), exit(1));
		close(pre_pipe[0]);
	}
	if (cmd->next)
	{
		if (dup2(ac_pipe[1], 1) < 0)
			(perror("minishell:"), exit(1));
		close(ac_pipe[1]);
	}
	if (cmd->in_fd > 2)
	{
		if (dup2(cmd->in_fd, 0) < 0)
			(perror("minishell:"), exit(1));
		close(cmd->in_fd);
	}
	if (cmd->out_fd > 2 && ft_strcmp("echo", cmd->cmd))
	{
		if (dup2(cmd->out_fd, 1) < 0)
			(perror("minishell:"), exit(1));
		close(cmd->out_fd);
	}
}

void	manage_params_child(t_toolbox *tools, t_command *cmd)
{
	char	**cmd_arg;
	char	*cmd_rute;
	char	**path_rutes;
	char	*path_rute;

	cmd_arg = fill_args(cmd);
	if (!cmd_arg)
		(executor_error(cmd, "error in arguments"), exit(1));
	if (!access(cmd->cmd, X_OK))
		if (execve(cmd->cmd, cmd_arg, tools->env) < 0)
			(executor_error(cmd, "execve error"), exit(1));
	path_rute = find_paths(tools->env);
	if (!path_rute)
		(executor_error(cmd, ": no such file or directory"), exit(127));
	path_rutes = ft_split((char const *)path_rute, ':');
	if (!path_rutes)
		(executor_error(cmd, "path rutes error"), exit(1));
	cmd_rute = find_path(cmd->cmd, path_rutes);
	if (!cmd_rute)
		(executor_error(cmd, "no such rute command"), exit(1));
	if (execve(cmd_rute, cmd_arg, tools->env) < 0)
		(executor_error(cmd, "execve error"), exit(1));
}

void	heredoc_child(int *pre_p, int *ac_p, t_command *cmd)
{
	(close(pre_p[1]), close(ac_p[0]));
	if (!cmd->prev)
		close(pre_p[0]);
	if (!cmd->next)
		close(ac_p[1]);
	manage_dups(cmd, pre_p, ac_p);
	if (cmd->heredoc && !cmd->args)
	{
		if (dup2(cmd->heredoc, 0) < 0)
			(perror("minishell"), exit(1));
		close(cmd->heredoc);
	}
}
