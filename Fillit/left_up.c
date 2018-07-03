/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:10:25 by dkotenko          #+#    #+#             */
/*   Updated: 2017/12/13 14:10:32 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fiqure	*left(t_fiqure *fiq)
{
	int		element;

	while (1)
	{
		element = 0;
		while (element < 4)
		{
			if (fiq[element].x == 0)
				return (fiq);
			element++;
		}
		element = 0;
		while (element < 4)
		{
			fiq[element].x--;
			element++;
		}
	}
	return (fiq);
}

t_fiqure	*up(t_fiqure *fiq)
{
	int		element;

	while (1)
	{
		element = 0;
		while (element < 4)
		{
			if (fiq[element].y == 0)
				return (fiq);
			element++;
		}
		element = 0;
		while (element < 4)
		{
			fiq[element].y--;
			element++;
		}
	}
	return (fiq);
}

t_fiqure	**left_up(t_fiqure **fiqura, int num)
{
	int		num_fiqur;

	num_fiqur = 0;
	if (fiqura == NULL)
		return (NULL);
	while (num_fiqur < num)
	{
		fiqura[num_fiqur] = left(fiqura[num_fiqur]);
		fiqura[num_fiqur] = up(fiqura[num_fiqur]);
		num_fiqur++;
	}
	return (fiqura);
}
