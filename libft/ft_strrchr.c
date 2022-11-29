/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:32:50 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/14 06:29:58 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buffer;
	int		a;

	c = (char) c;
	buffer = 0;
	a = 0;
	while (s[a] > 0)
	{
		if (s[a] == c)
			buffer = ((char *)(s + a));
		a++;
	}
	if (c == 0)
		return ((char *)(s + a));
	return (buffer);
}
