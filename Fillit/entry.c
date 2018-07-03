/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:02:49 by dkotenko          #+#    #+#             */
/*   Updated: 2017/12/12 13:02:51 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_field		*entry(t_fiqure **fiq, int n_fiq, t_field *pole)
{
	char	abc;
	int		elem;
	int		j;

	elem = 0;
	j = 0;
	abc = 'A' + n_fiq;
	while (elem < 4)
	{
		if (fiq[n_fiq][elem].x == pole[j].x && fiq[n_fiq][elem].y == pole[j].y)
		{
			pole[j].point = abc;
			elem++;
			j = 0;
		}
		j++;
	}
	return (pole);
}
