/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:32:58 by hboutale          #+#    #+#             */
/*   Updated: 2025/03/20 12:17:31 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./frontend/tokenizer/tokenizer.h"

int main(int ac, char **av)
{
	t_tokenizer *tokenizer;
	(void)av;
	printf("number of args %d\n", ac);
	tokenizer = tokenizer_create();

	while (1)
	{
		tokenize(tokenizer);
	}
}
