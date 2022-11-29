/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:12:51 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/14 08:11:19 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[h] != 0 && len > 0)
	{
		if (haystack[h] == needle[n])
		{
			if (needle[n + 1] == 0)
				return ((char *)haystack + h - n);
			n++;
		}
		else
		{
			h = h - n;
			len = len + n;
			n = 0;
		}
		len--;
		h++;
	}
	return (0);
}
