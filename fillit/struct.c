#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct s_fiqure {
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
				printf("fiqure = %d!!!\n", fiqure);
				printf("element = %d!!!\n", element);
				printf("x = %d  ", struct_fiqure[fiqure][element].x);
				struct_fiqure[fiqure][element].y = y;
				printf("y = %d\n", struct_fiqure[fiqure][element].y);
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

int		main(int argc, char **argv)
{
	t_fiqure 	**s;
	s = fiqure_to_struct(fillit_string(argv[1]));
	printf("\n\n%d\n", s[1][2].x);
}