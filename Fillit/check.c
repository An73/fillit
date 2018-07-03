/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:01:15 by dkotenko          #+#    #+#             */
/*   Updated: 2017/12/12 13:01:17 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check(t_fiqure *fiq, t_field *pole)
{
	int		element;
	int		j;

	element = 0;
	j = 0;
	while (element < 4)
	{
		while (!(fiq[element].x == pole[j].x && fiq[element].y == pole[j].y))
			j++;
		if (pole[j].point != '.')
			return (0);
		element++;
	}
	return (1);
}
