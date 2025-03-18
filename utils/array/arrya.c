/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrya.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:39:04 by hboutale          #+#    #+#             */
/*   Updated: 2025/03/18 11:05:20 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array *array_create()
{
	t_array *arr;

	arr = (t_array *)malloc(sizeof(t_array));
	if (!arr)
		return (NULL);
	arr->len = 0;
	arr->cap = 4;
	arr->arr = ft_calloc(arr->cap, sizeof(void *));
	if (!arr->arr)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
