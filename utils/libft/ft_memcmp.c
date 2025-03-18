/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:55:12 by hboutale          #+#    #+#             */
/*   Updated: 2024/11/05 11:22:51 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1_ptr, const void *str2_ptr, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	i = 0;
	str1 = str1_ptr;
	str2 = str2_ptr;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
