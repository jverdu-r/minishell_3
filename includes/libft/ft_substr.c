/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:47:21 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/24 09:10:14 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	nlen;
	size_t	b;

	b = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return ("");
	nlen = ft_strlen(s + start);
	if (nlen < len)
		len = nlen;
	ptr = ft_calloc(sizeof(char), (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (b < len && s[start] != 0)
	{
		ptr[b] = s[start];
		start++;
		b++;
	}
	ptr[b] = '\0';
	return (ptr);
}
