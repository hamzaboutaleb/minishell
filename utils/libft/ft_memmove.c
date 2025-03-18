/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:09:56 by hboutale          #+#    #+#             */
/*   Updated: 2024/11/05 11:32:08 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*move_non_overlap(void *dest_ptr, const void *src_ptr, int size)
{
	unsigned char		*dest;
	const unsigned char	*src;
	int					i;

	dest = dest_ptr;
	src = src_ptr;
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest_ptr);
}

static void	*move_overlap(void *dest_ptr, const void *src_ptr, int size)
{
	unsigned char		*dest;
	const unsigned char	*src;
	int					i;

	dest = dest_ptr;
	src = src_ptr;
	i = size - 1;
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest_ptr);
}

void	*ft_memmove(void *dest_ptr, const void *src_ptr, size_t size)
{
	if (dest_ptr == NULL && src_ptr == NULL)
		return (NULL);
	if (dest_ptr > src_ptr)
		return (move_overlap(dest_ptr, src_ptr, size));
	else
		return (move_non_overlap(dest_ptr, src_ptr, size));
}
