# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 11:53:06 by hel-hadi          #+#    #+#              #
#    Updated: 2017/02/08 13:36:15 by hel-hadi         ###   ########.fr        #
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
		ft_puthexa/ft_hexa_size.c			\
		ft_puthexa/ft_puthexa_f.c			\
		ft_puthexa/ft_puthexa_maj_f.c		\
		ft_puthexa/ft_size_chain_hexa.c		\
		ft_puthexa/ft_size_chain_hexa_maj.c \
		ft_puthexa/tools_hexa.c 			\
		ft_puthexa/tools_hexa2.c 			\
		ft_puthexa/tools_hexa3.c 			\
		ft_puthexa/tools_hexa4.c 			\
		ft_putnbr/ft_nbr_size.c				\
		ft_putnbr/ft_nbr_size_maj.c			\
		ft_putnbr/ft_putnbr_maj_f.c			\
		ft_putnbr/ft_size_chain_nbr.c		\
		ft_putnbr/ft_size_chain_less.c 		\
		ft_putoctal/ft_oct_size.c			\
		ft_putoctal/ft_putoctal_f.c			\
		ft_putoctal/ft_putoctal_maj_f.c		\
		ft_putoctal/ft_size_chain_oct.c		\
		ft_putoctal/tools_oct.c 			\
		ft_putoctal/tools_oct2.c 			\
		ft_putpercent/ft_putpercent.c		\
		ft_putstr/ft_handle_str.c			\
		ft_putstr/ft_putstr_f.c				\
		ft_putstr/ft_putstr_maj_f.c			\
		ft_putstr/ft_size_chain_str.c		\
		ft_putstr/ft_size_chain_str_maj.c 	\
		ft_putstr/ft_str_size.c				\
		ft_putuns/ft_putuns_f.c				\
		ft_putuns/ft_putuns_maj_f.c			\
		ft_putuns/ft_size_chain_uns.c		\
		ft_putuns/ft_uns_size.c				\
		ft_putuns/tools_uns.c				\
		ft_check_spec.c						\
		ft_check_tools.c					\
		ft_check_tools2.c					\
		ft_check_tools3.c					\
		ft_putnbr/tools_nbr.c  				\
		ft_putnbr/tools_nbr2.c  			\
		ft_putbin/ft_putbin_f.c				\
		ft_putbin/ft_size_chain_bin.c 		\
		ft_putnbr/ft_putnbr_f.c				\
		ft_putnbr/ft_putnbr_f2.c   			\
		ft_printf.c							\

OBJ = $(SRC:.c=.o)
OBJ1 = objets/*.o
CC = gcc
OPT1 = -c
OPT2 = -o

all: $(NAME)
$(NAME):
		make -C libft fclean && make -C libft
		$(CC) $(FLAGS) $(OPT1) $(SRCS)
		@mkdir objets
		@mv *.o objets
		ar rc $(NAME) $(OBJ1)
		ranlib $(NAME)
		@echo "\033[36m === Creation de la libftprintf.a ===\033[0m"


clean	:
	@make clean -C libft/
	@rm -rf objets
	rm -rf *.o
	@echo "\033[31m === Suppression des fichiers objets===\033[0m"

fclean: clean
	@make fclean -C libft/
	rm -f $(NAME)
	@echo "\033[31m === Suppression du fichier executable===\033[0m"


re: fclean all
	 @echo "\033[35m === Renouvellement Librairie ====\033[0m"

.PHONY: clean fclean re
