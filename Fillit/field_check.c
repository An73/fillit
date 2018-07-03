/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:33:31 by dkotenko          #+#    #+#             */
/*   Updated: 2017/12/20 17:33:33 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*sub_func(char *str, size_t *hash_tag, size_t *point, size_t *enter)
{
	while (!(*str == '\n' && *(str + 1) == '\n') && *str != '\0')
	{
		if (*str != '.' && *str != '#' && *str != '\n')
			return (NULL);
		else if (*str == '#')
			*hash_tag += 1;
		else if (*str == '.')
			*point += 1;
		else
			*enter += 1;
		str++;
	}
	return (str);
}

int		field_check(char *str)
{
	size_t		hash_tag;
	size_t		block;
	size_t		point;
	size_t		enter;

	block = 0;
	while (*str != '\0')
	{
		enter = 0;
		hash_tag = 0;
		point = 0;
		str = sub_func(str, &hash_tag, &point, &enter);
		if (str == NULL)
			return (0);
		(++block == 1) ? enter++ : enter;
		(*str == '\n') ? enter++ : enter;
		if (hash_tag != 4 || point != 12 || enter != 5 || block > 26)
			return (0);
		else if (*str == '\0')
			return (1);
		str++;
	}
	return (0);
}
