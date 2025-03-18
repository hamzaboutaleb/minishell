/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:39:02 by hboutale          #+#    #+#             */
/*   Updated: 2025/03/18 11:07:13 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_array
{
	void *arr;
	size_t len;
	size_t cap;
} t_array;

t_array *array_create();
void array_destroy();
int array_push(t_array *array, void *element);
void *array_pop(t_array *array);
size_t array_length(const t_array *array);
#endif
