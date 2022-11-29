/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:57:01 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/14 09:07:14 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	a;

	c = (unsigned char) c;
	a = 0;
	while (n > 0)
	{
		if (*(unsigned char *)(s + a) == c)
			return ((unsigned char *)(s + a));
		a++;
		n--;
	}
	return (0);
}
