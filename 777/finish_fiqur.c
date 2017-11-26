/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_fiqur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 13:16:38 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/25 13:16:39 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_fiqure	**finish_fiqur(char *argv)
{
	int			check;
	char		*str;

	str = fillit_string(argv);
	check = 1;
	if (field_check(str) == 1)
	{
		while(*(str + 1) != '\0' && check != 0)
		{
			check = vallid_fiqure(str);
			str = str + 21;
		}
		if (check == 1)
			return (fiqure_to_struct(fillit_string(argv)));
		else
		{
			write(1, "error\n", 6);
			return (NULL);
		}
	}
	write(1, "error\n", 6);
	return (NULL);
}
