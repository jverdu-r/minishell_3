/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:14:28 by daparici          #+#    #+#             */
/*   Updated: 2024/05/08 19:11:08 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getreserv(char *res)
{
	char	*copy;
	int		k;
	int		i;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (!res[i])
	{
		free(res);
		return (NULL);
	}
	copy = (char *)malloc((ft_strlennew(res) - i + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i++;
	k = 0;
	while (res[i])
		copy[k++] = res[i++];
	copy[k] = '\0';
	free(res);
	return (copy);
}

char	*ft_copystr(int fd, char *res)
{
	char	*copy;
	char	*aux;
	int		len;

	copy = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	len = 1;
	while (!ft_strchrnew(res, '\n') && len != 0)
	{
		len = read(fd, copy, BUFFER_SIZE);
		if (len == -1)
		{
			free(copy);
			return (NULL);
		}
		copy[len] = '\0';
		aux = res;
		res = ft_strjoinnew(aux, copy);
		free(copy);
	}
	return (res);
}

char	*ft_getline(char *res)
{
	char	*line;
	int		i;

	i = 0;
	if (!res[i])
		return (NULL);
	while (res[i] && res[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (res[i] && res[i] != '\n')
	{
		line[i] = res[i];
		i++;
	}
	if (res[i] == '\n')
	{
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	res = ft_copystr(fd, res);
	if (!res)
		return (NULL);
	line = ft_getline(res);
	res = ft_getreserv(res);
	return (line);
}
