/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:46:43 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/15 10:09:57 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * <cat>print</cat>
 *
 * <summary>
 *	int	ft_putstr(char *s)
 * </summary>
 *
 * <description>
 *	ft_putchar_fd print the string s
 * </description>
 *
 * <param type="char *" name="s">string to print</param>
 *
 * <return>
 *	number of char printed.
 * </return>
 *
 */

void	ft_putstr(char *s, int *nb_char_printed)
{
	if (!s)
		ft_putstr("(null)", nb_char_printed);
	while (s && *s)
		ft_putchar(*s++, nb_char_printed);
}
