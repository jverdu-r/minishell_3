/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:23:03 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/02/08 17:45:27 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	overload(int val)
{
	if (val == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long int	res;
	int					neg;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == 32 || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == 45)
		neg = -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i] - '0';
		if (res > 9223372036854775807)
			return (overload(neg));
		i++;
	}
	res = res * neg;
	return ((int)res);
}
