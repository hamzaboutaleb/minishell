/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:37:02 by hboutale          #+#    #+#             */
/*   Updated: 2024/11/04 18:14:25 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	result = malloc(sizeof(char) * (s_len + 1));
	if (!result)
		return (NULL);
	while (i < s_len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
