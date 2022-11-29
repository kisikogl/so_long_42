/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:17:39 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/14 11:34:36 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*pnt;

	pnt = malloc(count * size);
	if (pnt == NULL)
		return (NULL);
	ft_bzero(pnt, count * size);
	return ((void *)pnt);
}
