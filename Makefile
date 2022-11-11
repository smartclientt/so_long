# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 13:16:57 by shbi              #+#    #+#              #
#    Updated: 2022/11/11 07:57:43 by shbi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	so_long
SRCS	=	so_long.c 																		\
			parcing.c functions.c functions_.c error_msg.c check_map.c 	check_map_.c		\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 				\
			tools.c split_with_new_line.c build_map.c make_moves.c	end_game.c 				\
			
OBJS	=	$(SRCS:.c=.o)
HEADR	=	so_long.h
PRINTF	=	./ft_printf/libftprintf.a
PATH_PR =	./ft_printf
CC		=	cc
CFLAG	=	-Wall -Werror -Wextra
RM		=	rm -rf

all			:	$(NAME)
$(PRINTF)	:
				make -C $(PATH_PR)
$(NAME)		:	$(OBJS) $(PRINTF)
				$(CC) $(CFLAG) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(PRINTF)
%.o			:	%.c $(HEADR)
				$(CC) $(CFLAG) -Imlx -c $< -o $@
clean		:
				$(RM) $(OBJS)
				make clean -C $(PATH_PR)
fclean		:	clean
				$(RM) $(NAME)
				make fclean -C $(PATH_PR)
re			:	fclean all 
