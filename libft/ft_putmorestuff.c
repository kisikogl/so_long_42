/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmorestuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:21:09 by kisikogl          #+#    #+#             */
/*   Updated: 2022/07/14 14:06:48 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned(unsigned int num, int fd)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		ft_putchar('0', fd);
		count++;
	}
	else
		rec_putnbr(num, &count, fd);
	return (count);
}

int	ft_puthexa(unsigned int num, int *count, int fd)
{
	if (num != 0)
	{
		*count = 0;
		ft_puthexa(num / 16, count, fd);
		num = num % 16;
		if (num > 9)
			num += 87;
		else
			num += '0';
		ft_putchar(num, fd);
		(*count)++;
	}
	if (num == 0 && *count == 1)
		ft_putchar('0', fd);
	return (*count);
}

int	ft_putcaphexa(unsigned int num, int *count, int fd)
{
	if (num != 0)
	{
		*count = 0;
		ft_putcaphexa(num / 16, count, fd);
		num = num % 16;
		if (num > 9)
			num += 55;
		else
			num += '0';
		ft_putchar(num, fd);
		(*count)++;
	}
	if (num == 0 && *count == 1)
		ft_putchar('0', fd);
	return (*count);
}

int	putunsignedhexa(unsigned long num, int *count, int fd)
{
	if (num != 0)
	{
		*count = 0;
		putunsignedhexa(num / 16, count, fd);
		num = num % 16;
		if (num > 9)
			num += 87;
		else
			num += '0';
		ft_putchar(num, fd);
		(*count)++;
	}
	if (num == 0 && *count == 1)
		ft_putchar('0', fd);
	return (*count);
}

int	ft_putpnt(void *pnt, int fd)
{
	int	count;

	count = 1;
	ft_putstr("0x", fd);
	putunsignedhexa((unsigned long)pnt, &count, fd);
	count += 2;
	return (count);
}
