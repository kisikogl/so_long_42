/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:24:48 by kisikogl          #+#    #+#             */
/*   Updated: 2022/04/10 13:34:04 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	create_strings(char **arr, char const *s, char c, int arr_len)
{
	int	x;
	int	i;
	int	k;

	x = 0;
	i = 0;
	while (x < arr_len)
	{
		k = 0;
		while (s[i] != c && s[i] != 0)
		{
			i++;
			k++;
		}
		if (k == 0)
		{
			i++;
			continue ;
		}
		arr[x] = malloc(k + 1);
		ft_strlcpy(arr[x], s + i - k, k + 1);
		while (s[i] == c)
			i++;
		x++;
	}
}

static int	get_arrlen(const char *s, int c)
{
	char	k;
	int		i;
	int		arr_len;

	i = 0;
	arr_len = 1;
	if (s[0] == '\0')
		return (0);
	if (c == '\0')
		return (1);
	while (ft_strchr(s + i, c) != NULL)
	{
		if (s[i++] == c)
			continue ;
		while (s[i++] != c)
			k = 1;
		while (s[i] == c)
			i++;
		if (s[i] != 0)
			arr_len++;
	}
	if (s[i] == '\0' && k != 1)
		return (0);
	return (arr_len);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		arr_len;

	if (s == NULL)
		return (NULL);
	arr_len = get_arrlen(s, c);
	arr = (char **)malloc((arr_len + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	create_strings(arr, s, c, arr_len);
	arr[arr_len] = NULL;
	return (arr);
}
