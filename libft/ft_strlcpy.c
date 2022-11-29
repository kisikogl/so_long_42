/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:39:17 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/10 06:57:59 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	a;

	a = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (a < dstsize - 1 && src[a])
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = 0;
	return (ft_strlen(src));
}
