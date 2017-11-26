/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_fiqure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:04:12 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/25 16:04:14 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		num_fiqure(char *str)
{
	int		i;
	int		num_fiqure;

	i = 0;
	num_fiqure = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			num_fiqure++;
		i++;
	}
	num_fiqure = (num_fiqure + 1) / 5;
	return (num_fiqure);
}
