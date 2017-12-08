#include <stdio.h>
#include "fillit.h"

int		main(int argc, char **argv)
{
	t_field *pole;
	t_fiqure **f;
	t_field *wr;
	int		num;
	int		len_;

	pole = field_to_struct(fillit_string(argv[1]));
	f = finish_fiqur(fillit_string(argv[1]));
	len_ = len_side(field_to_struct(fillit_string(argv[1])));
	num = num_fiqure(fillit_string(argv[1]));
	wr = writer(f, pole, num, len_);
	if (wr == NULL)
		printf("NULL\n");
	else
		ft_print(wr, len_);
}