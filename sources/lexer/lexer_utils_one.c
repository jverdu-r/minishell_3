/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:21:42 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/10 15:41:42 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_lexer	*lexer_new(char	*str, t_token token)
{
	t_lexer	*new;

	new = ft_calloc(sizeof(t_lexer), 1);
	if (!new)
		return (NULL);
	new->token = token;
	new->str = str;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_lexer	*lexer_last(t_lexer *list)
{
	t_lexer	*tmp;

	if (!list)
		return (NULL);
	tmp = list;
	while (tmp->next)
	{
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (tmp);
}

void	lexer_delone(t_lexer **list)
{
	if (list && *list)
	{
		if (lexer_length(*list) > 1)
		{
			list[0] = list[0]->next;
			free(list[0]->prev);
			list[0]->prev = NULL;
		}
		else
		{
			free(list[0]);
			list[0] = NULL;
		}
	}
}

void	lexer_add(t_lexer **head, t_lexer *new)
{
	t_lexer	*tmp;

	tmp = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		new->next = tmp;
		new->index = tmp->index + 1;
		tmp->prev = new;
		tmp = new;
		*head = tmp;
	}
}

void	lexer_addback(t_lexer **head, t_lexer *new)
{
	t_lexer	*tmp;

	if (ft_strlen(new->str) > 0 || new->token > 0)
	{
		tmp = *head;
		if (*head == NULL)
			*head = new;
		else
		{
			tmp = lexer_last(tmp);
			tmp->next = new;
			new->index = tmp->index + 1;
			new->prev = tmp;
		}
	}
	else
	{
		free(new->str);
		free(new);
	}
}
