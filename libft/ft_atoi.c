/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:04:40 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/14 11:45:35 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspaceorsign(int c)
{
	char	ch[6];
	int		a;

	ch[0] = '\t';
	ch[1] = '\n';
	ch[2] = '\v';
	ch[3] = '\f';
	ch[4] = '\r';
	ch[5] = ' ';
	a = 0;
	while (a < 6)
	{
		if (c == ch[a])
			return (1);
		a++;
	}
	if (c == '-' || c == '+')
		return (c);
	return (0);
}

int	ft_atoi(const char *str)
{
	char	sign;
	long	num;
	int		a;

	sign = 0;
	num = 0;
	a = 0;
	while (isspaceorsign(str[a]))
	{
		if (isspaceorsign(str[a]) == str[a])
		{
			if (sign > 0)
				return (0);
			sign = str[a++];
			break ;
		}
		a++;
	}
	while ((str[a] >= '0' && str[a] <= '9'))
	{
		num = num * 10 + (str[a++] - '0');
	}
	if (sign == '-')
		num = -num;
	return (num);
}
