/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:46:58 by dkotenko          #+#    #+#             */
/*   Updated: 2017/11/24 20:47:01 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FILLIT_H
# define __FT_FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct 	s_fiqure{
	int	x;
	int	y;
}				t_fiqure;

typedef struct 	t_field{
	int 	x;
	int 	y;
	char 	point;
}				t_field;

char			*fillit_string(char	*argv);/*Функция перезаписывает строку из argv в строку fillit_string*/
int				field_check(char *str);/*функция проверяет на валидность поля фигур('#', '.', '\n')*/
int				vallid_fiqure(char *str); /* Проверяет на валидность фигуры (по одному блоку) */
t_fiqure		**fiqure_to_struct(char *str);/*Записывает фигуры в структуры*/
t_fiqure		**finish_fiqur(char *str);/*включает все пред. функции*/
int				num_fiqure(char *str);/*считает количество фигур*/
int				ft_sqrt(int nb);
t_fiqure		*field_to_struct(char *str);/*Записывает минимальное поле в структуру*/

#endif