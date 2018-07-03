/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fiqure_to_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 13:09:58 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/25 13:10:02 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		crd_to_struct(char **str, t_fiqure fiqura[4])
{
	int		i;
	int		x;
	int		y;
	int		element;

	i = 0;
	x = 0;
	y = 0;
	element = 0;
	while (i++ < 21)
	{
		if (*(*str) == '#')
		{
			fiqura[element].x = x;
			fiqura[element].y = y;
			element++;
		}
		x++;
		if (*(*str)++ == '\n')
		{
			y++;
			x = 0;
		}
	}
}

t_fiqure	**fiqure_to_struct(char *str)
{
	int			fiqure;
	t_fiqure	**struct_fiqure;

	struct_fiqure = (t_fiqure **)malloc(sizeof(t_fiqure *) * num_fiqure(str));
	fiqure = 0;
	while (*str != '\0')
	{
		struct_fiqure[fiqure] = (t_fiqure *)malloc(sizeof(t_fiqure) * 10);
		crd_to_struct(&str, struct_fiqure[fiqure]);
		fiqure++;
	}
	return (struct_fiqure);
}
