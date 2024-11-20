/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:46:33 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/15 10:10:56 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	g_fd;

/*
 * <cat>print</cat>
 *
 * <summary>
 *	int	ft_putchar(char c)
 * </summary>
 *
 * <description>
 *	ft_putchar_fd print the char c.
 * </description>
 *
 * <param type="char" name="c">char to print</param>
 *
 * <return>
 *	number of char printed.
 * </return>
 *
 */

void	ft_putchar(int c, int *nb_char_printed)
{
	write(1, &c, 1);
	(*nb_char_printed)++;
}
