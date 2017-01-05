# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfour <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 11:19:49 by vfour             #+#    #+#              #
#    Updated: 2016/12/02 14:53:11 by vfour            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME    =   libft.a
CC      =   gcc
DIR_LIB =   ./
LIB     =   $(DIR_LIB)ft_atoi.c             \
            $(DIR_LIB)ft_atoi_base.c        \
            $(DIR_LIB)ft_bzero.c            \
            $(DIR_LIB)ft_isalnum.c          \
            $(DIR_LIB)ft_isalpha.c          \
            $(DIR_LIB)ft_isascii.c          \
            $(DIR_LIB)ft_isdigit.c          \
            $(DIR_LIB)ft_isprint.c          \
            $(DIR_LIB)ft_itoa.c             \
            $(DIR_LIB)ft_lstadd.c           \
            $(DIR_LIB)ft_lstcreateelem.c    \
            $(DIR_LIB)ft_lstdel.c           \
            $(DIR_LIB)ft_lstdelone.c        \
            $(DIR_LIB)ft_lstiter.c          \
            $(DIR_LIB)ft_lstmap.c           \
            $(DIR_LIB)ft_lstnew.c           \
            $(DIR_LIB)ft_lstpop.c           \
            $(DIR_LIB)ft_lstpushback.c      \
            $(DIR_LIB)ft_lstpushfront.c     \
            $(DIR_LIB)ft_lstreverse.c       \
            $(DIR_LIB)ft_lstsize.c          \
            $(DIR_LIB)ft_memalloc.c         \
            $(DIR_LIB)ft_memccpy.c          \
            $(DIR_LIB)ft_memchr.c           \
            $(DIR_LIB)ft_memcmp.c           \
            $(DIR_LIB)ft_memcpy.c           \
            $(DIR_LIB)ft_memdel.c           \
            $(DIR_LIB)ft_memmove.c          \
            $(DIR_LIB)ft_memset.c           \
            $(DIR_LIB)ft_putchar.c          \
            $(DIR_LIB)ft_putchar_fd.c       \
            $(DIR_LIB)ft_putendl.c          \
            $(DIR_LIB)ft_putendl_fd.c       \
            $(DIR_LIB)ft_putnbr.c           \
            $(DIR_LIB)ft_putnbr_fd.c        \
            $(DIR_LIB)ft_putstr.c           \
            $(DIR_LIB)ft_putstr_fd.c        \
            $(DIR_LIB)ft_strcat.c           \
            $(DIR_LIB)ft_strchr.c           \
            $(DIR_LIB)ft_strclr.c           \
            $(DIR_LIB)ft_strcmp.c           \
            $(DIR_LIB)ft_strcpy.c           \
            $(DIR_LIB)ft_strdel.c           \
            $(DIR_LIB)ft_strdup.c           \
            $(DIR_LIB)ft_strequ.c           \
            $(DIR_LIB)ft_striter.c          \
            $(DIR_LIB)ft_striteri.c         \
            $(DIR_LIB)ft_strjoin.c          \
            $(DIR_LIB)ft_strlcat.c          \
            $(DIR_LIB)ft_strlen.c           \
            $(DIR_LIB)ft_strmap.c           \
            $(DIR_LIB)ft_strmapi.c          \
            $(DIR_LIB)ft_strncat.c          \
            $(DIR_LIB)ft_strncmp.c          \
            $(DIR_LIB)ft_strncpy.c          \
            $(DIR_LIB)ft_strnequ.c          \
            $(DIR_LIB)ft_strnew.c           \
            $(DIR_LIB)ft_strnlen.c          \
            $(DIR_LIB)ft_strnstr.c          \
            $(DIR_LIB)ft_strrchr.c          \
            $(DIR_LIB)ft_strsplit.c         \
            $(DIR_LIB)ft_strstr.c           \
            $(DIR_LIB)ft_strsub.c           \
            $(DIR_LIB)ft_strtabdel.c        \
            $(DIR_LIB)ft_strtablen.c        \
            $(DIR_LIB)ft_strtrim.c          \
            $(DIR_LIB)ft_tolower.c          \
            $(DIR_LIB)ft_toupper.c          \
            $(DIR_LIB)get_next_line.c       \
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
ft_atoi.o: libft.h
ft_bzero.o: libft.h
ft_isalnum.o: libft.h
ft_itoa.o: libft.h
ft_lstadd.o: libft.h
ft_lstcreateelem.o: libft.h
ft_lstdel.o: libft.h
ft_lstdelone.o: libft.h
ft_lstiter.o: libft.h
ft_lstmap.o: libft.h
ft_lstnew.o: libft.h
ft_lstpop.o: libft.h
ft_lstpushback.o: libft.h
ft_lstpushfront.o: libft.h
ft_lstreverse.o: libft.h
ft_lstsize.o: libft.h
ft_memalloc.o: libft.h
ft_memccpy.o: libft.h
ft_memchr.o: libft.h
ft_memcpy.o: libft.h
ft_memdel.o: libft.h
ft_memmove.o: libft.h
ft_memset.o: libft.h
ft_putendl.o: libft.h
ft_putendl_fd.o: libft.h
ft_putnbr.o: libft.h
ft_putnbr_fd.o: libft.h
ft_putstr.o: libft.h
ft_putstr_fd.o: libft.h
ft_strclr.o: libft.h
ft_strdel.o: libft.h
ft_strdup.o: libft.h
ft_strequ.o: libft.h
ft_strjoin.o: libft.h
ft_strlcat.o: libft.h
ft_strmap.o: libft.h
ft_strmapi.o: libft.h
ft_strncat.o: libft.h
ft_strncpy.o: libft.h
ft_strnequ.o: libft.h
ft_strnew.o: libft.h
ft_strrchr.o: libft.h
ft_strsplit.o: libft.h
ft_strstr.o: libft.h
ft_strsub.o: libft.h
ft_strtrim.o: libft.h
get_next_line.o: libft.h
