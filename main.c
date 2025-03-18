/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:32:58 by hboutale          #+#    #+#             */
/*   Updated: 2025/03/18 13:37:26 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./frontend/tokenizer/tokenizer.h"

int main()
{
	t_tokenizer *tokenizer;

	tokenizer = tokenizer_create();

	while (1)
	{
		tokenize(tokenizer);
	}
}
