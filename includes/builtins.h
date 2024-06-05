/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:56:27 by daparici          #+#    #+#             */
/*   Updated: 2024/05/25 02:17:24 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "tokens.h"

//Here_doc
char	*heredoc_loop(t_command *cmd, char **env);
char	*heredoc(char *input, char *lim);
void	check_here_doc(t_command *cmd, char **env);
void	heredoc_child(int *pre_p, int *ac_p, t_command *cmd);
char	*find_variable(char *str, unsigned int i);
char	*expander_hdoc(char *str, char **env);
int		expander_hdoc_2(char *str, int i);
char	*expander_hdoc_3(char *str, char **env, char *expand_str, int i);
char	*check_env(char *str, char **env);
void	resolve_heredocs(t_command *cmd, char **env);
void	child_control(int *pipe1, char **env, t_command *cmd, int i);
int		ft_strncmp_2(const char *s1, const char *s2, size_t n);

//built-ins funcion
//  echo
int		ft_echo(t_command *cmd);
void	print_arguments(char **arg, int i, int out_fd);
//  pwd
int		ft_pwd(void);
// 	env
int		ft_env(char **env);
int		check_equal_env(char *env);
//	export
int		ft_export(t_toolbox *tools);
char	**add_variable(char **sort_env, char *cmd_arg);
void	print_export(char **env);
void	export_error(char *cmd_arg);
int		lenght_to_equal(char *cmd_arg);
int		check_variable_exist(t_toolbox *tools, char *cmd_arg);
int		check_parametres(char *cmd_arg);
char	**delete_variable(char **env, int i);
void	executor_error(t_command *cmd, char *str);

// unset
int		ft_unset(t_toolbox *tools);
char	**delete_variable(char **env, int i);
int		ft_check_equal(char *arg);
int		check_pmt_unset(char *cmd_arg);

// cd
int		ft_cd(t_toolbox *tools);
void	render_env(t_toolbox *tools);
char	*get_env_dir(t_toolbox *tools, char *arg);
char	*get_absolute_dir(t_toolbox *tools);
void	print_err(char *str, int c);

//exit
int		m_exit(t_toolbox *tools, t_command *cmd);
#endif
