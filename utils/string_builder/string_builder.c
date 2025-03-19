/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:16:09 by hboutale          #+#    #+#             */
/*   Updated: 2025/03/19 21:01:58 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_builder.h"

t_sb *sb_create()
{
	t_sb *sb;

	sb = (t_sb *)malloc(sizeof(t_sb));
	if (!sb)
		return (NULL);
	sb->cap = 8;
	sb->len = 0;
	sb->buffer = (char *)ft_calloc(sb->cap, sizeof(char));
	if (!sb->buffer)
	{
		free(sb);
		return (NULL);
	}
	sb->buffer[0] = 0;
	return (sb);
}

int sb_ensure_cap(t_sb *sb, size_t additinal_len)
{
	size_t required_len;
	if (!sb)
		return (0);

	required_len = sb->len + additinal_len + 1; // 1 for null term
	if (required_len > sb->cap)
	{
		if (!sb_resize(sb, required_len * 2))
			return (0);
	}
	return (1);
}

int sb_resize(t_sb *sb, size_t new_cap)
{
	char *new_buffer;
	if (!sb || new_cap == 0)
		return (0);
	new_buffer = (char *)malloc(sizeof(char) * new_cap);
	if (!new_buffer)
		return (0);
	ft_memcpy(new_buffer, sb->buffer, (sb->len + 1) * sizeof(char));
	free(sb->buffer);
	sb->buffer = new_buffer;
	sb->cap = new_cap;
	return (1);
}

int sb_append(t_sb *sb, char *str)
{
	size_t strlen;

	if (!sb || !str)
		return (0);
	strlen = ft_strlen(str);
	if (!sb_ensure_cap(sb, strlen))
		return (0);
	ft_strlcpy(sb->buffer + sb->len, str, strlen + 1);
	sb->len += strlen;
	return (1);
}

int sb_append_char(t_sb *sb, char c)
{
	if (!sb)
		return (0);
	if (!sb_ensure_cap(sb, 1))
		return (0);
	sb->buffer[sb->len] = c;
	sb->len += 1;
	sb->buffer[sb->len] = '\0';
	return (1);
}
