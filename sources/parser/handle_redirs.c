/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:22:42 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/06/06 09:51:34 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_exit_status;

void	redis_error(char *str, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(msg, 2);
	g_exit_status = 1;
}

int	check_in_fd_2(t_redir *in_files)
{
	if (access(in_files->file, R_OK) == -1)
	{
		if (errno == EACCES)
			redis_error(in_files->file, ": Permission denied");
		else if (errno == ENOENT)
			redis_error(in_files->file, ": No such file or directory");
		else
			redis_error(in_files->file, ": Access error");
		return (-1);
	}
	return (0);
}

int	check_in_fd(t_redir *redir, char **env)
{
	t_redir	*in_files;

	in_files = redir;
	while (in_files)
	{
		if (!check_rd_str(in_files, env))
		{
			if (check_in_fd_2(in_files) < 0)
				return (-1);
			if (in_files->next)
				in_files = in_files->next;
		}
		else
			break ;
	}
	return (open(in_files->file, O_RDONLY));
}

int	check_out_fd(t_command *cmd, char **env)
{
	t_redir	*out_files;

	out_files = cmd->out_files;
	while (out_files)
	{
		if (!check_rd_str(out_files, env))
			open_rd(out_files, cmd);
		else
		{
			cmd->out_fd = 1;
			return (1);
		}
		out_files = out_files->next;
	}
	return (0);
}

int	get_fds(t_toolbox *tools, char **env)
{
	t_command	*cmd;

	cmd = tools->cmd;
	while (cmd)
	{
		if (cmd && cmd->in_files)
			cmd->in_fd = check_in_fd(cmd->in_files, env);
		if (cmd && cmd->in_fd == -1 && !cmd->next)
			return (1);
		if (cmd && cmd->out_files)
			cmd = check_out_file_cmd(cmd, env);
		if (cmd && cmd->next)
			cmd = cmd->next;
		else
			break ;
	}
	if (!cmd)
	{
		tools->cmd = NULL;
		return (1);
	}
	while (cmd->prev != NULL)
		cmd = cmd->prev;
	tools->cmd = cmd;
	return (0);
}
