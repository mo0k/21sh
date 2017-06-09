# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 17:53:51 by mo0ky             #+#    #+#              #
#    Updated: 2017/06/09 10:20:43 by mo0ky            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

CC = clang

CFLAGS = -Wall -Wextra -Werror

INC_PATH = includes

INC =	$(INC_PATH)/ft_21sh.h			\
		$(INC_PATH)/error.h				\
		$(INC_PATH)/readline.h			\
		$(INC_PATH)/newline.h			\
		$(INC_PATH)/keys.h				\
		$(INC_PATH)/terms.h				\
		$(INC_PATH)/history.h			\
		$(INC_PATH)/tokenizer.h			\
		$(INC_PATH)/signals.h

SRC_PATH = sources

SRC =	$(SRC_PATH)/shell/21sh.c								\
		$(SRC_PATH)/shell/usage.c								\
		$(SRC_PATH)/shell/init.c								\
		$(SRC_PATH)/shell/error.c								\
		$(SRC_PATH)/shell/prompt.c								\
		$(SRC_PATH)/shell/stock.c								\
		$(SRC_PATH)/shell/winsize.c								\
		$(SRC_PATH)/readline/handler.c							\
		$(SRC_PATH)/readline/readline.c							\
		$(SRC_PATH)/readline/add_key.c							\
		$(SRC_PATH)/readline/protection.c						\
		$(SRC_PATH)/readline/newline/handler.c					\
		$(SRC_PATH)/readline/newline/init.c						\
		$(SRC_PATH)/readline/newline/newline.c					\
		$(SRC_PATH)/readline/termios/ft_cfmakeraw.c				\
		$(SRC_PATH)/readline/termios/init.c						\
		$(SRC_PATH)/readline/termios/my_putc.c					\
		$(SRC_PATH)/readline/termios/restore.c					\
		$(SRC_PATH)/readline/keys/ctrl/backward_char.c			\
		$(SRC_PATH)/readline/keys/ctrl/backward_delete_char.c	\
		$(SRC_PATH)/readline/keys/ctrl/beginning_of_line.c		\
		$(SRC_PATH)/readline/keys/ctrl/clear_screen.c			\
		$(SRC_PATH)/readline/keys/ctrl/delete_char.c			\
		$(SRC_PATH)/readline/keys/ctrl/end_of_line.c			\
		$(SRC_PATH)/readline/keys/ctrl/forward_char.c			\
		$(SRC_PATH)/readline/keys/ctrl/kill_line.c				\
		$(SRC_PATH)/readline/keys/ctrl/next_history.c			\
		$(SRC_PATH)/readline/keys/ctrl/paste.c					\
		$(SRC_PATH)/readline/keys/ctrl/previous_history.c		\
		$(SRC_PATH)/readline/keys/ctrl/search_history.c			\
		$(SRC_PATH)/readline/keys/ctrl/unix_line_discard.c		\
		$(SRC_PATH)/readline/keys/ctrl/unix_word_rubout.c		\
		$(SRC_PATH)/readline/keys/meta/backward_word.c			\
		$(SRC_PATH)/readline/keys/meta/capitalize_word.c		\
		$(SRC_PATH)/readline/keys/meta/downcase_word.c			\
		$(SRC_PATH)/readline/keys/meta/forward_word.c			\
		$(SRC_PATH)/readline/keys/meta/kill_word.c				\
		$(SRC_PATH)/readline/keys/meta/upcase_word.c			\
		$(SRC_PATH)/readline/keys/others/line_down.c			\
		$(SRC_PATH)/readline/keys/others/line_up.c				\
		$(SRC_PATH)/readline/keys/others/return.c				\
		$(SRC_PATH)/history/init.c								\
		$(SRC_PATH)/history/delete.c							\
		$(SRC_PATH)/history/load.c								\
		$(SRC_PATH)/history/move.c								\
		$(SRC_PATH)/history/print.c								\
		$(SRC_PATH)/history/save.c								\
		$(SRC_PATH)/tokenizer/delete.c							\
		$(SRC_PATH)/tokenizer/init.c							\
		$(SRC_PATH)/tokenizer/print.c							\
		$(SRC_PATH)/tokenizer/quoting.c							\
		$(SRC_PATH)/tokenizer/tokenizer.c						\
		$(SRC_PATH)/tokenizer/tokens/init.c						\
		$(SRC_PATH)/tokenizer/tokens/delete.c					\
		$(SRC_PATH)/tokenizer/tokens/token.c					\
		$(SRC_PATH)/tokenizer/tokens/types/io_number.c			\
		$(SRC_PATH)/tokenizer/tokens/types/redir_op.c			\
		$(SRC_PATH)/tokenizer/tokens/types/word.c				\
		$(SRC_PATH)/signals/catch.c 							\
		$(SRC_PATH)/signals/handler.c

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
