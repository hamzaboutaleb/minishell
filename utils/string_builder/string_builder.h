/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_builder.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:16:18 by hboutale          #+#    #+#             */
/*   Updated: 2025/03/20 12:23:53 by hboutale         ###   ########.fr       */
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
int sb_ensure_cap(t_sb *sb, size_t additinal_len);
int sb_resize(t_sb *sb, size_t new_cap);
int sb_append(t_sb *sb, char *str);
int sb_append_char(t_sb *sb, char c);
char *sb_build(t_sb *sb);
#endif
