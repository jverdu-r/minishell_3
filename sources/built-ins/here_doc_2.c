/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:45:25 by daparici          #+#    #+#             */
/*   Updated: 2024/05/24 13:57:17 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_exit_status;

int	ft_strncmp_2(const char *s1, const char *s2, size_t n)
{
	size_t			a;

	a = 0;
	while (a <= n)
	{
		if (((unsigned char *)s1)[a] != ((unsigned char *)s2)[a])
			return (((unsigned char *)s1)[a] - ((unsigned char *)s2)[a]);
		if (s1[a] == 0)
			return (0);
		a++;
	}
	return (0);
}

int	expander_hdoc_2(char *str, int i)
{
	i++;
	while (str[i] && ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0'
				&& str[i] <= '9') || str[i] == '_' || str[i] == '?'))
		i++;
	return (i);
}

char	*expander_hdoc_3(char *str, char **env, char *expand_str, int i)
{
	char	*variable;
	char	*copy_ex_str;
	char	*aux;

	copy_ex_str = ft_strdup(expand_str);
	free(expand_str);
	if (str[i + 1] == '?')
		aux = ft_itoa(g_exit_status);
	else
	{
		variable = find_variable(str, i + 1);
		aux = check_env(variable, env);
		free(variable);
	}
	expand_str = ft_strjoin(copy_ex_str, aux);
	free(aux);
	free(copy_ex_str);
	return (expand_str);
}

char	*expander_hdoc(char *str, char **env)
{
	int				i;
	char			*expand_str;
	char			*copy_ex_str;
	char			*aux;

	i = 0;
	expand_str = ft_strdup("");
	while (str[i])
	{
		if (str[i] && str[i] == '$' && !ft_exp_stop(str[i + 1]))
		{
			copy_ex_str = expand_str;
			expand_str = expander_hdoc_3(str, env, copy_ex_str, i);
			i = expander_hdoc_2(str, i);
		}
		else
		{
			copy_ex_str = expand_str;
			aux = ft_substr(str, i, 1);
			expand_str = ft_strjoin(copy_ex_str, aux);
			(free(copy_ex_str), free(aux), i++);
		}
	}
	return (expand_str);
}
