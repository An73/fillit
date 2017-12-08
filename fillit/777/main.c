#include <stdio.h>
#include "fillit.h"

t_fiqure	**sdv(t_fiqure **fiq, int fiqure, int len_s)
{
	int		xback[4];
	int		element;

	write(1, "/", 1);
	element = 0;
	while (element < 4)
	{
		write(1, "z", 1);
		printf("f = %d\n", fiq[fiqure][element].x);
		xback[element] = fiq[fiqure][element].x;
		element++;
	}
	write(1, "s", 1);
	element = 0;
	while (element < 4)/*Функция сдвига фигуры*/
	{
		if (fiq[fiqure][element].x == len_s - 1)
		{
			element = 0;
			while (element < 4)
			{
				fiq[fiqure][element].x = xback[element];
				if (fiq[fiqure][element].y == len_s - 1)
					return (NULL);
				fiq[fiqure][element].y++;
				element++;
			}
		}
		else
		{
			//write(1, "2", 1);
			fiq[fiqure][element].x++;
			element++;
		}
	}
	return (fiq);
}

int		main(int argc, char **argv)
{
	t_field *pole;
	t_fiqure **f;
	t_fiqure **fiq;
	t_field *wr;
	int		i;
	int		num;
	int		len_;
	int		kkk;

	kkk = 1;
	i = 0;
	pole = field_to_struct(fillit_string(argv[1]));
	f = finish_fiqur(fillit_string(argv[1]));
	len_ = len_side(field_to_struct(fillit_string(argv[1])));
	num = num_fiqure(fillit_string(argv[1]));
	wr = writer(f, pole, num, len_);
	while (wr == NULL)
	{
		printf("kkk = %d\n", kkk);
		fiq = sdv(f, (len_ - kkk), len_);
		if (fiq == NULL)
		{
			write(1, "2", 1);
			fiq = finish_fiqur(fillit_string(argv[1]));
			kkk++;
		}
		else
			wr = writer(fiq, pole, num, len_);
		write(1, "3", 1);
		//printf("NULL\n");
	}
	while (i < len_ * len_ && wr != NULL)
	{
		printf("%c", wr[i].point);
		if((i + 1) % len_ == 0)
			printf("\n");
		i++;
	}
}