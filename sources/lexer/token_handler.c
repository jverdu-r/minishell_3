/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:40:51 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/18 13:45:26 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	check_token(char *tk, int i)
{
	if (tk[i] == '|')
		return (PIPE);
	if (tk[i] == '<')
	{
		if (tk[i + 1] && tk[i + 1] == '<')
			return (LESS_LESS);
		else
			return (LESS);
	}
	if (tk[i] == '>')
	{
		if (tk[i + 1] && tk[i + 1] == '>')
			return (GREAT_GREAT);
		else
			return (GREAT);
	}
	return (0);
}

int	token_handler(t_toolbox *tools, int i)
{
	t_token	tk;

	tk = check_token(tools->args, i);
	if (tk == LESS_LESS || tk == GREAT_GREAT)
	{
		lexer_addback(&tools->lexer_list, lexer_new(NULL, tk));
		return (2);
	}
	if (tk == PIPE || tk == LESS || tk == GREAT)
	{
		lexer_addback(&tools->lexer_list, lexer_new(NULL, tk));
		return (1);
	}
	return (0);
}
