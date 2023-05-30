# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 20:00:23 by kgebski           #+#    #+#              #
#    Updated: 2023/05/30 16:18:27 by kgebski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c src/parser.c src/not_unique.c src/initialize.c

OBJS	= $(SRCS:.c=.o)
NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror
LIBFT_L = libft.a
LIBFT_DIR = libft
INCLUDE = inc

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDE}
	
all: libft ${NAME}

${NAME}: $(OBJS)
	gcc ${CFLAGS} ${OBJS} ${LIBFT_DIR}/${LIBFT_L} -o ${NAME}
	
clean:
	rm -f ${OBJS}
	make -C ${LIBFT_DIR} clean

fclean: clean
	rm -f ${NAME}
	make -C ${LIBFT_DIR} fclean

re: fclean all

libft: 
	make bonus -C ${LIBFT_DIR}

.PHONY: all clean fclean re libft