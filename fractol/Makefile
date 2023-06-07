# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 20:00:23 by kgebski           #+#    #+#              #
#    Updated: 2023/06/01 16:30:37 by kgebski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c 

OBJS	=	$(SRCS:.c=.o)

NAME		=	push_swap
LIBFT		=	./inc/libft/libft.a
LIBFT_DIR	=	./inc/libft/
HDRS_DIR	=	./inc/
SRC_DIR		=	./src

CFLAGS		=	-Wall -Wextra -Werror

all: libft ${NAME}

${NAME}: $(OBJS)
	gcc ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

libft: 
	make -C ${LIBFT_DIR}

.c.o:
	gcc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HDRS_DIR} -I ${LIBFT_DIR}

clean:
	rm -f ${OBJS}
	make -C ${LIBFT_DIR} clean

fclean: clean
	rm -f ${NAME}
	make -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re libft