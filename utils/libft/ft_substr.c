/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:02:33 by hboutale          #+#    #+#             */
/*   Updated: 2024/11/04 18:39:01 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t n1, size_t n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	max_len;
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	max_len = ft_min(s_len - start, len);
	result = (char *)malloc(sizeof(char) * (max_len + 1));
	if (!result)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}
