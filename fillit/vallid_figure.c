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

int		field_check(char *str)
{
	size_t		i; /* index*/
	size_t		hash_tag; /* counter #*/
	size_t		block;
	size_t		point; /* точка */
	size_t		enter;

	i = 0;
	block = 0;
	while (str[i] != '\0')
	{
		enter = 0;
		hash_tag = 0;
		point = 0;
		while (!(str[i] == '\n' && str[i + 1] == '\n') && str[i] != '\0')
		{
			if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
				return (0);
			else if (str[i] == '#')
				hash_tag++;
			else if (str[i] == '.')
				point++;
			else
				enter++;
			i++;
		}
		block++;
		if (block == 1)
			enter++;
		if (str[i] == '\n')
			enter++;
		if (hash_tag != 4 || point != 12 || enter != 5 || block > 26)
			return (0);
		else if (str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		vallid_fiqure(char *str) /* Проверяет на валидность фигуры один блок */
{
	size_t		i;
	size_t		nexus;

	i = 0;
	nexus = 0;
	while (i < 21)
	{
		if (str[i] == '#')
		{
			if (i < 20 && str[i + 1] == '#')
				nexus++;
			if (i > 0 && str[i - 1] == '#')
				nexus++;
			if (i < 15 && str[i + 5] == '#')
				nexus++;
			if (i > 4 && str[i - 5] == '#')
				nexus++;
		}
		i++;
	}
	if (nexus == 6 || nexus == 8)
		return (1);
	return (0);
}

char	**fiqure_to_array(char *str)
{
	char	**array;
	int		fiqure;
	int		i;
	int		num_fiqure;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			num_fiqure++;
		i++;
	}
	num_fiqure = (num_fiqure + 1) / 5; /*количество фигур (сделать отдельной функцией)*/
	array = (char **)malloc(sizeof(char*) * num_fiqure);
	fiqure = 0;
	while (*str != '\0')
	{
		i = 0;
		array[fiqure] = (char *)malloc(sizeof(char) * 21);
		while (i < 21)
			array[fiqure][i++] = *str++;
		array[fiqure][i] = '\0';
		*str = *(str + 2);
		fiqure++;
	}
	return (array);
}

int		main(int argc, char **argv)
{
	char	*str;
	int		check;
	char	**array;

	check = 1;
	if (argc == 2)
	{
		str = fillit_string(argv[1]);
		if (field_check(str) == 1)
		{
			while (*(str + 1) != '\0' && check != 0)
			{
				check = vallid_fiqure(str);
				str = str + 21;
			}
		}
		//printf("%s", fillit_string(argv[1]));
		array = fiqure_to_array(fillit_string(argv[1]));
		printf("%s", array[0]);
	}
}