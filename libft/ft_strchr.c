/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:53:15 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/14 06:29:41 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	a;

	c = (char) c;
	a = 0;
	while (s[a] > 0)
	{
		if (s[a] == c)
			return ((char *)(s + a));
		a++;
	}
	if (c == 0)
		return ((char *)(s + a));
	return (0);
}
