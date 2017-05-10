# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 13:11:07 by jmoucade          #+#    #+#              #
#    Updated: 2017/05/07 22:27:53 by mo0ky            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

CC = clang

CFLAGS = -Wall -Wextra -Werror

INC_PATH = includes

SRC_PATH = sources

SRC =	$(SRC_PATH)/21sh.c			\
		$(SRC_PATH)/usage.c			\
		$(SRC_PATH)/prompt.c			\
		$(SRC_PATH)/shell/init.c			\
		$(SRC_PATH)/shell/stock.c			\
		$(SRC_PATH)/keyboard/handler.c	\
		$(SRC_PATH)/keyboard/termios.c	\
		$(SRC_PATH)/keyboard/editline.c			\
		$(SRC_PATH)/keyboard/add_key.c			\
		$(SRC_PATH)/keyboard/keys/keys_arrow.c	\
		$(SRC_PATH)/keyboard/keys/keys_del.c	\
		$(SRC_PATH)/keyboard/keys/key_return.c	\
		$(SRC_PATH)/history/init.c			\
		$(SRC_PATH)/history/move.c			\
		$(SRC_PATH)/history/delete.c			\
		$(SRC_PATH)/history/print.c			\
		$(SRC_PATH)/history/save.c			\
		$(SRC_PATH)/history/load.c			\
		$(SRC_PATH)/signals/catch.c \
		$(SRC_PATH)/signals/handler.c \
		$(SRC_PATH)/error.c

OSRC = $(SRC:.c=.o)

LIB_PATH = libft
LIB = libft/libft.a

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m

all: $(NAME)

$(NAME): $(LIB) $(OSRC)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OSRC) -o $@ -L $(LIB_PATH) -lft -lncurses -g -fsanitize=address -fno-omit-frame-pointer
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