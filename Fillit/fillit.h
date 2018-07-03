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

typedef struct	s_fiqure{
	int			x;
	int			y;
}				t_fiqure;

typedef struct	s_field{
	int			x;
	int			y;
	char		point;
}				t_field;

char			*fillit_string(char	*argv);
int				field_check(char *str);
int				vallid_fiqure(char *str);
t_fiqure		**fiqure_to_struct(char *str);
t_fiqure		**finish_fiqur(char *str);
int				num_fiqure(char *str);
int				ft_sqrt(int nb);
t_field			*field_to_struct(char *str, t_fiqure **f, int plus);
int				len_side(t_field *pole);
t_field			*writer(t_fiqure **fiqures, t_field *pole, int num, int len_s);
void			ft_print(t_field *finish, int len_);
t_field			*assembly(t_fiqure **fiq, t_field *pole, int len_s, int num);
void			re_write(t_fiqure a[26][4], t_fiqure **b, int num);
int				check(t_fiqure *fiq, t_field *pole);
t_field			*entry(t_fiqure **fiq, int n_fiq, t_field *pole);
t_fiqure		*shift(t_fiqure *fiqura, t_fiqure *backup, int len_s);
void			re_write_1(t_fiqure *a, t_fiqure b[4]);
t_field			*delet(int number_fiqur, t_field *pole, int len_s);
t_fiqure		**left_up(t_fiqure	**fiqura, int num);

#endif
