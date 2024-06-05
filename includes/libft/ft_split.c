/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:37:13 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/02/21 11:49:17 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *s, char c)
{
	int	res;
	int	trig;

	res = 0;
	trig = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && trig == 0)
		{
			trig = 1;
			res++;
		}
		else if (*s == c)
			trig = 0;
		s++;
	}
	return (res);
}

char	*ft_word(char const *s, int st, int end)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (end - st + 1));
	if (ptr == NULL)
		return (0);
	while (st < end)
	{
		ptr[i] = s[st];
		i++;
		st++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	size_t	a;
	int		i;
	char	**split;

	split = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (split == 0)
		return (0);
	index = -1;
	a = 0;
	i = 0;
	while (a <= ft_strlen(s))
	{
		if (s[a] != c && index < 0)
			index = a;
		else if ((s[a] == c || a == ft_strlen(s)) && index >= 0)
		{
			split[i++] = ft_word(s, index, a);
			index = -1;
		}
		a++;
	}
	split[i] = 0;
	return (split);
}
