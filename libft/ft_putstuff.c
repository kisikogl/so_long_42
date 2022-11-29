/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:13:38 by kisikogl          #+#    #+#             */
/*   Updated: 2022/07/14 14:05:24 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr(char *s, int fd)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write (fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

void	rec_putnbr(unsigned int n, int *count, int fd)
{
	if (n != 0)
	{
		rec_putnbr(n / 10, count, fd);
		ft_putchar(n % 10 + '0', fd);
		(*count)++;
	}
}

int	ft_putnbr(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		return (ft_putstr("-2147483648", fd));
	}
	if (n < 0)
	{
		n = -n;
		count += ft_putchar('-', fd);
	}
	if (n == 0)
	{
		count += ft_putchar('0', fd);
	}
	else
	{
		rec_putnbr(n, &count, fd);
	}
	return (count);
}
