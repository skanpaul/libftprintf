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
# **************************************************************************** #
NAME			= libftprintf.a
# ----------------------------------------------------------------------------
PATH_PRINTF		= ./
HD_PRINTF		= ft_printf.h
SRC_PRINTF		= \
				ft_printf.c		sk_charcmp.c \
				sk_putchar_fd.c	sk_putstr_fd.c		sk_putstr_printf_fd.c \
				sk_putptr_fd.c	sk_putnbr_s_fd.c	sk_putnbr_u_fd.c \
				sk_puthex_low_fd.c 	sk_puthex_up_fd.c \
				sk_putnbr_fd.c
OBJ_PRINTF		= ${SRC_PRINTF:.c=.o}
# ----------------------------------------------------------------------------
PATH_LIBFT		= libft/
NAME_LIBFT		= libft.a
HD_LIBFT		= libft.h

# **************************************************************************** #
PATH_SUBMAKE	= ${PATH_LIBFT}
SRC_NORM		= ${SRC_PRINTF}
HD_NORM			= ${HD_PRINTF}
# **************************************************************************** #
all: ${NAME}

${NAME}: ${OBJ_PRINTF} sub_all
	cp ${PATH_LIBFT}${NAME_LIBFT} ${PATH_PRINTF}
	mv ${NAME_LIBFT} ${NAME}
	${AR} ${NAME} ${OBJ_PRINTF}

clean: sub_clean
	${RM} ${OBJ_PRINTF}

fclean: clean sub_fclean
	${RM} ${NAME}

re: fclean all sub_re

.PHONY: all clean fclean re

nono: sub_nono
	${NORM} ${SRC_NORM}
	${NORM} ${HD_NORM}

# **************************************************************************** #
sub_all:
	${MAKE} all -C ${PATH_SUBMAKE}

sub_clean:
	${MAKE} clean -C ${PATH_SUBMAKE}

sub_fclean:
	${MAKE} fclean -C ${PATH_SUBMAKE}

sub_re:
	${MAKE} re -C ${PATH_SUBMAKE}

sub_nono:
	${MAKE} nono -C ${PATH_SUBMAKE}

# **************************************************************************** #

