#include <stdio.h>
#include "fillit.h"

t_field		*raz_raz(t_fiqure **fiqures, t_field *pole, int len_s, int num);
t_field		*delete(int number_fiqur, t_field *pole, int len_s);
t_field		*entry(t_fiqure *fiqura, int number_fiqur, t_field *pole);
t_fiqure	*shift(t_fiqure *fiqura, t_fiqure *backup, int len_s);
int		check(t_fiqure *fiqura, t_field *pole);
t_fiqure	*left_up(t_fiqure *fiqura);
t_fiqure 	*left_x(t_fiqure *fiqura);
void 	re_write(t_fiqure a[26][4], t_fiqure **b, int num);
void 	re_write_1(t_fiqure *a, t_fiqure b[4], int num);

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
	
	wr = raz_raz(f, pole, len_, num);
	ft_print(wr, len_);
}

t_field		*raz_raz(t_fiqure **fiqures, t_field *pole, int len_s, int num)
{
	int		number_fiqur;
	t_fiqure backup_f[26][4];

	re_write(backup_f, fiqures, num);
	number_fiqur = 0;
	while (number_fiqur < num)
	{
		//printf("fiqura = %d\nelement = 3\nx = %d\ny = %d\n", number_fiqur, backup[number_fiqur][3].x, backup[number_fiqur][3].y);
	printf("fiqura = %d\nelement = 0\nx = %d\ny = %d\n", number_fiqur, fiqures[number_fiqur][0].x, fiqures[number_fiqur][0].y);
	printf("fiqura = %d\nelement = 1\nx = %d\ny = %d\n", number_fiqur, fiqures[number_fiqur][1].x, fiqures[number_fiqur][1].y);
	printf("fiqura = %d\nelement = 2\nx = %d\ny = %d\n", number_fiqur, fiqures[number_fiqur][2].x, fiqures[number_fiqur][2].y);
	printf("fiqura = %d\nelement = 3\nx = %d\ny = %d\n", number_fiqur, fiqures[number_fiqur][3].x, fiqures[number_fiqur][3].y);
		if (check(fiqures[number_fiqur], pole) == 1)
		{
			//write(1, "a", 1);
			pole = entry(fiqures[number_fiqur], number_fiqur, pole);
			//write(1, "b", 1);
			number_fiqur++;
		}
		else
		{
			//write(1, "o", 1);
			fiqures[number_fiqur] = shift(fiqures[number_fiqur], backup_f[number_fiqur], len_s);
			//write(1, "S", 1);
			if (fiqures[number_fiqur] == NULL)
			{
				write(1, "xyu\n", 4);
				re_write_1(fiqures[number_fiqur], backup_f[number_fiqur], num);
				//fiqures[number_fiqur] = left_up(fiqures[number_fiqur]);
				write(1, "xyu1\n", 4);
				if (number_fiqur == 0)
					return (NULL);//kvadrat();
				else
				{
					number_fiqur--;
					pole = delete(number_fiqur, pole, len_s);
					shift(fiqures[number_fiqur], fiqures[number_fiqur], len_s);
				}
			}
			//write(1, "X", 1);
		}
	}
	return (pole);
}

void 	re_write_1(t_fiqure *a, t_fiqure b[4], int num)
{
	int		num_f;
	int		element;

	num_f = 0;
	element = 0;
	while (element < 4)
	{
		a[element].x = b[element].x;
		a[element].y = b[element].y;
		element++;
	}
}

void 	re_write(t_fiqure a[26][4], t_fiqure **b, int num)
{
	int		num_f;
	int		element;

	num_f = 0;
	element = 0;
	while (num_f < num)
	{
		element = 0;
		while (element < 4)
		{
			a[num_f][element].x = b[num_f][element].x;
			a[num_f][element].y = b[num_f][element].y;
			element++;
		}
		num_f++;
	}
}

t_fiqure 	*left_x(t_fiqure *fiqura)
{
	int element;

	element = 0;
	while (fiqura[element].x != 0)
	{
		element++;
		if (element == 4)
		{
			element = 0;
			while (element < 4)
			{
				fiqura[element].x--;
				element++;
			}
			element = 0;
		}
	}
	return (fiqura);
}

t_fiqure	*left_up(t_fiqure *fiqura)
{
	int element;

	element = 0;
	while (fiqura[element].x != 0)
	{
		element++;
		if (element == 4)
		{
			element = 0;
			while (element < 4)
			{
				fiqura[element].x--;
				element++;
			}
			element = 0;
		}
	}
	element = 0;
	while (fiqura[element].y != 0)
	{
		element++;
		if (element == 4)
		{
			element = 0;
			while (element < 4)
			{
				fiqura[element].y--;
				element++;
			}
			element = 0;
		}
	}
	return (fiqura);
}

t_field		*delete(int number_fiqur, t_field *pole, int len_s)
{
	char	abc;
	int		j;

	abc = 'A' + number_fiqur;
	j = 0;
	while (j)
	{
		if (pole[j].point == abc)
			pole[j].point = '.';
		if (pole[j].y == len_s - 1 && pole[j].x == len_s - 1)
			return (pole);
		j++;
	}
	return (pole);
}

t_field		*entry(t_fiqure *fiqura, int number_fiqur, t_field *pole)
{
	char	abc;
	int		element;
	int		j;

	element = 0;
	j = 0;
	abc = 'A' + number_fiqur;
	printf("                    num = %d\n", number_fiqur);
	while (element < 4)
	{
		//printf("x = %d\ny = %d\nelement = %d\n", fiqura[element].x, fiqura[element].y, element);
		//printf("xp = %d\nyp = %d\n", pole[j].x, pole[j].y);
		if (fiqura[element].x == pole[j].x && fiqura[element].y == pole[j].y)
		{
			pole[j].point = abc;
			element++;
			j = 0;
		}
		j++;
	}
	return (pole);
}

t_fiqure	*shift(t_fiqure *fiqura, t_fiqure *backup, int len_s)/* Сдвигает на одну позицию */
{
	int		element;

	element = 0;
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
				fiqura[element].y++;
				element++;
			}
		}
		else
		{
			fiqura[element].x++;
			element++;
		}
	}
	return (fiqura);
}

int		check(t_fiqure *fiqura, t_field *pole)/* Проверяет поле под фигуру */
{
	int		element;
	int		j;

	element = 0;
	j = 0;
	while (element < 4)
	{
		while (!(fiqura[element].x == pole[j].x && fiqura[element].y == pole[j].y))
			j++;
		if (pole[j].point != '.')
			return (0);
		element++;
	}
	return (1);
}



