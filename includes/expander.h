/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:59:56 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/29 10:01:42 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "libft/libft.h"
# include "structs.h"
# include "minishell.h"

char	*charjoin(char *str, char c);
char	*var_find(char *str, int i, char **env);
char	*trimmed(char *str, int i, int j);
int		ovarpass(char *str, int i);
char	*expnd(char *str, char **env);
char	*var_exp(char *str, char *aux, int i, char **env);
int		ft_exp_stop(char c);
char	*get_exp_value(char *str);
char	*expander(char *str, char **env, int i);
int		check_next(char *str, int i, char c);
#endif