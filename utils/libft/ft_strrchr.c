/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:02:39 by hboutale          #+#    #+#             */
/*   Updated: 2024/11/05 11:59:37 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *str, int c)
{
	int		i;
	char	*result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			result = &(str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (result);
}
