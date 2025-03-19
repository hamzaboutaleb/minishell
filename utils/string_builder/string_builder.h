/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_builder.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:16:18 by hboutale          #+#    #+#             */
/*   Updated: 2025/03/19 20:27:53 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_BUILDER_H
#define STRING_BUILDER_H
#include <stdlib.h>
#include "./../libft/libft.h"

typedef struct s_sb
{
	char *buffer;
	size_t cap;
	size_t len;
} t_sb;

t_sb *sb_create();

#endif
