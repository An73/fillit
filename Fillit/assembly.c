/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembly.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:55:06 by dkotenko          #+#    #+#             */
/*   Updated: 2017/12/12 12:55:10 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_field		*assembly(t_fiqure **fiq, t_field *pole, int len_s, int num)
{
	int			n_fiqur;
	t_fiqure	backup_f[26][4];

	re_write(backup_f, fiq, num);
	n_fiqur = 0;
	while (n_fiqur < num)
	{
		if (fiq[n_fiqur][0].y != len_s && check(fiq[n_fiqur], pole) == 1)
			pole = entry(fiq, n_fiqur++, pole);
		else
		{
			if (fiq[n_fiqur][0].y != len_s)
				fiq[n_fiqur] = shift(fiq[n_fiqur], backup_f[n_fiqur], len_s);
			if (fiq[n_fiqur][0].y == len_s)
			{
				re_write_1(fiq[n_fiqur], backup_f[n_fiqur]);
				if (n_fiqur-- == 0)
					return (NULL);
				pole = delet(n_fiqur, pole, len_s);
				fiq[n_fiqur] = shift(fiq[n_fiqur], backup_f[n_fiqur], len_s);
			}
		}
	}
	return (pole);
}
