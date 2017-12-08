/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:47:58 by dkotenko          #+#    #+#             */
/*   Updated: 2017/12/04 12:48:03 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_field		*writer(t_fiqure **fiqures, t_field *pole, int num, int len_s)
{
	int			element;
	t_fiqure	fi[20][500];
	int			j;
	char		abc;
	int			fiqure;

	j = 0;
	fiqure = 0;
	abc = 'A';
	while (fiqure < num)
	{
		j = 0;
		element = 0;
		while (element < 4)
		{
			fi[fiqure][element].x = fiqures[fiqure][element].x;
			fi[fiqure][element].y = fiqures[fiqure][element].y;
			element++;
		}
		element = 0;
		while (element < 4)
		{
			while (!(fi[fiqure][element].x == pole[j].x && fi[fiqure][element].y == pole[j].y))
				j++;
			if (pole[j].point != '.')
			{
				element = 0;
				while (element < 4)/*Функция сдвига фигуры*/
				{
					if (fi[fiqure][element].x == len_s - 1)
					{
						element = 0;
						while (element < 4)
						{
							//write(1, "1", 1);
							fi[fiqure][element].x = fiqures[fiqure][element].x;
							if (fi[fiqure][element].y == len_s - 1)
								return (NULL);
							fi[fiqure][element].y++;
							element++;
						}
					}
					else
					{
						//write(1, "2", 1);
						fi[fiqure][element].x++;
						element++;
					}
				}
				element = 0;
				j = 0;
			}
			else
				element++;
		}
		element = 0;
		j = 0;
		while (element < 4)
		{
			if (fi[fiqure][element].x == pole[j].x && fi[fiqure][element].y == pole[j].y)
			{
				pole[j].point = abc;
				element++;
			}
			j++;
		}
		fiqure++;
		abc++;
	}
	return (pole);
}
