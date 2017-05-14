# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2016/08/14 13:07:25 by jmoucade          #+#    #+#             #
#   Updated: 2016/08/17 03:05:31 by jmoucade         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INC_PATH = includes

SRCS_PATH = sources

SRCS = 	$(SRCS_PATH)/ft_memset.c			\
		$(SRCS_PATH)/ft_bzero.c			\
		$(SRCS_PATH)/ft_memcpy.c			\
		$(SRCS_PATH)/ft_memccpy.c		\
		$(SRCS_PATH)/ft_memmove.c		\
		$(SRCS_PATH)/ft_memchr.c			\
		$(SRCS_PATH)/ft_memcmp.c			\
		$(SRCS_PATH)/ft_strlen.c			\
		$(SRCS_PATH)/ft_strdup.c			\
		$(SRCS_PATH)/ft_strcpy.c			\
		$(SRCS_PATH)/ft_strncpy.c		\
		$(SRCS_PATH)/ft_strcat.c			\
		$(SRCS_PATH)/ft_strncat.c		\
		$(SRCS_PATH)/ft_strlcat.c		\
		$(SRCS_PATH)/ft_strchr.c			\
		$(SRCS_PATH)/ft_strrchr.c		\
		$(SRCS_PATH)/ft_strstr.c			\
		$(SRCS_PATH)/ft_strnstr.c		\
		$(SRCS_PATH)/ft_strcmp.c			\
		$(SRCS_PATH)/ft_strncmp.c		\
		$(SRCS_PATH)/ft_atoi.c			\
		$(SRCS_PATH)/ft_isalpha.c		\
		$(SRCS_PATH)/ft_isdigit.c		\
		$(SRCS_PATH)/ft_isalnum.c		\
		$(SRCS_PATH)/ft_isascii.c		\
		$(SRCS_PATH)/ft_isprint.c		\
		$(SRCS_PATH)/ft_toupper.c		\
		$(SRCS_PATH)/ft_tolower.c		\
		$(SRCS_PATH)/ft_memalloc.c		\
		$(SRCS_PATH)/ft_memdel.c			\
		$(SRCS_PATH)/ft_strnew.c			\
		$(SRCS_PATH)/ft_strdelnew.c			\
		$(SRCS_PATH)/ft_strdel.c			\
		$(SRCS_PATH)/ft_strclr.c			\
		$(SRCS_PATH)/ft_striter.c		\
		$(SRCS_PATH)/ft_striteri.c		\
		$(SRCS_PATH)/ft_strmap.c			\
		$(SRCS_PATH)/ft_strmapi.c		\
		$(SRCS_PATH)/ft_strequ.c			\
		$(SRCS_PATH)/ft_strnequ.c		\
		$(SRCS_PATH)/ft_strsub.c			\
		$(SRCS_PATH)/ft_strjoin.c		\
		$(SRCS_PATH)/ft_strtrim.c		\
		$(SRCS_PATH)/ft_strsplit.c		\
		$(SRCS_PATH)/ft_itoa.c			\
		$(SRCS_PATH)/ft_putchar.c		\
		$(SRCS_PATH)/ft_putchar_fd.c		\
		$(SRCS_PATH)/ft_putstr.c			\
		$(SRCS_PATH)/ft_putstr_fd.c		\
		$(SRCS_PATH)/ft_putendl.c		\
		$(SRCS_PATH)/ft_putendl_fd.c		\
		$(SRCS_PATH)/ft_putnbr.c			\
		$(SRCS_PATH)/ft_putnbr_fd.c		\
		$(SRCS_PATH)/ft_putcharcolor.c		\
		$(SRCS_PATH)/ft_putcharcolor_fd.c		\
		$(SRCS_PATH)/ft_putstrcolor.c			\
		$(SRCS_PATH)/ft_putstrcolor_fd.c		\
		$(SRCS_PATH)/ft_putendlcolor.c		\
		$(SRCS_PATH)/ft_putendlcolor_fd.c		\
		$(SRCS_PATH)/ft_putnbrcolor.c			\
		$(SRCS_PATH)/ft_putnbrcolor_fd.c		\
		$(SRCS_PATH)/ft_lstnew.c			\
		$(SRCS_PATH)/ft_lstdelone.c		\
		$(SRCS_PATH)/ft_lstdel.c			\
		$(SRCS_PATH)/ft_lstdelfirst.c			\
		$(SRCS_PATH)/ft_lstdelnext.c			\
		$(SRCS_PATH)/ft_lstadd_start.c			\
		$(SRCS_PATH)/ft_lstadd_end.c			\
		$(SRCS_PATH)/ft_lstrev.c			\
		$(SRCS_PATH)/ft_lstiter.c		\
		$(SRCS_PATH)/ft_lstselect.c		\
		$(SRCS_PATH)/ft_lstmap.c			\
		$(SRCS_PATH)/get_next_line.c		\
		$(SRCS_PATH)/ft_nbrlen.c			\
		$(SRCS_PATH)/ft_memrcpy.c		\
		$(SRCS_PATH)/ft_lstlen.c			\
		$(SRCS_PATH)/ft_is_space.c 		\
		$(SRCS_PATH)/ft_swap.c			\
		$(SRCS_PATH)/ft_range.c			\
		$(SRCS_PATH)/ft_foreach.c		\
		$(SRCS_PATH)/ft_count_if.c		\
		$(SRCS_PATH)/ft_putstrtab.c			\
		$(SRCS_PATH)/ft_delstrtab.c			\
		$(SRCS_PATH)/ft_putnbr_base.c 		\
		$(SRCS_PATH)/ft_itoa_base.c 		\
		$(SRCS_PATH)/ft_stracat.c 			\
		$(SRCS_PATH)/ft_triple_tab.c 			\
		$(SRCS_PATH)/ft_strpadding_right.c 			\
		$(SRCS_PATH)/ft_strpadding_left.c 			\
		$(SRCS_PATH)/ft_str3join.c 			\
		$(SRCS_PATH)/ft_addchar.c


OBJ	= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_PATH) -c -o $@ $?

clean: 
	/bin/rm -f $(SRCS_PATH)/*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean