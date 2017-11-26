/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 20:35:23 by dkotenko          #+#    #+#             */
/*   Updated: 2017/10/23 21:53:53 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		sqrt;

	sqrt = 0;
	if (nb > 0)
	{
		while (sqrt * sqrt < nb)
			sqrt++;
		if (sqrt * sqrt == nb)
			return (sqrt);
		else
			return (0);
	}
	else
		return (0);
}
