/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:35:15 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/28 17:05:03 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), \
		void (*del)(void *))
{
	t_list	*newlst;
	t_list	*aux;

	if (lst != NULL && f != NULL)
	{
		newlst = ft_lstnew(f(lst->content));
		aux = newlst;
		while (lst->next)
		{
			lst = lst->next;
			aux->next = ft_lstnew(f(lst->content));
			if (aux->next == NULL)
			{
				ft_lstclear(&newlst, del);
				return (NULL);
			}
			aux = aux->next;
		}
		return (newlst);
	}
	return (NULL);
}
