/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:27:54 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/13 06:32:28 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_bytes(int n)
{
	int	bytes;

	bytes = 0;
	if (n <= 0)
		bytes++;
	while (n != 0)
	{
		n = n / 10;
		bytes++;
	}
	return (bytes);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		bytes;

	bytes = count_bytes(n);
	num = malloc(bytes + 1);
	if (num == NULL)
		return (NULL);
	num[bytes] = '\0';
	if (n == -2147483648)
	{
		ft_strlcpy(num, "-2147483648", 12);
		return (num);
	}
	if (n < 0)
		n = -n;
	while (bytes > 0)
	{
		num[bytes - 1] = n % 10 + '0';
		n = n / 10;
		bytes--;
	}
	if (num[0] == '0' && num[1] != '\0')
		num[0] = '-';
	return (num);
}
