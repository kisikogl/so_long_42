/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:15:38 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/14 11:42:59 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_start(char const *s1, char const *set)
{
	size_t	c;

	c = 0;
	if (s1[0] == 0)
		return (0);
	while (ft_strchr(set, s1[c]))
	{
		c++;
		if (s1[c] == '\0')
			return (c - 1);
	}
	return (c);
}

static size_t	trim_end(char const *s1, char const *set, size_t start)
{
	size_t	c;

	if (s1[0] == 0)
		return (0);
	c = ft_strlen(s1);
	while (start < c && ft_strchr(set, s1[c - 1]))
	{
		c--;
	}
	return (ft_strlen(s1) - c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trimstart;
	size_t	trimend;
	size_t	trimmed_strlen;

	if (s1 == NULL)
		return (NULL);
	trimstart = trim_start(s1, set);
	trimend = trim_end(s1, set, trimstart);
	trimmed_strlen = ft_strlen(s1) - (trimstart + trimend);
	return (ft_substr(s1, trimstart, trimmed_strlen));
}
