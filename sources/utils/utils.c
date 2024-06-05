/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:58:17 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/28 19:27:09 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_exit_status;

char	*get_input(char *str)
{
	int		len;
	int		i;
	char	*res;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	res = ft_calloc(sizeof(char *), len);
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[len] = 0;
	free(str);
	return (res);
}

int	handle_quotes(char *input)
{
	int	qt;
	int	i;
	int	len;

	qt = -1;
	i = 0;
	len = ft_strlen(input);
	while (i < len)
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			qt = i;
			i++;
			while (input[i] != input[qt] && input[i])
				i++;
			if (input[i] == input[qt])
				qt = -1;
		}
		i++;
	}
	if (qt != -1)
	{
		return (error_msg("unclosed quotation mark\n"));
	}
	return (0);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

int	check_input_end(char *c)
{
	int		len;

	len = ft_strlen(c) - 1;
	if (c[len] == '<' || c[len] == '>' || c[len] == '|')
	{
		if (len > 0 && is_white_space(c[len - 1]))
			print_err_token(c, len);
		else
		{
			ft_putstr_fd("minishell: sintax error near", 2);
			ft_putstr_fd(" unexpected token `newline'\n", 2);
		}
		return (0);
	}
	return (1);
}

int	check_input(t_toolbox *tools)
{
	char	*input;

	input = get_input(readline("minishell>"));
	if (!input)
		exit_code(2);
	if (input && ft_strlen(input) >= 1)
	{
		if (!check_input_st(input) || !check_input_end(input))
		{
			add_history(input);
			free(input);
			g_exit_status = 2;
			return (1);
		}
		tools->args = ft_strtrim(input, " ");
		free(input);
		return (1);
	}
	free(input);
	return (0);
}
