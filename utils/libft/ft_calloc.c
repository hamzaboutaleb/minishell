/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:34:46 by hboutale          #+#    #+#             */
/*   Updated: 2024/11/05 11:12:49 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;

	if (elsize && nelem > (size_t)-1 / elsize)
		return (NULL);
	ptr = malloc(nelem * elsize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nelem * elsize);
	return (ptr);
}
