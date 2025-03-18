/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:33:33 by hboutale          #+#    #+#             */
/*   Updated: 2024/11/05 11:15:29 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		ch;

	ch = (unsigned char)c;
	str = (const unsigned char *)ptr;
	while (n--)
	{
		if (*str == ch)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
