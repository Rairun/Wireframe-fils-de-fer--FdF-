# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaprono <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 11:41:27 by psaprono          #+#    #+#              #
#    Updated: 2018/04/22 12:43:49 by psaprono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := 	fdf

SRC :=		main.c color.c check.c read.c draw.c key_bind.c convert.c \
			key_bind1.c brez.c tutor.c

OBJ =		$(SRC:.c=.o)

LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=	libft/
LIBFT_FLAGS :=	-lft -L $(LIBFT_DIR) -lmlx -framework OpenGL -framework AppKit

CC_FLAGS :=		-Wall -Werror -Wextra

LINK_FLAGS :=	$(LIBFT_FLAGS)

HEADER_FLAGS :=	-I. -I $(LIBFT_DIR)

CC :=			gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	$(CC) -O3 -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
