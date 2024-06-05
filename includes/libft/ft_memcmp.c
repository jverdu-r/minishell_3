/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:07:27 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/02/07 16:35:19 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	a;

	a = 0;
	while (a < n)
	{
		if (((unsigned char *)s1)[a] != ((unsigned char *)s2)[a])
		{
			return (((unsigned char *)s1)[a] - ((unsigned char *)s2)[a]);
		}
		a++;
	}
	return (0);
}
