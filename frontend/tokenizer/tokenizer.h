/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:36:39 by hboutale          #+#    #+#             */
/*   Updated: 2025/03/18 14:35:08 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../../utils/libft/libft.h"
#include "../../utils/array/array.h"

typedef enum e_token_type
{
	WORD,
	STRING,	  // "" || ''
	GREATER,  // >
	LESS,	  // <
	PIPE,	  // |
	APPEND,	  // >>
	HERE_DOC, // <<
	AND,	  // &&
	OR,		  // ||
	END_FILE  // EOF
} t_token_type;

typedef struct s_token
{
	char *value;
	t_token_type type;
} t_token;

typedef struct s_tokenizer
{
	char *input;
	size_t index;
	size_t start;
	t_array *tokens;
} t_tokenizer;

t_tokenizer *tokenizer_create();
void tokenizer_destroy(t_tokenizer *tokenizer);
t_token *tokenizer_next(t_tokenizer *tokenizer);
t_array *tokenize(t_tokenizer *tokenizer);

#endif
