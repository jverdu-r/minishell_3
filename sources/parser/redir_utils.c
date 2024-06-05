/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:43:17 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/06/05 13:36:18 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_redir	*redir_new(char *str)
{
	t_redir	*new;

	new = ft_calloc(sizeof(t_redir), 1);
	if (!new)
		return (NULL);
	new->file = ft_strdup(str);
	new->next = NULL;
	new->prev = NULL;
	free(str);
	return (new);
}

char	**lim_add(char **limts, int lim, char *str)
{
	char	**nlimts;
	int		i;

	nlimts = ft_calloc(sizeof(char *), (lim + 2));
	i = 0;
	if (limts)
	{
		while (limts[i])
		{
			nlimts[i] = limts[i];
			i++;
		}
		free(limts);
	}
	nlimts[i] = ft_strdup(str);
	nlimts[i + 1] = 0;
	return (nlimts);
}

void	redir_addback(t_redir **head, t_redir *new)
{
	t_redir	*aux;

	aux = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
		new->prev = aux;
	}
}

void	redir_free(t_redir *redir)
{
	while (redir->prev)
		redir = redir->prev;
	while (redir->next)
	{
		if (redir->file)
			free(redir->file);
		redir = redir->next;
		if (redir->prev)
			free(redir->prev);
	}
	free(redir->file);
	free(redir);
}

int	check_void_redir(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!is_white_space(str[i]))
			return (1);
		i++;
	}
	return (0);
}
