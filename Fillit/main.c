/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 19:34:51 by dkotenko          #+#    #+#             */
/*   Updated: 2017/12/19 19:34:54 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_field		*pole;
	t_fiqure	**f;
	t_field		*wr;
	int			num;
	int			len_;

	num = num_fiqure(fillit_string(argv[1]));
	f = left_up(finish_fiqur(fillit_string(argv[1])), num);
	if (f != NULL)
	{
		len_ = len_side(field_to_struct(fillit_string(argv[1]), f, 0));
		pole = field_to_struct(fillit_string(argv[1]), f, 0);
		wr = assembly(f, pole, len_, num);
		argc = 1;
		while (wr == NULL)
		{
			len_ = len_side(field_to_struct(fillit_string(argv[1]), f, argc));
			pole = field_to_struct(fillit_string(argv[1]), f, argc);
			wr = assembly(f, pole, len_, num);
			argc++;
		}
		ft_print(wr, len_);
	}
}
