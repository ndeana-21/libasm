# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndeana <ndeana@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/22 21:32:51 by ndeana            #+#    #+#              #
#    Updated: 2020/10/25 03:52:14 by ndeana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

SRCS	=	ft_strlen.s		ft_strcpy.s		ft_strcmp.s							\
			ft_write.s		ft_read.s		ft_strdup.s
OBJ		=	$(SRCS:.s=.o)

all: $(NAME)

%.o: %.s
	@nasm -f elf64 $<
	@echo compile $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo made $(NAME)

clean:
	@rm -f $(OBJ) main.o
	@echo clean $(OBJ) main.o

fclean: clean
	@rm -f $(NAME) a.out
	@echo clean $(NAME)

main: all
	@clang main.c $(NAME)
	@./a.out

re: fclean all

.PHONY: all clean fclean re main