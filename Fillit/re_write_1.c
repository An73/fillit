/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_write_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:06:04 by dkotenko          #+#    #+#             */
/*   Updated: 2017/12/12 13:06:06 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	re_write_1(t_fiqure *a, t_fiqure b[4])
{
	int		num_f;
	int		element;

	num_f = 0;
	element = 0;
	while (element < 4)
	{
		a[element].x = b[element].x;
		a[element].y = b[element].y;
		element++;
	}
}
