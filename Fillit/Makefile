# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkravets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/19 16:16:45 by vkravets          #+#    #+#              #
#    Updated: 2017/12/19 16:16:53 by vkravets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CFILES = *.c

OFILES = $(CFILES:.c=.o)


all: $(NAME)

%.o: %.c
		gcc -c $? $(FILES) -Wall -Wextra -Werror

$(NAME): $(OFILES)
		gcc -Wall -Wextra -Werror $(OFILES) -o $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean