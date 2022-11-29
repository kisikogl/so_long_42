/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:22:15 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/14 11:44:48 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sone;
	unsigned char	*stwo;
	size_t			a;

	sone = (unsigned char *)s1;
	stwo = (unsigned char *)s2;
	a = 0;
	while (a < n)
	{
		if (sone[a] != stwo[a])
			return (sone[a] - stwo[a]);
		a++;
	}
	return (0);
}
