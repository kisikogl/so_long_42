/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:18:12 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/09 07:04:06 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	a;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= dstsize)
		return (dstsize + len_src);
	a = 0;
	while (a < (dstsize - len_dst - 1) && src[a])
	{
		dst[len_dst + a] = src[a];
		a++;
	}
	dst[len_dst + a] = 0;
	return (len_dst + len_src);
}
