/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:20:42 by hboutale          #+#    #+#             */
/*   Updated: 2024/11/05 11:28:32 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	i = 0;
	while (i < size)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}
