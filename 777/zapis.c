/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zapis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 13:50:43 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/26 13:50:44 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_field		*zapis(t_fiqure **fiqures, t_field *pole)
{
	int			element;
	t_fiqure	**fi;
	int			j;
	char		abc;
	int			fiqure;

	fi = (t_fiqure **)malloc(sizeof(t_fiqure *) * 2);
	fi = fiqures;
	element = 0;
	j = 0;
	fiqure = 0;
	abc = 'A';
	while (fiqure < 2)
	{
		j = 0;
		write(1, "1", 1);
		fi[fiqure] = (t_fiqure *)malloc(sizeof(t_fiqure) * 4);
		while (element < 4)
		{
			write(1, "2", 1);
			while (!(fi[fiqure][element].x == pole[j].x && fi[fiqure][element].y == pole[j].y))
			{
				write(1, "+", 1);
				j++;
			}
			if (pole[j].point == '.')
			{
				write(1, "-", 1);
				element++;
			}
			else
			{
				fi[fiqure] = fiqures[fiqure];
				element = 0;
				while (element < 4)
				{
					write(1, "3", 1);
					if (fi[fiqure][element].x + 1 > 3)
					{
						if (fi[fiqure][element].y + 1 > 3)
							return (NULL);
						while (element < 4)
						{
							write(1, "4", 1);
							fi[fiqure][element].x = fiqures[fiqure][element].x;
							element++;
						}
						element = 0;
						while (element < 4)
						{
							fi[fiqure][element].y++;
							element++;
						}
						write(1, "5", 1);
					}
					else
						fi[fiqure][element].x++;
				}
				j++;
				element = 0;
			}
			//j++;
			fiqure++;
		}
	}
	element = 0;
	fiqure = 0;
	while (fiqure < 2)
	{
		while (element < 4)
		{
			j = 0;
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
	write(1, "0", 1);
	return (pole);
}
