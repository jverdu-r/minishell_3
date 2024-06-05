/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:24:09 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/02/01 16:34:44 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ptr;
	unsigned int		a;

	a = 0;
	if ((s == NULL) || (f == NULL))
		return (NULL);
	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s[a] != 0)
	{
		ptr[a] = (*f)(a, (char)s[a]);
		a++;
	}
	ptr[a] = '\0';
	return (ptr);
}
