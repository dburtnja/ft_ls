# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 16:49:11 by dburtnja          #+#    #+#              #
#    Updated: 2017/04/26 19:33:48 by dburtnja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a
FT_PRINTF = libft/ft_printf/libftprintf.a

NAME = ft_ls

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =	ft_ls.c\
        read_arguments.c\
        error.c\
        directory_struct.c\
        recursive_search.c\
        directory.c\
        file.c\
        print_ls.c\
        sort_before_print.c\
        simple_print.c\
        my_sort_func.c\
        list_print.c\
        read_chmod.c\
        get_owner_and_groupe_name.c\
        simple_print_2.c\
        list_print_2.c


OBJ = $(SRC:.c=.o)

all:	$(FT_PRINTF) $(LIB) $(NAME)

$(LIB):
		make -C ./libft

$(FT_PRINTF):
		make -C ./libft/ft_printf

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB) $(FT_PRINTF)
%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<

clean:
		@make clean -C ./libft
		@make clean -C ./libft/ft_printf
		@rm -f $(OBJ)
fclean:
		@make fclean -C ./libft
		@make fclean -C ./libft/ft_printf
		@make clean
		@rm -f $(NAME)

re:
		@make fclean
		@make all