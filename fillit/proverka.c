
int		proverka(char *str)
{
	while (str[i] != '\0')
	{
		while (str[i] != '\n' && str[i + 1] != '\n')
		{
			if (str[i] != '.' || str[i] != '#')
				return (0)
			else if (str[i] == '#')
				element++; //# counter
			i++;
		}
		if (element != 4)
			return (0);
		block++; // фигура (блок хули )
		else if (block > 26)
			return (0);
		i++;
	}
	return (1);
}


int		field_check(char *str)
{
	size_t		i; /* index*/
	size_t		hash_tag; /* counter #*/
	size_t		block;
	size_t		point; /*точка*/

	i = 0;
	block = 0;
	point = 0;
	while (str[i] != '\0')
	{
		hash_tag = 0;
		while (!(str[i] == '\n' && str[i + 1] == '\n') && str[i] != '\0')
		{
			if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			{
				return (0);
			}
			else if (str[i] == '#')
				hash_tag++;
			else if (str[i] == '.')
				point++;
			i++;
		}
		if (hash_tag != 4 || point != 12)
			return (0);
		block++;
		if (block >= 26)
			return (0);
		if (str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

/*#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char	*fillit_string(char	*argv) //Функция перезаписывает строку из argv в строку fillit_string
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
		fillit_string[count++] = buf;
	fillit_string[count] = '\0';
	return (fillit_string);
}

int		field_check(char *str)
{
	size_t		i;  //index
	size_t		hash_tag; // counter #
	size_t		block;
	size_t		point; // точка 
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
			//if (str[i] == '\0')
				//return (1);
			write (1, "1", 1);
			if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			{
				printf("palumba");
				printf("i = %zu\n", i);
				return (0);
			}
			write (1, "2", 1);
			if (str[i] == '#')
				hash_tag++;
			else if (str[i] == '.')
				point++;
			else if (str[i] == '\n')
				enter++;
			i++;
		}
		if (block == 0)
			enter++;
		if (str[i] == '\n')
			enter++;
		printf("i = %zu\n", i);
		write (1, "3", 1);
		printf("e = %zu\n", enter);
		if (hash_tag != 4 || point != 12 || enter != 5)
			return (0);
		write (1, "4", 1);
		block++;
		write (1, "5", 1);
		printf("block = %zu\n", block);
		if (block > 26)
			return (0);
		if (str[i] == '\0')
			return (1);
		i++;
		write (1, "6", 1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	*str;

	if (argc == 2)
	{
		str = fillit_string(argv[1]);
		printf("%s\n", str);
		printf("\n%d\n", field_check(str));
	}
}*/ <----BACKUP