/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:19:32 by hboutale          #+#    #+#             */
/*   Updated: 2025/04/10 13:38:13 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

t_parser *new_parser(t_array *tokens)
{
	t_parser *parser;

	if (!tokens)
		return (NULL);
	parser = malloc(sizeof(t_parser));
	parser->pos = 0;
	parser->tokens = tokens;
	parser->error = 0;
	return (parser);
}

t_token *p_peek(t_parser *parser)
{
	if (parser->pos >= parser->tokens->len)
		return (NULL);
	return parser->tokens->arr[parser->pos];
}

t_token *p_advance(t_parser *parser)
{
	t_token *current;

	current = p_peek(parser);
	if (!current)
		return (NULL);
	parser->pos++;
	return (current);
}

void p_consume(t_parser *parser, t_token_type type)
{
	t_token *current;

	current = p_peek(parser);
	if (!current)
	{
		printf("Unexpected EOF\n");
		parser->error = 1;
		return;
	}
	if (current->type != type)
	{
		printf("Unexpected token %d, expected %d", current->type, type);
		parser->error = 1;
		return;
	}
	p_advance(parser);
}

t_ast_node *parse(t_parser *parser)
{
	return command(parser);
}

t_ast_node *p_pipe(t_parser *p) {
	t_ast_node *left;
	t_ast_node *right;

	left = command(p);
	if (p_peek(p) && p_peek(p)->type == PIPE) {
		right = command(p);

		left = 
	}
}

t_ast_node *command(t_parser *p)
{
	t_ast_node *name;
	t_ast_node *command;

	name = primary(p);
	if (!name)
		return (NULL);
	command = node_command(name->data.string->value);
	while (p_peek(p) && p_peek(p)->type == STRING)
	{
		array_push(command->data.command->args, node_string(p_advance(p)->value));
	}
	return command;
}

t_ast_node *primary(t_parser *p)
{
	if (p_peek(p) && p_peek(p)->type == STRING)
		return node_string(p_advance(p)->value);
	return (NULL);
}

void print_ast(t_ast_node *ast)
{
	int i;
	t_ast_node *arg;
	if (ast->type == NODE_COMMAND)
	{
		printf("(command %s with args ", ast->data.command->name);
		i = 0;
		while (i < ast->data.command->args->len)
		{
			arg = ast->data.command->args->arr[i];
			printf(" %s ", arg->data.string->value);
			i++;
		}
		printf(")\n");
	}
	else if (ast->type == NODE_STRING)
	{
		printf("STRING(%s)\n", ast->data.string->value);
	}
}
