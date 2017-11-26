/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_to_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:02:14 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/25 16:02:16 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fiqure	*field_to_struct(char *str)
{
	int		num_sqr;
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	num_sqr = num_fiqure(str);
	if (num_sqr > 4)
	{
		num_sqr = num_sqr * 4;
		while (ft_sqrt(num_sqr) == 0)
			num_sqr++;
	}
	else
		num_sqr = 16;
	struct_field = (t_field*)malloc(sizeof(t_field) * num_sqr);
	while (i < num_sqr)
	{
		struct_field[i].x = x;
		struct_field[i].y = y;
		struct_field[i].point = '.';
		x++;
		if (ft_sqrt(num_sqr) == x)
		{
			x = 0;
			y++;
		}
		i++;
	}
	return (struct_field);
}
