# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgebski <kgebski@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 15:31:39 by kgebski           #+#    #+#              #
#    Updated: 2023/06/06 16:01:21 by kgebski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = philo
CFLAGS      =  -pthread -Wall -Wextra -Werror -O3
LIBFT       = ./inc/libft/libft.a
LIBFT_DIR   = ./inc/libft/
HDRS_DIR    = ./inc/
SRC_DIR     = ./src

SRCS	= src/_main.c
HDRS	= -I$(LIBFT_DIR)/inc -I$(HDRS_DIR)
LIBS	= -L$(LIBFT_DIR)
OBJS	= $(SRCS:.c=.o)


all: libft ${NAME}

${NAME}: $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME) $(LIBFT)

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

.PHONY: all clean fclean re libft ${NAME}