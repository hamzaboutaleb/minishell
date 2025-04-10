/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:32:58 by hboutale          #+#    #+#             */
/*   Updated: 2025/04/09 17:13:00 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./frontend/tokenizer/tokenizer.h"
#include "./frontend/parser/parser.h"

int main(int ac, char **av)
{
	t_tokenizer *tokenizer;
	t_parser *parser;
	t_array *tokens;
	t_ast_node *ast;
	(void)av;
	while (1)
	{
		tokenizer = tokenizer_create();
		tokens = tokenize(tokenizer);
		if (!tokens)
			continue;
		parser = new_parser(tokens);
		ast = parse(parser);
		print_ast(ast);
	}
}
