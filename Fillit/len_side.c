/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_side.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:10:59 by dkotenko          #+#    #+#             */
/*   Updated: 2017/12/05 14:11:02 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		len_side(t_field *pole)
{
	int	i;

	i = 0;
	while (pole[i].point == '.')
		i++;
	return (ft_sqrt(i));
}
