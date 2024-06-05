/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:06:57 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/30 17:32:57 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*expand(char *str, int i, char **env)
{
	char	*aux;
	char	*res;

	res = ft_strdup("");
	i++;
	while (str[i] && str[i] != '\"')
	{
		aux = res;
		if (str[i] == '$' && str[i + 1])
		{
			res = var_exp(str, aux, i, env);
			i = ovarpass(str, i);
		}
		else
			res = charjoin(aux, str[i]);
		i++;
	}
	return (res);
}

char	*noqt(char *str, int i, char **env)
{
	char	*aux;
	char	*res;

	res = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			break ;
		aux = res;
		if (str[i] == '$' && str[i + 1])
		{
			res = var_exp(str, aux, i, env);
			i = ovarpass(str, i);
		}
		else
			res = charjoin(aux, str[i]);
		i++;
	}
	return (res);
}

char	*extract(char *str, int i)
{
	int		j;
	char	*res;

	j = i + 1;
	while (str[j] && str[j] != '\'')
		j++;
	j--;
	res = ft_substr(str, i + 1, j - i);
	return (res);
}

char	*quoted(char *str, int i, char **env)
{
	char	*res;

	res = NULL;
	if (str[i] == '\'')
		res = extract(str, i);
	else if (str[i] == '\"')
		res = expand(str, i, env);
	return (res);
}

char	*expander(char *str, char **env, int i)
{
	char	*aux;
	char	*res;
	char	*exp;

	res = ft_strdup("");
	while (str[i])
	{
		aux = res;
		if (str[i] && (str[i] == '\"' || str[i] == '\''))
		{
			exp = quoted(str, i, env);
			i = check_next(str, i, str[i]);
			res = ft_strjoin(aux, exp);
			(free(aux), free(exp), i++);
		}
		else if (str[i] && str[i] != '\'' && str[i] != '\"')
		{
			exp = noqt(str, i, env);
			i = check_next(str, i, 'c');
			res = ft_strjoin(aux, exp);
			(free(aux), free(exp));
		}
	}
	return (res);
}
