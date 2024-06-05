/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:07:55 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/26 15:28:08 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include "libft/libft.h"
# include "tokens.h"
# include "structs.h"
# include "lexer.h"
# include "parser.h"
# include "expander.h"
# include "builtins.h"
# include "GetNextLine/get_next_line.h"

//global
//volatile sig_atomic_t	g_exit_status;

//test
t_command	*cmd_extract(t_lexer *list);
int			check_syntax(t_lexer *tk_list);

//signal functions
void		sig_heredoc(void);
void		signals_workout(void);
void		child_signals(void);
void		father_workout(void);
void		sig_ignire(void);
void		println(int sig);
void		sig_heredoc(void);
void		sig_ignire(void);

//loop functions
int			minishell_loop(t_toolbox *tools);
int			tools_load(t_toolbox *tools);
void		tools_reload(t_toolbox *tools);

//enviroment functions
char		**envp_dup(char **envp, t_toolbox *tools);
int			pwd_search(t_toolbox *tools, char **envp);
char		**st_envp(char **envp);
char		**new_env(void);
char		*get_home(void);
char		**sort_arr(char **arr);

//utility functions
int			exit_code(int ex);

//char		*expander(t_toolbox *tools, char *str);
void		free_arr(char **arr);
int			handle_quotes(char *input);
int			check_input(t_toolbox *tools);
int			check_quotes(char *str);
t_bool		switch_bool(t_bool bool);

//error functions
int			error_msg(char *msg);
int			error_token(t_token token);
void		print_err_token(char *c, int len);

//executor funcion
void		ft_executor_loop(t_command *cmd, t_toolbox *tools);
void		ft_executor(t_toolbox *tools);
void		recursive_ex(int *pre_pipe, t_command *cmd, t_toolbox *tools);
int			ft_is_builtin(t_command *cmd);
void		ft_is_builtin_2(t_toolbox *tools, t_command *cmd);
char		*find_paths(char **envp);
char		*find_path(char *cmd, char **path);
void		manage_params_child(t_toolbox *tools, t_command *cmd);
void		manage_dups(t_command *cmd, int *pre_pipe, int *ac_pipe);
void		simple_command(t_toolbox *tools, t_command *cmd);
int			ft_lstsize_m(t_command *list);
char		**fill_args(t_command *cmd);
void		ret_exit(void);
#endif
