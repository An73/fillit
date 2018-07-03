/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:44:48 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/24 20:44:53 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*fillit_string(char *argv)
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
