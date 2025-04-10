/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:04:28 by hboutale          #+#    #+#             */
/*   Updated: 2025/04/10 13:36:34 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H
#include "./../../utils/array/array.h"
#include "./../tokenizer/tokenizer.h"

typedef struct s_parser
{
	t_array *tokens;
	size_t pos;
	int error;
} t_parser;

typedef enum e_node_type
{
	NODE_COMMAND,
	NODE_PIPELINE,
	NODE_REDIR,
	NODE_HEREDOC,
	NODE_STRING
} t_node_type;

typedef struct s_command_node
{
	char *name;
	t_array *args;
} t_command_node;

typedef struct s_string_node
{
	char *value;
} t_string_node;

typedef struct s_pipe_node
{
	t_ast_node *left;
	t_ast_node *right;
} t_pipe_node;


typedef struct s_ast_node
{
	t_node_type type;
	union u_data
	{
		t_command_node *command;
		t_string_node *string;
		t_pipe_node *pipe;
	} data;
} t_ast_node;


t_parser *new_parser(t_array *tokens);
t_ast_node *parse(t_parser *parser);
t_ast_node *command(t_parser *p);
t_ast_node *primary(t_parser *p);
t_token *p_peek(t_parser *parser);
t_token *p_advance(t_parser *parser);
void p_consume(t_parser *parser, t_token_type type);
//----------------------------- Nodes

t_ast_node *node_string(char *value);
t_ast_node *node_command(char *value);
void print_ast(t_ast_node *ast);

#endif
