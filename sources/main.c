/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:28:15 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/26 15:53:36 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status = 0;

void	leaks(void)
{
	system("leaks minishell");
}

void	shell_up(char **env)
{
	int		i;
	int		lvl;
	char	**aux;
	char	*shlvl;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "SHLVL", 5))
		{
			aux = ft_split(env[i], '=');
			lvl = ft_atoi(aux[1]);
			lvl++;
			free(aux[1]);
			aux[1] = ft_itoa(lvl);
			shlvl = ft_strjoin("SHLVL=", aux[1]);
			free(env[i]);
			env[i] = shlvl;
			free_arr(aux);
		}
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_toolbox	*tools;

	if (argc != 1 || argv[1])
	{
		ft_putstr_fd("Minishell must be executed wihtout arguments\n", 2);
		exit(0);
	}
	tools = ft_calloc(sizeof(t_toolbox), 1);
	tools_load(tools);
	if (envp[0] == NULL)
		tools->env = new_env();
	else
	{
		tools->env = envp_dup(envp, tools);
		shell_up(tools->env);
	}
	pwd_search(tools, tools->env);
	minishell_loop(tools);
	free(tools);
	return (0);
}
