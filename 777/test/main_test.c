#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct 	t_field{
	int 	x;
	int 	y;
	char 	point;
}				t_field;

typedef struct 	s_fiqure{
	int	x;
	int	y;
}				t_fiqure;

t_fiqure		**fiqure_to_struct(char *str)
{
	int		fiqure;
	int		i;
	int		num_fiqure;
	int		y;
	int		element;
	int		x;
	t_fiqure **struct_fiqure;

	i = 0;
	num_fiqure = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			num_fiqure++;
		i++;
	}
	num_fiqure = (num_fiqure + 1) / 5; /*количество фигур (сделать отдельной функцией)*/
	struct_fiqure = (t_fiqure **)malloc(sizeof(t_fiqure *) * num_fiqure);
	fiqure = 0;
	while (*str != '\0')
	{
		i = 0;
		y = 0;
		x = 0;
		element = 0;
		struct_fiqure[fiqure] = (t_fiqure *)malloc(sizeof(t_fiqure) * 5);
		while (i < 21)
		{
			if (*str == '#')
			{
				struct_fiqure[fiqure][element].x = x;
				struct_fiqure[fiqure][element].y = y;
				element++;
			}
			x++;
			if (*str == '\n')
			{
				y++;
				x = 0;
			}
			i++;
			str++;
		}
		*str = *(str + 2);
		fiqure++;
	}
	return (struct_fiqure);
}

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

char	*fillit_string(char	*argv) /*Функция перезаписывает строку из argv в строку fillit_string*/
{
	int		fd;
	char	buf;
	int		count;
	char	*fillit_string;

	count = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buf, 1))
		count++;
	fillit_string = (char *)malloc(sizeof(fillit_string) * (count + 1));
	if (!fillit_string)
		return (NULL);
	count = 0;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buf, 1))
	{
		fillit_string[count++] = buf;
	}
	fillit_string[count] = '\0';
	return (fillit_string);
}

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

t_field	*field_to_struct(char *str)
{
	int			num_sqr;
	int			x;
	int			y;
	int			i;
	t_field		*struct_field;

	x = 0;
	y = 0;
	i = 0;
	num_sqr = num_fiqure(str);
	if (num_sqr > 4)
	{
		num_sqr = num_sqr * 4;
		while (ft_sqrt(num_sqr) == 0)
			num_sqr++;
	}
	else
		num_sqr = 16;
	struct_field = (t_field*)malloc(sizeof(t_field) * num_sqr);
	while (i < num_sqr)
	{
		struct_field[i].x = x;
		struct_field[i].y = y;
		struct_field[i].point = '.';
		x++;
		if (ft_sqrt(num_sqr) == x)
		{
			x = 0;
			y++;
		}
		i++;
	}
	return (struct_field);
}

t_field		*zapis(t_fiqure **fiqures, t_field *pole)
{
	int			element;
	t_fiqure	**fi;
	int			j;
	char		abc;
	int			fiqure;

	fi = (t_fiqure **)malloc(sizeof(t_fiqure *) * 2);
	fi = fiqures;
	j = 0;
	fiqure = 0;
	abc = 'A';
	while (fiqure < 3)
	{
		j = 0;
		fi[fiqure] = fiqures[fiqure];
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
					write(1, "3", 1);
					if (fi[fiqure][element].x + 1 > 3)
					{
						if (fi[fiqure][element].y + 1 > 3)
							return (NULL);
						while (element < 4)
						{
							write(1, "4", 1);
							fi[fiqure][element].x = fiqures[fiqure][element].x;
							fi[fiqure][element].y++;
							element++;
						}
						element = 0;
						/*while (element < 4)
						{
							fi[fiqure][element].y++;
							element++;
						}*/
						write(1, "5", 1);
					}
					else
						fi[fiqure][element].x++;
				}
				element = -1;
			}
			else
				element++;
		}
		fiqure++;
	}
	fiqure = 0;
	while (fiqure < 3)
	{
		j = 0;
		element = 0;
		while (element < 4)
		{
			if (fi[fiqure][element].x == pole[j].x && fi[fiqure][element].y == pole[j].y)
			{
				pole[j].point = abc;
				element++;
			}
			j++;
		}
		fiqure++;
		abc++;
	}
	return (pole);
}

int		main(int argc, char **argv)
{
	t_field *s;
	t_fiqure **f;
	t_field *zap;
	int		i;

	i = 0;
	s = field_to_struct(fillit_string(argv[1]));
	f = fiqure_to_struct(fillit_string(argv[1]));
	printf("x = %d\n", f[1][1].y);
	zap = zapis(f, s);
	while (i < 16)
	{
		printf("%c", zap[i].point);
		if((i + 1) % 4 == 0)
			printf("\n");
		i++;
	}
}
