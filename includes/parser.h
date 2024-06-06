/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:40:45 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/06/06 09:56:35 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft/libft.h"
# include "tokens.h"
# include "structs.h"
# include "minishell.h"

t_command	*parser(t_toolbox *tools);
int			token_reader(t_toolbox *tools);
int			token_handler(t_toolbox *tools, int i);
char		*fully_prompt(char *input, char c);
char		*get_input(char *str);
t_redir		*redir_new(char *str);
void		redir_addback(t_redir **head, t_redir *new);
void		redir_free(t_redir *redir);
void		cmd_free(t_command *cmd);
void		scmd_free(t_command *cmd);
int			get_fds(t_toolbox *tools, char **env);
char		**lim_add(char **limts, int lim, char *str);
char		*get_home(void);
int			check_input_st(char *str);
int			is_white_space(char c);
t_lexer		*get_cmd(t_command *cmd, t_lexer *list, char **env);
t_lexer		*get_new_arg(t_command *cmd, t_lexer *list, char **env);
t_lexer		*get_arg(t_command *cmd, t_lexer *list, char **env);
t_lexer		*extract_str(t_command *cmd, t_lexer *aux, char **env);
char		**cp_ad_args(char **args, char *str);
int			check_rd_str(t_redir *list, char **env);
int			bad_redir(char *str);
int			check_void_redir(char *str);
t_command	*skip_cmd(t_command *cmd);

void		open_rd(t_redir *out, t_command *cmd);
t_command	*check_out_file_cmd(t_command *cmd, char **env);
int			check_out_fd(t_command *cmd, char **env);
#endif
