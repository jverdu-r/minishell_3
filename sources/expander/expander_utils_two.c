/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:55:50 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/29 09:59:38 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ovarpass(char *str, int i)
{
	while (str[i] == '$')
		i++;
	while (str[i])
	{
		if (ft_exp_stop(str[i]))
			break ;
		i++;
	}
	i--;
	return (i);
}

char	*expnd(char *str, char **env)
{
	int		i;
	char	*aux;

	aux = ft_strjoin(str, "=");
	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], aux, ft_strlen(aux)))
		{
			free(aux);
			aux = get_exp_value(env[i]);
			free(str);
			return (aux);
		}
		i++;
	}
	free(aux);
	if (ft_strlen(str) == 0)
		aux = ft_strjoin(str, "$");
	else
		aux = ft_calloc(sizeof(char), 1);
	free(str);
	return (aux);
}

int	check_next(char *str, int i, char c)
{
	if (c == '\"')
	{
		i++;
		while (str[i] && str[i] != '\"')
			i++;
		return (i);
	}
	if (c == '\'')
	{
		i++;
		while (str[i] && str[i] != '\'')
			i++;
		return (i);
	}
	else
	{
		while (str[i])
		{
			if (str[i] == '\"' || str[i] == '\'')
				break ;
			i++;
		}
		return (i);
	}
}

char	*var_exp(char *str, char *aux, int i, char **env)
{
	char	*exp;
	char	*res;

	if (str[i + 1] == '\"' || is_white_space(str[i + 1]))
		res = charjoin(aux, str[i]);
	else
	{
		while (str[i])
		{
			if (str[i] == '$')
				i++;
			else
				break ;
		}
		exp = var_find(str, i, env);
		res = ft_strjoin(aux, exp);
		free(aux);
		free(exp);
	}
	return (res);
}
