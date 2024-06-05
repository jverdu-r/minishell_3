/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:26:55 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/03 19:25:11 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	a;
	int	len;

	a = 0;
	len = ft_strlen(str);
	while (a <= len)
	{
		if (str[a] == (char)c)
			return (&((char *)str)[a]);
		a++;
	}
	return (NULL);
}
