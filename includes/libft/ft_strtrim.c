/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:38:38 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/02/11 17:43:29 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getst(char const *s1, char const *set)
{
	int	i;
	int	c;

	i = 0;
	while (s1[i] != 0)
	{
		c = 0;
		while (s1[i] != set[c] && set[c] != 0)
			c++;
		if (set[c] == 0)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

int	ft_getend(char const *s1, char const *set)
{
	int	i;
	int	c;

	i = (int)ft_strlen(s1);
	i--;
	while (i >= 0)
	{
		c = 0;
		while (s1[i] != set[c] && set[c] != 0)
			c++;
		if (set[c] == 0)
		{
			return (i);
		}
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		st;
	int		end;
	int		len;
	int		memsize;
	char	*ptr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	st = ft_getst(s1, set);
	end = ft_getend(s1, set);
	if (st > end)
		return (ft_strdup(""));
	memsize = (ft_strlen(s1) - st - (ft_strlen(s1) - end));
	ptr = (char *)malloc(sizeof(char) * (memsize + 2));
	if (ptr == NULL)
		return (NULL);
	len = 0;
	while ((st) <= end)
	{
		ptr[len] = s1[st];
		st++;
		len++;
	}
	ptr[len] = 0;
	return (ptr);
}
