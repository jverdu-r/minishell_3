/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:25:27 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/03 01:22:02 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum s_token
{
	PIPE = 1,
	LESS,
	LESS_LESS,
	GREAT,
	GREAT_GREAT
}	t_token;

typedef struct s_redir
{
	char			*file;
	struct s_redir	*next;
	struct s_redir	*prev;
}	t_redir;

typedef struct s_command
{
	char				*cmd;
	char				*append;
	int					app;
	int					heredoc;
	char				**limiter;
	int					check_lim;
	char				**args;
	int					out_fd;
	int					in_fd;
	int					pid;
	t_redir				*in_files;
	t_redir				*out_files;
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;

typedef enum s_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_lexer
{
	char			*str;
	t_token			token;
	int				index;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_toolbox
{
	char		*args;
	char		**env;
	char		**sort_env;
	char		*env_rute;
	char		*pwd;
	char		*old_pwd;
	char		*home_dir;
	t_command	*cmd;
	t_lexer		*lexer_list;
}	t_toolbox;

#endif
