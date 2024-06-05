/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:37:01 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/29 10:08:38 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft/libft.h"
# include "tokens.h"
# include "structs.h"
# include "minishell.h"

void	lexer_addback(t_lexer **head, t_lexer *new);
void	lexer_add(t_lexer **head, t_lexer *new);
void	lexer_delone(t_lexer **list);
void	lexer_free(t_lexer *list);
int		lexer_length(t_lexer *list);
int		*init_ct(int cr);
t_lexer	*lexer_new(char	*str, t_token token);
t_lexer	*lexer_last(t_lexer *list);
#endif
