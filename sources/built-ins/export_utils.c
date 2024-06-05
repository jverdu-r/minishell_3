/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:52:40 by daparici          #+#    #+#             */
/*   Updated: 2024/05/30 19:21:24 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	export_error(char *cmd_arg)
{
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	ft_putchar_fd('\'', STDERR_FILENO);
	ft_putstr_fd(cmd_arg, STDERR_FILENO);
	ft_putchar_fd('\'', STDERR_FILENO);
	ft_putendl_fd(" : not a valid identifier", STDERR_FILENO);
}

int	lenght_to_equal(char *cmd_arg)
{
	int	i;

	i = 0;
	while (cmd_arg[i] && cmd_arg[i] != '=')
		i++;
	return (i);
}

int	check_variable_exist(t_toolbox *tools, char *cmd_arg)
{
	int	i;

	i = 0;
	while (tools->env[i])
	{
		if (!ft_strncmp(tools->env[i], cmd_arg, lenght_to_equal(cmd_arg))
			&& (lenght_to_equal(cmd_arg) == lenght_to_equal(tools->env[i])))
		{
			if (!cmd_arg[lenght_to_equal(cmd_arg)])
				return (1);
			free(tools->env[i]);
			tools->env[i] = ft_strdup(cmd_arg);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_parametres(char *cmd_arg)
{
	int	i;

	i = 0;
	if (cmd_arg[i] == '=')
	{
		export_error(cmd_arg);
		return (1);
	}
	while (cmd_arg[i] != '=' && cmd_arg[i])
	{
		if (ft_isdigit(cmd_arg[0]) || !cmd_arg[0])
		{
			export_error(cmd_arg);
			return (1);
		}
		if ((cmd_arg[i] != '_') && (ft_isalnum(cmd_arg[i]) == 0))
		{
			export_error(cmd_arg);
			return (1);
		}
		i++;
	}
	return (0);
}
