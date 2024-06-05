/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:34:15 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/02/08 17:06:27 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	len;
	size_t	newlen;

	len = ft_strlen(src);
	if (destsize == 0)
		return (len);
	if (len >= destsize)
		newlen = destsize - 1;
	else
		newlen = len;
	ft_memcpy(dst, src, newlen);
	dst[newlen] = 0;
	return (len);
}
