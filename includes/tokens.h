/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:45:51 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/26 13:54:17 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include "minishell.h"
# include "structs.h"

t_token			check_token(char *str, int i);
t_command		*init_cmd(void);
void			comm_addback(t_command **head, t_command *new);
void			cmd_free(t_command *cmd);

#endif
