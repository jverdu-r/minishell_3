/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:48:10 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/02/11 18:31:48 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int	ft_abs(int n)
{
	unsigned long int	a;

	a = n;
	return (a * -1);
}

int	ft_numlen(unsigned long int n, int b)
{
	int			count;
	long int	a;

	count = 0;
	a = n;
	while (a > 0)
	{
		a = a / 10;
		count++;
	}
	if (b < 0)
		count++;
	return (count);
}

char	*ft_zerolen(void)
{
	char	*p;

	p = malloc(sizeof(char) * 2);
	if (p == NULL)
		return (NULL);
	p[0] = '0';
	p[1] = '\0';
	return (p);
}

unsigned long int	ft_checknum(int n)
{
	unsigned long int	num;

	num = 0;
	if (n < 0)
		num = ft_abs(n);
	else
		num = n;
	return (num);
}

char	*ft_itoa(int n)
{
	unsigned long int	num;
	int					count;
	char				*ptr;

	num = ft_checknum(n);
	count = ft_numlen(num, n);
	if (n == 0)
		return (ptr = ft_zerolen());
	ptr = malloc(sizeof(char) * (count + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[count] = '\0';
	count--;
	while (count >= 0)
	{
		if (n < 0 && count == 0)
			ptr[count] = '-';
		else
		{
			ptr[count] = (num % 10) + 48;
			num = num / 10;
		}
		count--;
	}
	return (ptr);
}
