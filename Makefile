# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 09:45:53 by ski               #+#    #+#              #
#    Updated: 2021/11/04 16:34:14 by ski              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
AR 				= ar -rcs
RM				= rm -f 
NORM			= norminette -R CheckForbiddenSourceHeader 

# ----------------------------------------------------------------------------
NAME			= libftprintf.a

PATH_PRINTF		= ./
SRC_PRINTF		= ft_printf.c
HD_PRINTF		= ft_printf.h

OBJ_PRINTF		= ${SRC_PRINTF:.c=.o}

PATH_LIBFT		= libft/
NAME_LIBFT		= libft.a
HD_LIBFT		= libft.h

# **************************************************************************** #
all: $(NAME)

# **************************************************************************** #
$(NAME): $(OBJ_PRINTF) sub_all
	${AR} $(NAME) $(OBJ_PRINTF)
# **************************************************************************** #

clean: sub_clean
	${RM} $(OBJ_PRINTF)

fclean: clean sub_fclean
	${RM} $(NAME)

re: fclean all sub_re

.PHONY: all clean fclean re
# **************************************************************************** #

sub_all:
	${MAKE} all -C ${PATH_LIBFT}

sub_clean:
	${MAKE} clean -C ${PATH_LIBFT}

sub_fclean:
	${MAKE} fclean -C ${PATH_LIBFT}

sub_re:
	${MAKE} re -C ${PATH_LIBFT}


# **************************************************************************** #

nono:
	$(NORM) $(PATH_PRINTF)