/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:55:30 by ski               #+#    #+#             */
/*   Updated: 2021/12/02 18:55:36 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/* ************************************************************************** */
# include "ft_printf.h"
# include "libft/libft.h"
/* ************************************************************************** */
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/* ************************************************************************** */
int	ft_printf(const char *text, ...);
/* ------------------------------------------------------ */
size_t	sk_putchar_fd(char c, int fd);
size_t	sk_putstr_fd(char *s, int fd);

size_t	sk_putstr_printf_fd(char *s, int fd);
size_t	sk_putptr_fd(unsigned long n, int fd);
size_t	sk_putnbr_s_fd(int n, int fd);
size_t	sk_putnbr_u_fd(unsigned int u, int fd);
size_t	sk_puthex_low_fd(int n, int fd);
size_t	sk_puthex_up_fd(int n, int fd);

size_t	sk_charcmp(char c_src, char c_cmp);

/* ************************************************************************** */
#endif