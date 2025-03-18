/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:14:48 by hboutale          #+#    #+#             */
/*   Updated: 2024/11/04 17:57:27 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char ch)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	if (!*str)
		return (0);
	while (str[i])
	{
		while (str[i] && ch == str[i])
			i++;
		if (str[i])
			res++;
		while (str[i] && ch != str[i])
			i++;
	}
	return (res);
}

static char	*make_string(const char *str, int start, int end)
{
	int		size;
	char	*res;
	int		i;

	i = 0;
	size = end - start;
	res = (char *)malloc(sizeof(char) * size + 1);
	if (res == NULL || !*str)
		return (NULL);
	while (i < size)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	split_string(char **res, const char *str, char c)
{
	int	i;
	int	k;
	int	start;

	k = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && c == str[i])
			i++;
		start = i;
		while (str[i] && c != str[i])
			i++;
		if (start != i)
		{
			res[k] = make_string(str, start, i);
			if (!res[k])
				return (k);
			k++;
		}
	}
	res[k] = 0;
	return (-1);
}

static void	*free_until(char **res, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		err_index;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (res == NULL)
		return (NULL);
	err_index = split_string(res, s, c);
	if (err_index != -1)
		return (free_until(res, err_index));
	return (res);
}
