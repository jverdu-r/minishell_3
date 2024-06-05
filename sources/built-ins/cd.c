/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:39:42 by davidaparic       #+#    #+#             */
/*   Updated: 2024/06/03 09:36:26 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_dir(t_toolbox *tools, char *arg)
{
	int	i;

	i = 0;
	while (tools->env[i])
	{
		if (ft_strncmp(tools->env[i], arg, ft_strlen(arg)) == 0)
			return (&tools->env[i][5]);
		i++;
	}
	return (0);
}

char	*get_absolute_dir(t_toolbox *tools)
{
	char	*tmp;
	char	*absolute_dir;

	tmp = ft_strjoin(getcwd(NULL, 0), "/");
	absolute_dir = ft_strjoin(tmp, tools->cmd->args[0]);
	free(tmp);
	return (absolute_dir);
}

void	render_env(t_toolbox *tools)
{
	char	*oldpwd;
	char	*pwd;
	char	*current_dir;

	current_dir = getcwd(NULL, 0);
	if (current_dir != NULL)
	{
		free(tools->old_pwd);
		tools->old_pwd = ft_strdup(tools->pwd);
		free(tools->pwd);
		tools->pwd = getcwd(NULL, 0);
		pwd = ft_strjoin("PWD=", tools->pwd);
		oldpwd = ft_strjoin("OLDPWD=", tools->old_pwd);
		check_variable_exist(tools, pwd);
		check_variable_exist(tools, oldpwd);
		free(pwd);
		free(oldpwd);
	}
	free(current_dir);
}

void	print_err(char *str, int c)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(str, 2);
	if (c == 1)
		ft_putstr_fd(": No such file or directory\n", 2);
	else
		ft_putchar_fd('\n', 2);
}

int	ft_cd(t_toolbox *tools)
{
	char	*dir;
	int		dir_status;

	dir_status = 0;
	if (!tools->cmd->args)
	{
		dir = get_env_dir(tools, "HOME=");
		if (!dir || chdir(dir) == -1)
			return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
		else
			render_env(tools);
	}
	else if (!tools->cmd->args[1])
	{
		dir_status = chdir(tools->cmd->args[0]);
		if (dir_status == -1)
			return (print_err(tools->cmd->args[0], 1), 1);
		else
			render_env(tools);
	}
	else
		return (print_err("too many arguments", 0), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
