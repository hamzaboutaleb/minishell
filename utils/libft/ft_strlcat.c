/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:53:57 by hboutale          #+#    #+#             */
/*   Updated: 2024/11/05 11:43:24 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	dlen;
	unsigned int	slen;
	unsigned int	i;
	unsigned int	res;

	res = 0;
	i = 0;
	slen = ft_strlen(src);
	if (size == 0)
		return (slen);
	dlen = ft_strlen(dest);
	if (dlen >= size)
		return (size + slen);
	else
		res = slen + dlen;
	while (src[i] && dlen < size - 1)
	{
		dest[dlen] = src[i];
		dlen++;
		i++;
	}
	dest[dlen] = '\0';
	return (res);
}
