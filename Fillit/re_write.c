/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:59:02 by dkotenko          #+#    #+#             */
/*   Updated: 2017/12/12 12:59:06 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	re_write(t_fiqure a[26][4], t_fiqure **b, int num)
{
	int		num_f;
	int		element;

	num_f = 0;
	element = 0;
	while (num_f < num)
	{
		element = 0;
		while (element < 4)
		{
			a[num_f][element].x = b[num_f][element].x;
			a[num_f][element].y = b[num_f][element].y;
			element++;
		}
		num_f++;
	}
}
