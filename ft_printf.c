/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 08:25:59 by ski               #+#    #+#             */
/*   Updated: 2021/11/29 08:26:09 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/* ************************************************************************** */
static int	sk_printconv(va_list ptr_var, char type_conv);
static bool	isvariadic(const char *seg);

/* ************************************************************************** */
int	ft_printf(const char *text, ...)
{
	va_list	ptr_var;
	int		i;
	int		cnt_prnt;

	if (text == NULL)
		return (0);
	i = 0;
	cnt_prnt = 0;
	va_start(ptr_var, text);
	while (text[i] != '\0')
	{
		if (isvariadic(&text[i]))
		{
			cnt_prnt += sk_printconv(ptr_var, text[i + 1]);
			i += 2;
		}
		else
		{
			write(1, &text[i], 1);
			cnt_prnt++;
			i++;
		}
	}	
	va_end(ptr_var);
	return (cnt_prnt);
}

/* ************************************************************************** */
static int	sk_printconv(va_list ptr_var, char type_conv)
{
	int	n;

	n = 0;
	if (type_conv == 'c')
		return (sk_putchar_fd(va_arg(ptr_var, int), 1));
	if (type_conv == 's')
		return (sk_putstr_printf_fd(va_arg(ptr_var, char *), 1));
	if (type_conv == 'p')
		return (sk_putptr_fd(va_arg(ptr_var, size_t), 1));
	if ((type_conv == 'd') || (type_conv == 'i'))
		return (sk_putnbr_s_fd(va_arg(ptr_var, int), 1));
	if (type_conv == 'u')
		return (sk_putnbr_u_fd(va_arg(ptr_var, unsigned int), 1));
	if (type_conv == 'x')
		return (sk_puthex_low_fd(va_arg(ptr_var, int), 1));
	if (type_conv == 'X')
		return (sk_puthex_up_fd(va_arg(ptr_var, int), 1));
	if (type_conv == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
static bool	isvariadic(const char *seg)
{
	return ((seg[0] == '%')
		&& ((seg[1] == 'c') || (seg[1] == 's') || (seg[1] == 'p')
			|| (seg[1] == 'd') || (seg[1] == 'i') || (seg[1] == 'u')
			|| (seg[1] == 'x') || (seg[1] == 'X') || (seg[1] == '%')));
}

/* ************************************************************************** */
/* Nom du programme:	libftprintf.a 										*/
/*  																		*/
// Fichiers de rendu:	1) *.c												*/
// 						2) */*.c											*/
// 						3) *.h												*/
// 						4) */*.h											*/
// 						5) Makefile 										*/
/*  																		*/
/* Makefile:			all, clean, fclean, re, bonus 						*/
/*  																		*/
/* Fonctions externes autorisées Libft autorisée 							*/
/* 		malloc, free, write 												*/
/* 		1) va_start															*/
/*		2) va_arg															*/
/*		3) va_copy															*/
/*		4) va_end 															*/
/*  																		*/
/* Libft autorisée:		yes 												*/
/*  																		*/
/* Description:  															*/
/* 		- Une librairie qui contient ft_printf 								*/
/* 		- Une fonction qui marche comme le vrai printf 						*/
/*  																		*/
/* RETURN VALUE																*/
/*        Upon successful return, these functions return the number of 		*/
/*        characters printed (excluding the null byte used to end output to */
/*        strings). 														*/
/* ************************************************************************** */

/* ************************************************************************** */
/* 	sk_printconv															  */
/* -------------------------------------------------------------------------- */
/*		DESCRITPION:	print the VARIADIC on the terminal					  */
/* -------------------------------------------------------------------------- */
/*		INPUT:			- prt_var: pointer on VARIADIC						  */
/*						- vartype: variable type							  */
/*																			  */
/*		RETURN:        number of characters printed on the terminal			  */
/* ************************************************************************** */