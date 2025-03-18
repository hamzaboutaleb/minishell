/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:34:52 by hboutale          #+#    #+#             */
/*   Updated: 2024/11/05 18:52:00 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	has(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	start_index(char const *s1, char const *set)
{
	size_t	result;

	result = 0;
	while (s1[result] && has(s1[result], set))
		result++;
	return (result);
}

static size_t	end_index(char const *s1, char const *set)
{
	size_t	result;

	if (ft_strlen(s1) == 0)
		return (0);
	result = ft_strlen(s1) - 1;
	while (has(s1[result], set) && result > 0)
		result--;
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = start_index(s1, set);
	end = end_index(s1, set);
	i = 0;
	if (start > end)
		return (ft_strdup(""));
	result = ft_substr(s1, start, (end - start) + 1);
	return (result);
}
