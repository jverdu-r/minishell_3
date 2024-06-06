/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirs_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:10:40 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/06/06 09:56:22 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	open_rd(t_redir *out, t_command *cmd)
{
	if (cmd->app == 1)
		cmd->out_fd = open(out->file, O_WRONLY | O_APPEND | \
			O_CREAT, 0644);
	else
		cmd->out_fd = open(out->file, O_CREAT | O_WRONLY | \
			O_TRUNC, 0644);
	if (out->next)
		close(cmd->out_fd);
}

t_command	*check_out_file_cmd(t_command *cmd, char **env)
{
	if (check_void_redir(cmd->out_files->file))
	{
		if (check_out_fd(cmd, env))
			cmd = skip_cmd(cmd);
	}
	else
		cmd = cmd->next;
	return (cmd);
}
