/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrya.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:39:04 by hboutale          #+#    #+#             */
/*   Updated: 2025/03/18 11:46:59 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static int array_resize(t_array *array)
{
	void **new_arr;
	size_t new_cap;

	new_cap = array->cap * ARRAY_RESIZE_FACTOR;
	new_arr = ft_calloc(new_cap, sizeof(void *));
	if (!new_arr)
		return (0);
	ft_memcpy(new_arr, array->arr, array->len * sizeof(void *));
	free(array->arr);
	array->arr = new_arr;
	array->cap = new_cap;
	return (1);
}

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

int array_push(t_array *array, void *element)
{
	if (!array || !element)
	{
		fprintf(stderr, "Error: NULL pointer passed to array_push.\n");
		return (0);
	}
	if (array->len == array->cap)
	{
		if (!array_resize(array))
		{
			fprintf(stderr, "Error: Failed to resize array.\n");
			return (0);
		}
	}
	array->arr[array->len++] = element;
	return (1);
}

void *array_pop(t_array *array)
{
	void *element;

	if (!array || array->len == 0)
	{
		fprintf(stderr, "Error: Cannot pop from NULL or empty array.\n");
		return (NULL);
	}
	element = array->arr[array->len - 1];
	array->arr[array->len--] = NULL;
	return (element);
}

void array_destroy(t_array *array, void (*free_element)(void *))
{
	size_t i;
	if (!array)
	{
		fprintf(stderr, "Error: NULL pointer passed to array_destroy.\n");
		return;
	}
	if (free_element)
	{
		i = 0;
		while (i < array->len)
		{
			free_element(array->arr[i]);
			i++;
		}
	}
	free(array->arr);
	free(array);
}
