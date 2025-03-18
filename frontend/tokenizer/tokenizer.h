/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:36:39 by hboutale          #+#    #+#             */
/*   Updated: 2025/03/18 12:02:30 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdlib.h>
#include <stdio.h>
#include "../../utils/libft/libft.h"
#include "../../utils/array/array.h"

typedef enum e_token_type
{
	STRING, // ""
	GREATER, // >
	LESS, // <
	PIPE, // |
	APPEND, // >>
	AND, // &&
	OR, // ||
	END_FILE // EOF
} t_token_type;

typedef struct s_token
{
	char *value;
	t_token_type type;
} t_token;

t_array *tokenize(const char *input);

#endif
