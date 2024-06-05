/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:14:41 by daparici          #+#    #+#             */
/*   Updated: 2024/05/23 17:40:04 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
//# include <xlocale.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>  

char	*ft_strchrnew(char *s, int c);
char	*ft_strjoinnew(char *res, char *copy);
size_t	ft_strlennew(char *str);
char	*get_next_line(int fd);
char	*copystr(int fd, char *res);
char	*ft_getreserv(char *res);
char	*ft_getline(char *res);

#endif