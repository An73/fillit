/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:07:23 by dkotenko          #+#    #+#             */
/*   Updated: 2017/12/12 13:07:25 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_field		*delet(int number_fiqur, t_field *pole, int len_s)
{
	char	abc;
	int		j;

	abc = 'A' + number_fiqur;
	j = 0;
	while (1)
	{
		if (pole[j].point == abc)
			pole[j].point = '.';
		if (pole[j].y == len_s - 1 && pole[j].x == len_s - 1)
			return (pole);
		j++;
	}
	return (pole);
}
