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

t_fiqure		**fiqure_to_struct(char *str)
{
	int		fiqure;
	int		i;
	int		num_fiqure;
	int		y;
	int		element;
	int		x;
	t_fiqure **struct_fiqure;

	i = 0;
	num_fiqure = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			num_fiqure++;
		i++;
	}
	num_fiqure = (num_fiqure + 1) / 5; /*количество фигур (сделать отдельной функцией)*/
	struct_fiqure = (t_fiqure **)malloc(sizeof(t_fiqure *) * num_fiqure);
	fiqure = 0;
	while (*str != '\0')
	{
		i = 0;
		y = 0;
		x = 0;
		element = 0;
		struct_fiqure[fiqure] = (t_fiqure *)malloc(sizeof(t_fiqure) * 5);
		while (i < 21)
		{
			if (*str == '#')
			{
				struct_fiqure[fiqure][element].x = x;
				struct_fiqure[fiqure][element].y = y;
				element++;
			}
			x++;
			if (*str == '\n')
			{
				y++;
				x = 0;
			}
			i++;
			str++;
		}
		*str = *(str + 2);
		fiqure++;
	}
	return (struct_fiqure);
}
