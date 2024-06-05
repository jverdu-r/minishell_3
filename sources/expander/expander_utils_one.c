/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:21:11 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/29 09:58:12 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_exit_status;

char	*trimmed(char *str, int i, int j)
{
	char	c;
	char	*res;

	res = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i];
			i++;
			while (str[i] && str[i] != c)
				res[j++] = str[i++];
			i++;
		}
		else
		{
			res[j] = str[i];
			i++;
			j++;
		}
	}
	res[j] = 0;
	return (res);
}

char	*var_find(char *str, int i, char **env)
{
	char	*aux;
	char	*res;

	aux = ft_calloc(sizeof(char), 1);
	aux[0] = 0;
	res = NULL;
	while (str[i] && (ft_isalpha(str[i]) || str[i] == '_' || \
		ft_isdigit(str[i]) || str[i] == '?'))
	{
		res = charjoin(aux, str[i]);
		aux = res;
		i++;
	}
	if (res && res[0] == '?')
	{
		res = ft_itoa(g_exit_status);
		i = 0;
		while (aux[i++])
			res = charjoin(res, aux[i]);
		free(aux);
	}
	else
		res = expnd(aux, env);
	return (res);
}

char	*charjoin(char *str, char c)
{
	char	*res;
	int		len;
	int		i;

	len = ft_strlen(str);
	res = ft_calloc(sizeof(char), len + 2);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = 0;
	free(str);
	return (res);
}

char	*get_exp_value(char *str)
{
	int		i;
	char	*value;

	i = 0;
	while (str && str[i] != '=')
		i++;
	value = ft_substr(str, i + 1, ft_strlen(str) - 1);
	return (value);
}

int	ft_exp_stop(char c)
{
	if (c == '_' || c == '?' || \
		ft_isalpha(c) || ft_isdigit(c))
		return (0);
	else
		return (1);
}
