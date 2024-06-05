/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:32:32 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/27 03:29:26 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_exit_status;

int	error_msg(char *msg)
{
	printf("ERROR: %s", msg);
	return (-1);
}

int	error_token(t_token token)
{
	ft_putstr_fd("minishell: sintax error near", 2);
	ft_putstr_fd(" unexpected token ", 2);
	if (token == PIPE)
		ft_putstr_fd("'|'\n", 2);
	if (token == LESS)
		ft_putstr_fd("'<'\n", 2);
	if (token == LESS_LESS)
		ft_putstr_fd("'<<'\n", 2);
	if (token == GREAT)
		ft_putstr_fd("'>'\n", 2);
	if (token == GREAT_GREAT)
		ft_putstr_fd("'>>'\n", 2);
	g_exit_status = 2;
	return (-1);
}
