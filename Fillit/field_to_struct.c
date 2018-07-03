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

int			max_crd(t_fiqure **f, int num)
{
	int		fiqura;
	int		element;
	int		max;

	max = 0;
	fiqura = 0;
	while (fiqura < num)
	{
		element = 0;
		while (element < 4)
		{
			if (f[fiqura][element].x > max)
				max = f[fiqura][element].x;
			if (f[fiqura][element].y > max)
				max = f[fiqura][element].y;
			element++;
		}
		fiqura++;
	}
	return (max + 1);
}

t_field		*field_to_struct(char *str, t_fiqure **f, int plus)
{
	int			num_sqr;
	int			x;
	int			y;
	int			i;
	t_field		*struct_field;

	x = 0;
	y = 0;
	i = 0;
	num_sqr = max_crd(f, num_fiqure(str)) * max_crd(f, num_fiqure(str)) + plus;
	struct_field = (t_field*)malloc(sizeof(t_field) * num_sqr);
	while (i < num_sqr)
	{
		struct_field[i].x = x;
		struct_field[i].y = y;
		struct_field[i].point = '.';
		if (ft_sqrt(num_sqr) == ++x)
		{
			x = 0;
			y++;
		}
		i++;
	}
	return (struct_field);
}
