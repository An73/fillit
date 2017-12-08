#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int		vallid_fiqure(char *str)
{
	size_t		i;
	size_t		nexus;

	i = 0;
	while (str[i] != '\0')
	{
		nexus = 0;
		while (!(str[i] == '\n' && str[i + 1] == '\n') && str[i] != '\0')
		{
			while (str[i] != '#')
				i++;
			if (str[i + 1] == '#')
				nexus++;
			if (str[i - 1] == '#')
				nexus++;
			if (str[i + 5] == '#')
				nexus++;
			if (str[i - 5] == '#')
				nexus++;
			i++;
		}
		if (!(nexus == 6 || nexus == 8))
			return (0);
		if (str[i] == '\0')
			return (1);
		i++;
	}
}