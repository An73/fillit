#include <stdio.h>
#include "fillit.h"

int		main(int argc, char **argv)
{
	t_fiqure 	**s;
	s = finish_fiqur(argv[1]);
	printf("\n\n%d\n", s[0][0].y);
}