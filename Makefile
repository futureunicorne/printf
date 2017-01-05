# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 18:06:46 by hel-hadi          #+#    #+#              #
#    Updated: 2017/01/05 18:34:15 by hel-hadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME    =   libft.a
CC      =   gcc
DIR_LIB =   ./
LIB     =   ft_add_elem.c		\
			ft_atoi.c			\
			ft_bzero.c			\
			ft_count_len.c		\
			ft_count_num.c		\
			ft_count_words.c	\
			ft_del_elem.c		\
			ft_free_lst.c		\
			ft_get_elem.c		\
			ft_init_lst.c		\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_itoa.c			\
			ft_len_space_out.c	\
			ft_lstadd.c			\
			ft_lstdel.c			\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_lstnew.c			\
			ft_memalloc.c		\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memdel.c			\
			ft_memmove.c		\
			ft_memset.c			\
			ft_memset_base.c	\
			ft_print_lst.c		\
			ft_putchar.c		\
			ft_putchar_fd.c		\
			ft_putendl.c		\
			ft_putendl_fd.c		\
			ft_putnbr.c			\
			ft_putnbr_fd.c		\
			ft_putstr.c			\
			ft_putstr_fd.c		\
			ft_strcat.c			\
			ft_strchr.c			\
			ft_strclr.c			\
			ft_strcmp.c			\
			ft_strcpy.c			\
			ft_strdel.c			\
			ft_strdup.c			\
			ft_strequ.c			\
			ft_striter.c		\
			ft_striteri.c		\
			ft_strjoin.c		\
			ft_strlcat.c		\
			ft_strlen.c			\
			ft_strmap.c			\
			ft_strmapi.c		\
			ft_strncat.c		\
			ft_strnchr.c		\
			ft_strncmp.c		\
			ft_strncpy.c		\
			ft_strnequ.c		\
			ft_strnew.c			\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_strsplit.c		\
			ft_strstr.c			\
			ft_strsub.c			\
			ft_strsub_b.c		\
			ft_strtrim.c		\
			ft_tolower.c		\
			ft_toupper.c		\
OBJS    =   $(LIB:.c=.o)
INCLUDE =   -I.
CFLAGS  +=  -Wall -Wextra -Werror
all     :   $(NAME)
$(NAME) :   $(OBJS)
    @$(AR) rcs $(NAME) $(OBJS)
%.o     :   %.c
    @$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)
clean   :
    @$(RM) $(OBJS)
fclean  :   clean
    @$(RM) $(NAME)
re      :   fclean all
depend  :   $(LIB)
    makedepend -- -Y. -- $^
.PHONY  :   depend clean
# DO NOT DELETE THIS LINE -- make depend depends on it.
ft_add_elem.c: libft.h
ft_atoi.c: libft.h
ft_bzero.c: libft.h
ft_count_len.c: libft.h
ft_count_num.c: libft.h
ft_count_words.c: libft.h
ft_del_elem.c: libft.h
ft_free_lst.c: libft.h
ft_get_elem.c: libft.h
ft_init_lst.c: libft.h
ft_isalnum.c: libft.h
ft_isalpha.c: libft.h
ft_isascii.c: libft.h
ft_isdigit.c: libft.h
ft_isprint.c: libft.h
ft_itoa.c: libft.h
ft_len_space_out.c: libft.h
ft_lstadd.c: libft.h
ft_lstdel.c: libft.h
ft_lstdelone.c: libft.h
ft_lstiter.c: libft.h
ft_lstmap.c: libft.h
ft_lstnew.c: libft.h
ft_memalloc.c: libft.h
ft_memccpy.c: libft.h
ft_memchr.c: libft.h
ft_memcmp.c: libft.h
ft_memcpy.c: libft.h
ft_memdel.c: libft.h
ft_memmove.c: libft.h
ft_memset.c: libft.h
ft_memset_base.c: libft.h
ft_print_lst.c: libft.h
ft_putchar.c: libft.h
ft_putchar_fd.c: libft.h
ft_putendl.c: libft.h
ft_putendl_fd.c: libft.h
ft_putnbr.c: libft.h
ft_putnbr_fd.c: libft.h
ft_putstr.c: libft.h
ft_putstr_fd.c: libft.h
ft_strcat.c: libft.h
ft_strchr.c: libft.h
ft_strclr.c: libft.h
ft_strcmp.c: libft.h
ft_strcpy.c: libft.h
ft_strdel.c: libft.h
ft_strdup.c: libft.h
ft_strequ.c: libft.h
ft_striter.c: libft.h
ft_striteri.c: libft.h
ft_strjoin.c: libft.h
ft_strlcat.c: libft.h
ft_strlen.c: libft.h
ft_strmap.c: libft.h
ft_strmapi.c: libft.h
ft_strncat.c: libft.h
ft_strnchr.c: libft.h
ft_strncmp.c: libft.h
ft_strncpy.c: libft.h
ft_strnequ.c: libft.h
ft_strnew.c: libft.h
ft_strnstr.c: libft.h
ft_strrchr.c: libft.h
ft_strsplit.c: libft.h
ft_strstr.c: libft.h
ft_strsub.c: libft.h
ft_strsub_b.c: libft.h
ft_strtrim.c: libft.h
ft_tolower.c: libft.h
ft_toupper.c: libft.h