/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:44:34 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/24 08:53:18 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exit_num_err(t_toolbox *tools)
{
	ft_putstr_fd("bash: exit: hola: numeric argument required\n", 2);
	free(tools->old_pwd);
	free(tools->home_dir);
	free(tools->pwd);
	free_arr(tools->env);
	tools_reload(tools);
	free(tools);
	return (exit_code(2));
}

int	exit_clear(t_toolbox *tools, int ex)
{
	free(tools->old_pwd);
	free(tools->home_dir);
	free(tools->pwd);
	free_arr(tools->env);
	tools_reload(tools);
	free(tools);
	return (exit_code(ex));
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	get_code(int code)
{
	if (code > 255)
		code = code % 256;
	else if (code < 0)
		code = (code + 256) % 256;
	return (code);
}

int	m_exit(t_toolbox *tools, t_command *cmd)
{
	int	code;

	if (cmd->args)
	{
		if (cmd->args[1])
		{
			ft_putstr_fd("exit\n", 2);
			ft_putstr_fd("bash: exit: too many arguments\n", 2);
			return (1);
		}
		else
		{
			if (!check_num(cmd->args[0]))
			{
				code = ft_atoi(cmd->args[0]);
				code = get_code(code);
				return (exit_clear(tools, code));
			}
			else
				return (exit_num_err(tools));
		}
	}
	return (exit_clear(tools, 0));
}
