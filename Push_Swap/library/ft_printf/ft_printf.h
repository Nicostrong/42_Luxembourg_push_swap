/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:24:04 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/15 10:04:10 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
 *	Standard library
 */

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*
 * Printf functions
 */

int		ft_printf(const char *s, ...);

void	ft_putnbr(int n, int *nb_char_printed);
void	ft_putchar(int c, int *nb_char_printed);
void	ft_putstr(char *s, int *nb_char_printed);
void	ft_putaddress(void *ptr, int *nb_char_printed);
void	ft_putunsigned(unsigned int n, int *nb_char_printed);
void	ft_puthexa(const char flag, unsigned int c, int *nb_char_printed);

#endif
