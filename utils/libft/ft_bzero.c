/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:05:56 by hboutale          #+#    #+#             */
/*   Updated: 2024/11/04 17:02:30 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	size_t			i;
	unsigned char	*str;

	str = ptr;
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}
