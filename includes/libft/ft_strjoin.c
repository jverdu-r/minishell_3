/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:14:30 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/03/20 12:20:34 by davidaparic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		a;
	int		b;
	char	*ptr;

	a = 0;
	b = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[a] != '\0')
	{
		ptr[a] = ((char *)s1)[a];
		a++;
	}
	while (s2[b] != '\0')
	{
		ptr[a] = ((char *)s2)[b];
		a++;
		b++;
	}
	ptr[a] = 0;
	return (ptr);
}
