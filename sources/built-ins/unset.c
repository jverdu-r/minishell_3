/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:50:15 by daparici          #+#    #+#             */
/*   Updated: 2024/05/28 20:04:35 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_equal(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
		{
			export_error(arg);
			return (1);
		}
		i++;
	}
	return (0);
}

void	del_var(t_toolbox *tools, int i, int j)
{
	char	**tmp;

	if (!ft_strncmp(tools->env[j], tools->cmd->args[i], \
			lenght_to_equal(tools->cmd->args[i])))
	{
		if ((int)ft_strlen(tools->cmd->args[i]) \
			== lenght_to_equal(tools->env[j]))
		{
			tmp = delete_variable(tools->env, j);
			free_arr(tools->env);
			tools->env = tmp;
		}
	}
}

int	check_pmt_unset(char *cmd_arg)
{
	int	i;

	i = 0;
	if (cmd_arg[i] == '=')
		return (1);
	while (cmd_arg[i] != '=' && cmd_arg[i])
	{
		if (ft_isdigit(cmd_arg[0]) || !cmd_arg[0])
			return (1);
		if ((cmd_arg[i] != '_') && (ft_isalnum(cmd_arg[i]) == 0))
			return (1);
		i++;
	}
	return (0);
}

int	ft_unset(t_toolbox *tools)
{
	int		i;
	int		j;

	i = 0;
	if (tools->cmd->args)
	{
		while (tools->cmd->args[i])
		{
			j = 0;
			while (tools->env[j])
			{
				if (!check_pmt_unset(tools->cmd->args[i]) && \
					!ft_check_equal(tools->cmd->args[i]))
					del_var(tools, i, j);
				else
					break ;
				j++;
			}
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

char	**delete_variable(char **env, int i)
{
	char	**env_copy;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (env[j])
		j++;
	env_copy = ft_calloc(sizeof(char *), j + 1);
	if (!env_copy)
		return (NULL);
	j = 0;
	while (env[j])
	{
		if (j == i)
			j++;
		else
			env_copy[k++] = ft_strdup(env[j++]);
	}
	return (env_copy);
}
