/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 13:07:07 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/25 13:07:10 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		field_check(char *str)
{
	size_t		i; /* index*/
	size_t		hash_tag; /* counter #*/
	size_t		block;
	size_t		point; /* точка */
	size_t		enter;

	i = 0;
	block = 0;
	while (str[i] != '\0')
	{
		enter = 0;
		hash_tag = 0;
		point = 0;
		while (!(str[i] == '\n' && str[i + 1] == '\n') && str[i] != '\0')
		{
			if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
				return (0);
			else if (str[i] == '#')
				hash_tag++;
			else if (str[i] == '.')
				point++;
			else
				enter++;
			i++;
		}
		block++;
		if (block == 1)
			enter++;
		if (str[i] == '\n')
			enter++;
		if (hash_tag != 4 || point != 12 || enter != 5 || block > 26)
			return (0);
		else if (str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
