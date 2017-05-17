# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 13:11:07 by jmoucade          #+#    #+#              #
#    Updated: 2017/05/17 05:23:40 by jmoucade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

CC = clang

CFLAGS = -Wall -Wextra -Werror

INC_PATH = includes

INC =	$(INC_PATH)/ft_21sh.h			\
		$(INC_PATH)/terms.h				\
		$(INC_PATH)/editline.h				\
		$(INC_PATH)/error.h				\
		$(INC_PATH)/history.h				\
		$(INC_PATH)/keyboard.h				\
		$(INC_PATH)/signals.h

SRC_PATH = sources

SRC =	$(SRC_PATH)/shell/21sh.c			\
		$(SRC_PATH)/shell/usage.c			\
		$(SRC_PATH)/shell/init.c			\
		$(SRC_PATH)/shell/error.c			\
		$(SRC_PATH)/shell/prompt.c			\
		$(SRC_PATH)/shell/stock.c			\
		$(SRC_PATH)/keyboard/handler.c	\
		$(SRC_PATH)/keyboard/termios.c	\
		$(SRC_PATH)/keyboard/editline.c			\
		$(SRC_PATH)/keyboard/add_key.c			\
		$(SRC_PATH)/keyboard/is_key.c			\
		$(SRC_PATH)/keyboard/keys/arrow.c	\
		$(SRC_PATH)/keyboard/keys/home.c	\
		$(SRC_PATH)/keyboard/keys/end.c	\
		$(SRC_PATH)/keyboard/keys/del.c	\
		$(SRC_PATH)/keyboard/keys/return.c	\
		$(SRC_PATH)/keyboard/keys/alt.c	\
		$(SRC_PATH)/keyboard/keys/ctrl/ctrl_k.c	\
		$(SRC_PATH)/keyboard/keys/ctrl/ctrl_u.c	\
		$(SRC_PATH)/keyboard/keys/ctrl/ctrl_w.c	\
		$(SRC_PATH)/keyboard/keys/ctrl/ctrl_y.c	\
		$(SRC_PATH)/history/init.c			\
		$(SRC_PATH)/history/move.c			\
		$(SRC_PATH)/history/delete.c			\
		$(SRC_PATH)/history/print.c			\
		$(SRC_PATH)/history/save.c			\
		$(SRC_PATH)/history/load.c			\
		$(SRC_PATH)/signals/catch.c \
		$(SRC_PATH)/signals/handler.c \

OSRC = $(SRC:.c=.o)

LIB_PATH = libft
LIB = libft/libft.a

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m

all: $(NAME)

$(NAME): $(LIB) $(OSRC) $(INC)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OSRC) -o $@ -L $(LIB_PATH) -lft -lncurses -g3 -fsanitize=address -fno-omit-frame-pointer
	@echo "$(OK_COLOR)$@ compiled.$(NO_COLOR)"

$(LIB):
	@echo "Compiling libft..."
	@make -C $(LIB_PATH)
	@echo "Librairy compiled."

%.o: %.c
	@$(CC) $(CFLAGS) -I $(LIB_PATH)/$(INC_PATH) -I $(INC_PATH) -c -o $@ $?
	@echo "Linking file $@"

clean:
	@make clean -C $(LIB_PATH)
	@/bin/rm -f $(OSRC)
	@echo "Cleaning temporary files."

fclean: clean
	@make fclean -C $(LIB_PATH)
	@/bin/rm -f $(NAME)
	@echo "Delete $(NAME) file."

re: fclean all

.PHONY: all clean fclean re
