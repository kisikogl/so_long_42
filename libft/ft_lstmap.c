/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 07:33:13 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/14 11:11:58 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*pnt;
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	node = ft_lstnew(f(lst->content));
	if (node == NULL)
		return (NULL);
	pnt = node;
	lst = lst->next;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&pnt, del);
			return (NULL);
		}
		ft_lstadd_back(&pnt, node);
		lst = lst->next;
	}
	return (pnt);
}
