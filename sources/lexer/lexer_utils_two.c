/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:28:22 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/26 13:54:27 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lexer_length(t_lexer *list)
{
	int			i;
	t_lexer		*aux;

	if (!list)
		return (0);
	aux = list;
	i = 0;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

void	lexer_free(t_lexer *list)
{
	t_lexer	*aux;

	if (list)
	{
		while (list->prev != NULL)
			list = list->prev;
		while (list)
		{
			if (list->token == 0 || list->str)
				free(list->str);
			aux = list;
			if (list->next)
			{
				list = list->next;
				free(aux);
			}
			else
				break ;
		}
		free(list);
	}
}

int	*init_ct(int cr)
{
	int		*ct;

	ct = ft_calloc(sizeof(int), 3);
	ct[0] = 1;
	ct[1] = 1;
	ct[2] = cr;
	return (ct);
}
