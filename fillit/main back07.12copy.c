#include <stdio.h>
#include "fillit.h"

t_fiqure 	**rep_fiqure(t_fiqure **old_fiq, int num_fiq, int len_s, t_fiqure **back);

int		main(int argc, char **argv)
{
	t_field *pole;
	t_fiqure **f;
	t_fiqure **back;
	t_field *wr;
	int		num;
	int		len_;
	int		k;

	k = 1;
	pole = field_to_struct(fillit_string(argv[1]));
	f = finish_fiqur(fillit_string(argv[1]));
	back = finish_fiqur(fillit_string(argv[1]));
	len_ = len_side(field_to_struct(fillit_string(argv[1])));
	num = num_fiqure(fillit_string(argv[1]));
	wr = writer(f, pole, num, len_);
	while (fiqure < num)
	{

		//write(1, "1", 1);
		f = rep_fiqure(f, (num - k), len_, back);
		if (f == NULL)
		{
			//write(1, "3", 1);
			f = back;
			//write(1, "4", 1);
			k++;
		}
		else
		{
			wr = writer(f, pole, num, len_);
		}

	}
	ft_print(wr, len_);
}

t_field		*raz_raz(t_fiqure **fiqures, t_field *pole, int len_s, int fiqure)
{
	int			element;
	t_fiqure	fi[20][500];
	int			j;
	char		abc;

	abc = 'A' + fiqure;
	j = 0;
	element = 0;
	while (element < 4)
	{
		fi[fiqure][element].x = fiqures[fiqure][element].x;
		fi[fiqure][element].y = fiqures[fiqure][element].y;
		element++;
	}
	element = 0;
	while (element < 4)
	{
		while (!(fi[fiqure][element].x == pole[j].x && fi[fiqure][element].y == pole[j].y))
			j++;
		if (pole[j].point != '.')
		{
			element = 0;
			while (element < 4)/*Функция сдвига фигуры*/
			{
				if (fi[fiqure][element].x == len_s - 1)
				{
					element = 0;
					while (element < 4)
					{
						//write(1, "1", 1);
						fi[fiqure][element].x = fiqures[fiqure][element].x;
						if (fi[fiqure][element].y == len_s - 1)
						{
							//функция пробует сдвинуть на одну позицию пред. фигуру
							//если отказ то удалить с поля (восстановить положение) и повторить с фигурой -1

							return (NULL);
						}
						fi[fiqure][element].y++;
						element++;
					}
				}
				else
				{
					//write(1, "2", 1);
					fi[fiqure][element].x++;
					element++;
				}
			}
			element = 0;
			j = 0;
		}
		else
			element++;
	}
	element = 0;
	j = 0;
	while (element < 4)
	{
		if (fi[fiqure][element].x == pole[j].x && fi[fiqure][element].y == pole[j].y)
		{
			pole[j].point = abc;
			element++;
		}
		j++;
		ft_print(pole, len_s);
		write(1, "\n", 1);
	}
	abc++;
	return (pole);
}

t_fiqure	*shift(t_fiqure *fiqura, t_field *pole)
{
	while (element < 4)
	{
		if (fiqura[element].x == len_s - 1)
		{
			element = 0;
			while (element < 4)
			{
				fiqura[element].x = backup[element].x;
				if (fiqura[element].y == len_s - 1)
					return (NULL);
				element++;
			}
			fiqura[element].y++;
			element++;
		}
		else
		{
			fiqura[element].x++;
			element++;
		}
	}
	return (fiqura)
}
		}
	}
}
