/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:36:42 by hboutale          #+#    #+#             */
/*   Updated: 2025/04/09 17:04:41 by hboutale         ###   ########.fr       */
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
	size_t len;
	tokenizer->index = 0;
	tokenizer->start = 0;
	tokenizer->input = readline("minishell> ");
	if (!tokenizer->input)
		return (NULL);
	len = ft_strlen(tokenizer->input);
	while (tokenizer->index < len)
	{
		tokenizer->start = tokenizer->index;
		token = tokenizer_next(tokenizer);
		if (token)
		{
			array_push(tokenizer->tokens, token);
			print_token(token);
		}
	}
	free(tokenizer->input);
	return (tokenizer->tokens);
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

char prev(t_tokenizer *tokenizer)
{
	return tokenizer->input[tokenizer->index - 1];
}

void handle_variable(t_sb *sb, t_tokenizer *tokenizer)
{
	int start;
	char *name;
	char *env_var;
	start = tokenizer->index;
	while (peek(tokenizer) && peek(tokenizer) != ' ' && peek(tokenizer) != '\'' && peek(tokenizer) != '"' && peek(tokenizer) != '$')
		advance(tokenizer);
	name = ft_substr(tokenizer->input, start, tokenizer->index - start);
	env_var = getenv(name);
	if (env_var)
		sb_append(sb, env_var);
	free(name);
}

void handle_double_qoute(t_sb *sb, t_tokenizer *tokenizer)
{
	char c;
	while (peek(tokenizer) && peek(tokenizer) != '"')
	{
		c = advance(tokenizer);
		if (c == '$')
			handle_variable(sb, tokenizer);
		else
			sb_append_char(sb, c);
	}
	if (!peek(tokenizer))
	{
		// handle error
	}
	else
	{
		advance(tokenizer);
	}
}

void handle_single_qoute(t_sb *sb, t_tokenizer *tokenizer)
{
	while (peek(tokenizer) && peek(tokenizer) != '\'')
		sb_append_char(sb, advance(tokenizer));
	if (peek(tokenizer) == 0)
		return; // TODO: handle error
	else
		advance(tokenizer);
}

void handle_word(t_sb *sb, t_tokenizer *tokenizer)
{
	while (peek(tokenizer) && peek(tokenizer) != ' ' && peek(tokenizer) != '\'' && peek(tokenizer) != '"' && peek(tokenizer) != '$')
		sb_append_char(sb, advance(tokenizer));
}

t_token *tokenize_string(t_tokenizer *tokenizer)
{
	char c;
	t_sb *sb;
	tokenizer->index--;

	sb = sb_create();
	if (!sb)
		return (NULL);
	while (peek(tokenizer) && peek(tokenizer) != ' ')
	{
		c = advance(tokenizer);
		if (c == '\'')
			handle_single_qoute(sb, tokenizer);
		else if (c == '$')
			handle_variable(sb, tokenizer);
		else if (c == '"')
			handle_double_qoute(sb, tokenizer);
		else
		{
			tokenizer->index--;
			handle_word(sb, tokenizer);
		}
	}
	return new_token(STRING, sb_build(sb));
}

t_token *tokenizer_next(t_tokenizer *tokenizer)
{
	char c = advance(tokenizer);
	if (c == ' ')
		return (NULL);
	else if (c == '|')
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
	else
		return tokenize_string(tokenizer);
	return (NULL);
}
