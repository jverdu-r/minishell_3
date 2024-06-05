/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:33:17 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/28 19:56:30 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pwd_search(t_toolbox *tools, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && ft_strnstr(envp[i], "PWD=", 4) != 0)
			tools->pwd = ft_substr(envp[i],
					4, ft_strlen(envp[i]) - 4);
		if (envp[i][0] == 'O' && ft_strnstr(envp[i], "OLDPWD=", 7))
			tools->old_pwd = ft_substr(envp[i],
					7, ft_strlen(envp[i]) - 7);
		if (envp[i][0] == 'H' && ft_strnstr(envp[i], "HOME=", 5))
			tools->home_dir = ft_substr(envp[i],
					5, ft_strlen(envp[i]) - 5);
		i++;
	}
	return (i);
}

char	**new_env(void)
{
	char	**env;
	char	*aux;

	aux = getcwd(NULL, 0);
	env = ft_calloc(sizeof(char *), 6);
	env[0] = ft_strjoin("PWD=", aux);
	env[1] = ft_strdup("OLDPWD");
	env[2] = ft_strdup("SHLVL=1");
	env[3] = ft_strdup("_=/usr/bin/env");
	env[4] = ft_strdup("PATH=/usr/local/sbin:/usr/local/bin:\
/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	env[5] = 0;
	free(aux);
	return (env);
}

char	**st_envp(char **envp)
{
	char	**sorted;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	sorted = ft_calloc(sizeof(char *), i + 1);
	if (!sorted)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		sorted[i] = envp[i];
		i++;
	}
	sorted[i] = 0;
	sorted = sort_arr(sorted);
	return (sorted);
}

char	**envp_dup(char	**envp, t_toolbox *tools)
{
	char	**tmp;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	tmp = ft_calloc(sizeof(char *), i + 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		tmp[i] = ft_strdup(envp[i]);
		if (!tmp[i])
		{
			free_arr(tmp);
			return (NULL);
		}
		i++;
	}
	tmp[i] = 0;
	tools->env = tmp;
	return (tmp);
}
