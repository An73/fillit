
char	**fiqure_to_array(char *str)
{
	char	**array;
	int		fiqure;
	int		i;
	int		num_fiqure;

	while (str[i] == '\0')
	{
		if (str[i] == '\n')
			num_fiqure++;
		i++;
	}
	num_fiqure = (num_fiqure + 1) / 5; /*количество фигур*/
	array = (char **)malloc(sizeof(char*) * num_fiqure);
	fiqure = 0;
	while (*str != '\0')
	{
		i = 0;
		while (!(*str == '\n' && *(str + 1) == '\n') && *str != '\0')
		{
			array[fiqure] = (char *)malloc(sizeof(char) * 21);
			array[fiqure][i++] = *str++;
		}
		array[fiqure][i] = '\0';
		*str = *(str + 2);
		fiqure++;
	}
	return (array);
}