/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:36:42 by hboutale          #+#    #+#             */
/*   Updated: 2025/03/18 14:42:04 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static void print_token(const t_token *token)
{
	if (!token)
	{
		fprintf(stderr, "Error: NULL token passed to print_token.\n");
		return;
	}

	// Print the token value
	printf("Token(%s, ", token->value);

	// Print the token type
	switch (token->type)
	{
	case STRING:
		printf("STRING)\n");
		break;
	case GREATER:
		printf("GREATER)\n");
		break;
	case LESS:
		printf("LESS)\n");
		break;
	case PIPE:
		printf("PIPE)\n");
		break;
	case APPEND:
		printf("APPEND)\n");
		break;
	case HERE_DOC:
		printf("HERE_DOC)\n");
		break;
	case AND:
		printf("AND)\n");
		break;
	case OR:
		printf("OR)\n");
		break;
	case END_FILE:
		printf("END_FILE)\n");
		break;
	default:
		printf("UNKNOWN)\n");
		break;
	}
}

t_tokenizer *tokenizer_create()
{
	t_tokenizer *tokenizer;

	tokenizer = malloc(sizeof(t_tokenizer));
	if (!tokenizer)
		return (NULL);

	tokenizer->tokens = array_create();
	return (tokenizer);
}

t_array *tokenize(t_tokenizer *tokenizer)
{
	t_token *token;
	tokenizer->index = 0;
	tokenizer->start = 0;
	tokenizer->input = readline("minishell> ");
	if (!tokenizer->input)
		return (NULL);
	token = tokenizer_next(tokenizer);
	while (token)
	{
		print_token(token);
		token = tokenizer_next(tokenizer);
	}
	free(tokenizer->input);
	return (NULL);
}

t_token *new_token(t_token_type type, char *value)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	return token;
}

char advance(t_tokenizer *tokenizer)
{
	char c;
	c = tokenizer->input[tokenizer->index++];
	return c;
}

int match(t_tokenizer *tokenizer, char c)
{
	char curr;

	curr = tokenizer->input[tokenizer->index];
	if (curr == c)
	{
		tokenizer->index++;
		return (1);
	}
	return (0);
}

char peek(t_tokenizer *tokenizer)
{
	return tokenizer->input[tokenizer->index];
}

t_token *tokenize_string(t_tokenizer *tokenizer)
{
	char *str;
	t_token *token;

	while (peek(tokenizer) && peek(tokenizer) != '\'')
		advance(tokenizer);
	if (peek(tokenizer) == '\0')
		return (NULL);
	str = ft_substr(tokenizer->input, tokenizer->start + 1, tokenizer->index - tokenizer->start - 1);
	advance(tokenizer); // skip single qoute
	if (!str)
		return (NULL);
	token = new_token(STRING, str);
	if (!token)
	{
		free(str);
		return NULL;
	}
	return token;
}

t_token *tokenizer_next(t_tokenizer *tokenizer)
{
	while (peek(tokenizer) == ' ')
		advance(tokenizer);
	tokenizer->start = tokenizer->start;
	char c = advance(tokenizer);
	if (c == '|')
	{
		if (match(tokenizer, '|'))
			return new_token(OR, ft_strdup("||"));
		return new_token(PIPE, ft_strdup("|"));
	}
	else if (c == '>')
	{
		if (match(tokenizer, '>'))
			return new_token(APPEND, ">>");
		return new_token(GREATER, ">");
	}
	else if (c == '<')
	{
		if (match(tokenizer, '<'))
			return new_token(HERE_DOC, "<<");
		return new_token(LESS, "<");
	}
	else if (c == '\'')
	{
		return tokenize_string(tokenizer);
	}
	return (NULL);
}
