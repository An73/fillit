/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vallid_fiqure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 13:08:58 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/25 13:09:00 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		vallid_fiqure(char *str)
{
	size_t		i;
	size_t		nexus;

	i = 0;
	nexus = 0;
	while (i < 21)
	{
		if (str[i] == '#')
		{
			if (i < 20 && str[i + 1] == '#')
				nexus++;
			if (i > 0 && str[i - 1] == '#')
				nexus++;
			if (i < 15 && str[i + 5] == '#')
				nexus++;
			if (i > 4 && str[i - 5] == '#')
				nexus++;
		}
		i++;
	}
	if (nexus == 6 || nexus == 8)
		return (1);
	return (0);
}
