/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:22:42 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/06/05 19:07:21 by jverdu-r         ###   ########.fr       */
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
		{
			if (cmd->app == 1)
				cmd->out_fd = open(out_files->file, O_WRONLY | O_APPEND | \
					O_CREAT, 0644);
			else
				cmd->out_fd = open(out_files->file, O_CREAT | O_WRONLY | \
					O_TRUNC, 0644);
		}
		else
			return (close(cmd->out_fd), 1);
		if (out_files->next)
			close(cmd->out_fd);
		if (out_files->next)
			out_files = out_files->next;
		else
			break ;
	}
	return (0);
}

int	get_fds(t_command *raw_cmd, char **env)
{
	t_command	*cmd;

	cmd = raw_cmd;
	while (cmd)
	{
		if (cmd && cmd->in_files)
			cmd->in_fd = check_in_fd(cmd->in_files, env);
		if (cmd && cmd->in_fd == -1 && !cmd->next)
			return (1);
		if (cmd && cmd->out_files)
		{
			if (check_void_redir(cmd->out_files->file))
			{
				if (check_out_fd(cmd, env))
					cmd = cmd->next;
			}
			else
				cmd = cmd->next;
		}
		if (cmd)
			cmd = cmd->next;
	}
	return (0);
}
