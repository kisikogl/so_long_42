/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:13:24 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/12 05:53:57 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pnt;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len >= start + len)
		pnt = malloc(len + 1);
	else if (start <= s_len)
		pnt = malloc(s_len - start + 1);
	else
		return (ft_strdup(""));
	if (pnt == NULL)
		return (NULL);
	ft_strlcpy(pnt, s + start, len + 1);
	return (pnt);
}
