# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 18:14:05 by hel-hadi          #+#    #+#              #
#    Updated: 2017/01/24 17:01:40 by hel-hadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_printf
PREF = ./srcs/
HEADER = ./include/
OBJ = $(SRC:.c=.o)
OBJ1 = objets/*.o
CC = gcc
OPT1 = -c
OPT2 = -o

all: $(NAME)

$(NAME):
		make -C printf_src/ fclean && make -C printf_src/
		gcc  -I printf_src/includes -o printf.o -c printf_src/ft_printf.c
		gcc  -I printf_src/includes -o main.o -c main.c
		gcc -o test_printf main.o printf.o -I/includes -L printf_src/ -lftprintf
		@echo "\033[34m === Creation de l executable ===\033[0m"



clean	:
	rm -rf *.o
	@echo "\033[31m === Suppression des fichiers objets===\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[31m === Suppression du fichier executable===\033[0m"


re: fclean all
	 @echo "\033[35m === Renouvellement Librairie ====\033[0m"

.PHONY: clean fclean re
