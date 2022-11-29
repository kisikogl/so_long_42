/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:26:25 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/14 11:42:31 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pnt;
	size_t	len;
	size_t	a;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	pnt = malloc(len);
	if (pnt == NULL)
		return (0);
	a = 0;
	while (a < len)
	{
		if (a < ft_strlen(s1))
			pnt[a] = s1[a];
		else
			pnt[a] = s2[a - ft_strlen(s1)];
		a++;
	}
	return (pnt);
}
