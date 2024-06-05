/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:56:45 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/02/11 18:21:08 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	res;
	size_t	i;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = 0;
	if (dstsize > ldst)
		res = ldst + lsrc;
	else
		res = lsrc + dstsize;
	while (((char *)src)[i] != 0 && (ldst + 1) < dstsize)
	{
		dst[ldst] = ((char *)src)[i];
		ldst++;
		i++;
	}
	if (ldst < dstsize)
		dst[ldst] = 0;
	return (res);
}
