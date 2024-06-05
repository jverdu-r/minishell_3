/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:21:02 by davidaparic       #+#    #+#             */
/*   Updated: 2024/05/25 18:39:50 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	executor_error(t_command *cmd, char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd->cmd, STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
}

int	ft_lstsize_m(t_command *list)
{
	int			len;
	t_command	*temp;

	len = 0;
	temp = list;
	if (!list)
		return (0);
	while (temp->next != NULL)
	{
		temp = temp->next;
		len++;
	}
	if (temp->next == NULL)
		len++;
	return (len);
}

char	*find_path(char *cmd, char **path)
{
	char	*tmp;
	char	*aux;
	char	*err;

	if (!access(cmd, X_OK))
		return (cmd);
	if (path)
	{
		while (*path)
		{
			aux = ft_strjoin(*path, "/");
			tmp = ft_strjoin(aux, cmd);
			free(aux);
			if (!access(tmp, X_OK))
				return (tmp);
			free(tmp);
			path++;
		}
		err = ft_strjoin(cmd, ": Command not found\n");
		(ft_putstr_fd(err, 2), free(err), exit(127));
	}
	return (NULL);
}

char	**fill_args(t_command *cmd)
{
	char		**n_args;
	t_command	*aux;
	int			i;
	int			j;

	j = 0;
	aux = cmd;
	i = 0;
	if (aux->args)
		while (aux->args[i])
			i++;
	else
		i++;
	n_args = ft_calloc(sizeof(char *), (i + 2));
	n_args[0] = cmd->cmd;
	i = 1;
	if (aux->args)
		while (aux->args[j])
			n_args[i++] = aux->args[j++];
	n_args[i] = NULL;
	return (n_args);
}

char	*find_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}
