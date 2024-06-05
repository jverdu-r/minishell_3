/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:42:12 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/05/24 14:14:33 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] && str2[i] != '\0') && str1[i] == str2[i] && i < n - 1)
		i++;
	return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
}
