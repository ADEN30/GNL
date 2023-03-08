# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agallet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 15:33:24 by agallet           #+#    #+#              #
#    Updated: 2022/12/13 11:30:59 by agallet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
SRCS = get_next_line_utils.c main.c
BUFF = BUFFER_SIZE=10

all:
	gcc $(CFLAGS) -D $(BUFF) $(SRCS) -o prog
