/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:38:55 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/06/05 17:56:01 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_command	*cmd_list(t_lexer *list)
{
	t_command	*cmd;
	t_lexer		*aux;

	cmd = NULL;
	aux = list;
	while (aux)
	{
		if (aux->prev == NULL || aux->prev->token == PIPE)
			comm_addback(&cmd, init_cmd());
		aux = aux->next;
	}
	while (cmd->prev != NULL)
		cmd = cmd->prev;
	return (cmd);
}

t_lexer	*redir_add(t_command *cmd, t_lexer *list)
{
	if (list->token == LESS)
		redir_addback(&cmd->in_files, \
			redir_new(ft_strdup(list->next->str)));
	if (list->token == GREAT || list->token == GREAT_GREAT)
	{
		redir_addback(&cmd->out_files, \
			redir_new(ft_strdup(list->next->str)));
		if (list->token == GREAT_GREAT)
			cmd->app = 1;
		else
			cmd->app = 0;
	}
	if (list->token == LESS_LESS)
	{
		cmd->limiter = lim_add(cmd->limiter, \
			cmd->heredoc, list->next->str);
		cmd->heredoc++;
	}
	list = list->next;
	return (list);
}

t_lexer	*get_arg(t_command *cmd, t_lexer *list, char **env)
{
	char	*exp;

	if (ft_strlen(list->str) > 0)
	{
		exp = expander(list->str, env, 0);
		if (ft_strlen(exp) == 0)
		{
			free(exp);
			return (list);
		}
	}
	else
		exp = ft_strdup("");
	cmd->args = malloc(sizeof(char *) * 2);
	if (!cmd->args)
		cmd->args = NULL;
	cmd->args[0] = exp;
	cmd->args[1] = 0;
	return (list);
}

t_lexer	*get_new_arg(t_command *cmd, t_lexer *list, char **env)
{
	char	**aux;
	char	*exp;

	if (ft_strlen(list->str) > 0)
	{
		exp = expander(list->str, env, 0);
		if (ft_strlen(exp) == 0)
		{
			free(exp);
			return (list);
		}
	}
	else
		exp = ft_strdup("");
	aux = cp_ad_args(cmd->args, exp);
	cmd->args = aux;
	return (list);
}

t_command	*parser(t_toolbox *tools)
{
	t_lexer		*aux;
	t_command	*cmd;

	aux = tools->lexer_list;
	cmd = cmd_list(aux);
	while (aux)
	{
		if (aux->token == PIPE)
			cmd = cmd->next;
		else if (aux->token > 1)
			aux = redir_add(cmd, aux);
		else
			aux = extract_str(cmd, aux, tools->env);
		if (aux)
			aux = aux->next;
	}
	while (cmd->prev)
		cmd = cmd->prev;
	return (cmd);
}
