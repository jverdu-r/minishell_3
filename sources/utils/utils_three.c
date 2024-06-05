/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:28:52 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/21 16:35:47 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_exit_status;

void	print_err_token(char *c, int len)
{
	char	*aux;

	ft_putstr_fd("minishell: sintax error near ", 2);
	ft_putstr_fd("unexpected token '", 2);
	if (c[len - 1] == c[len])
	{
		aux = ft_substr(c, len - 1, 2);
		ft_putstr_fd(aux, 2);
		ft_putstr_fd("'\n", 2);
	}
	else
	{
		aux = ft_substr(c, len, 1);
		ft_putstr_fd(aux, 2);
		ft_putstr_fd("'\n", 2);
	}
	free(aux);
	g_exit_status = 2;
}
