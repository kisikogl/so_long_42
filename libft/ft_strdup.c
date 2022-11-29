/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 09:02:37 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/08 18:34:28 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pnt;
	size_t	a;

	pnt = (char *)malloc(ft_strlen(s1) + 1);
	if (pnt == NULL)
		return (0);
	a = 0;
	while (a < ft_strlen(s1) + 1)
	{
		pnt[a] = s1[a];
		a++;
	}
	return (pnt);
}
