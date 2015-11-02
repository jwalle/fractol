# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/07 17:35:39 by jwalle            #+#    #+#              #
#    Updated: 2015/09/07 18:14:24 by jwalle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fractol

SRC 		=	fractol.c \
				hook.c \
				loop.c \
				mandelbrot.c \

INC			=	-I./inc -I./libft/includes
LINK		=	-Llibft -lft $(LDFLAGS) $(MLXFLAGS)
SRCDIR		= ./srcs/
ODIR		= ./objs/
INC_MLX		=	minilibx_macos

CFLAGS		=	-Wall -Wextra -Werror
LDFLAGS		=	-L/usr/X11/lib
MLXFLAGS	=	-L$(INC_MLX) -lmlx -framework OpenGL -framework AppKit	
FLAGS		=	$(CFLAGS)

CC			=	clang
RM			=	/bin/rm -f

OBJ			=	$(SRC:.c=.o)
OBJS		= 	$(addprefix $(ODIR), $(OBJ))

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	@make -C ./libft
	@make -C minilibx_macos
	$(CC) -o $(NAME) $(LINK) $(MLXFLAGS) $^ 

$(ODIR)%.o : $(SRCDIR)%.c
	$(CC) $(FLAGS) $(INC) -c $^ -o $@

clean		:
	@make -C ./libft clean
	@$(RM) $(OBJ)

fclean		:	clean
	@make -C ./libft fclean
	@$(RM) $(NAME)

re			:	fclean all

%.o			:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
