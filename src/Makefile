# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 11:53:06 by hel-hadi          #+#    #+#              #
#    Updated: 2017/01/25 09:29:09 by hel-hadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
PREF = ./srcs/
HEADER = ./include/
SRCS = 	ft_putadd/ft_add_size.c				\
		ft_putadd/ft_handle_add.c			\
		ft_putadd/ft_putadd_f.c				\
		ft_putadd/ft_size_chain_add.c		\
		ft_putchar/ft_char_size.c			\
		ft_putchar/ft_handle_char.c			\
		ft_putchar/ft_putchar_f.c			\
		ft_putchar/ft_putchar_maj_f.c		\
		ft_putchar/ft_size_chain_char.c		\
		ft_puthexa/ft_handle_hexa.c			\
		ft_puthexa/ft_hexa_size.c			\
		ft_puthexa/ft_puthexa_f.c			\
		ft_puthexa/ft_puthexa_maj_f.c		\
		ft_puthexa/ft_size_chain_hexa.c		\
		ft_putnbr/ft_handle_nbr.c			\
		ft_putnbr/ft_handle_nbr_maj.c		\
		ft_putnbr/ft_nbr_size.c				\
		ft_putnbr/ft_nbr_size_maj.c			\
		ft_putnbr/ft_putnbr_maj_f.c			\
		ft_putnbr/ft_size_chain_nbr.c		\
		ft_putoctal/ft_handle_oct.c			\
		ft_putoctal/ft_oct_size.c			\
		ft_putoctal/ft_putoctal_f.c			\
		ft_putoctal/ft_putoctal_maj_f.c		\
		ft_putoctal/ft_size_chain_oct.c		\
		ft_putpercent/ft_putpercent.c		\
		ft_putstr/ft_handle_str.c			\
		ft_putstr/ft_putstr_f.c				\
		ft_putstr/ft_putstr_maj_f.c			\
		ft_putstr/ft_size_chain_str.c		\
		ft_putstr/ft_str_size.c				\
		ft_putuns/ft_handle_uns.c			\
		ft_putuns/ft_putuns_f.c				\
		ft_putuns/ft_putuns_maj_f.c			\
		ft_putuns/ft_size_chain_uns.c		\
		ft_putuns/ft_uns_size.c				\
		ft_check_spec.c						\
		ft_check_tools.c					\
		ft_check_tools2.c					\
		ft_printf.c							\

OBJ = $(SRC:.c=.o)
OBJ1 = objets/*.o
CC = gcc
OPT1 = -c
OPT2 = -o

all: $(NAME)
$(NAME):
		make -C ../libft fclean && make -C ../libft
		$(CC) $(FLAGS) $(OPT1) $(SRCS)
		@mkdir objets
		@mv *.o objets
		ar rc $(NAME) $(OBJ1)
		ranlib $(NAME)
		@rm -rf objets
		@echo "\033[34m === Creation de la libft.a ===\033[0m"


clean	:
	rm -rf *.o
	@echo "\033[31m === Suppression des fichiers objets===\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[31m === Suppression du fichier executable===\033[0m"


re: fclean all
	 @echo "\033[35m === Renouvellement Librairie ====\033[0m"

.PHONY: clean fclean re