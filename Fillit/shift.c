/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:04:27 by dkotenko          #+#    #+#             */
/*   Updated: 2017/12/12 13:04:30 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fiqure	*shift(t_fiqure *fiqura, t_fiqure *backup, int len_s)
{
	int		element;

	element = 0;
	while (element < 4)
	{
		if (fiqura[element].x == len_s - 1)
		{
			element = 0;
			while (element < 4)
			{
				fiqura[element].x = backup[element].x;
				if (fiqura[element].y == len_s - 1)
				{
					fiqura[0].y = len_s;
					return (fiqura);
				}
				fiqura[element].y++;
				element++;
			}
		}
		else
			fiqura[element++].x++;
	}
	return (fiqura);
}
