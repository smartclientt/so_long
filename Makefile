# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 13:16:57 by shbi              #+#    #+#              #
#    Updated: 2022/11/03 18:17:08 by shbi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	so_long
SRCS	=	so_long.c \
			parcing.c functions.c functions_.c error_msg.c check_map.c 			\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 	\
			tools.c split_with_new_line.c 
OBJS	=	$(SRCS:.c=.o)
HEADR	=	so_long.h
CC		=	cc
CFLAG	=	-Wall -Werror -Wextra
RM		=	rm -rf

all			:	$(NAME)
$(NAME)		:	$(OBJS)
				$(CC) $(CFLAG) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
%.o			:	%.c $(HEADR)
				$(CC) $(CFLAG) -Imlx -c $< -o $@
clean		:
				$(RM) $(OBJS)
fclean		:	clean
				$(RM) $(NAME)
re			:	fclean all 