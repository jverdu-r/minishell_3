/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:22:15 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/02/07 17:04:12 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (((char *)needle)[b] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[a] != '\0' && a < len)
	{
		while (haystack[a + b] != '\0' && needle[b] != '\0'
			&& haystack[a + b] == needle[b] && a + b < len)
		{
			if (needle[b + 1] == '\0')
			{
				return ((char *)&haystack[a]);
			}
			b++;
		}
		b = 0;
		a++;
	}
	return (0);
}
