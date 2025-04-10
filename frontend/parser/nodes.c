/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:36:35 by hboutale          #+#    #+#             */
/*   Updated: 2025/04/10 13:44:07 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

t_ast_node *node_string(char *value)
{
	t_ast_node *node;

	if (!value)
		return NULL;
	node = malloc(sizeof(t_ast_node));

	if (!node)
		return NULL;
	node->type = NODE_STRING;
	node->data.string = malloc(sizeof(t_string_node));
	if (!node->data.string)
	{
		free(node);
		return NULL;
	}
	node->data.string->value = value;
	return node;
}

t_ast_node *node_command(char *value)
{
	t_ast_node *node;

	if (!value)
		return NULL;
	node = malloc(sizeof(t_ast_node));

	if (!node)
		return NULL;
	node->type = NODE_COMMAND;
	node->data.string = 0;
	node->data.command = malloc(sizeof(t_command_node));
	if (!node->data.command)
	{
		free(node);
		return NULL;
	}
	node->data.command->args = array_create();
	if (!node->data.command->args)
	{
		free(node);
		free(node->data.command);
		return (NULL);
	}
	node->data.command->name = value;
	return node;
}

t_ast_node *pipe_commad(t_ast_node *left, t_ast_node *right)
{
	t_ast_node *node;

	node = malloc(sizeof(t_ast_node));
	if (!node)
		return (NULL);
	node->type = NODE_PIPELINE;
	node->data.pipe = malloc(sizeof(t_pipe_node));
	node->data.pipe->left = left;
	node->data.pipe->right = right;
	return node;
}
