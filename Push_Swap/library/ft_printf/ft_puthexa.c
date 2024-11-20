/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:47:54 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/15 10:07:07 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * 	<cat>print</cat>
 *
 * 	<summary>
 * 		void	ft_puthexa(const char flag, unsigned int c)
 *	</summary>
 *
 *	<description>
 *		ft_puthexa convert an unsigned int in hexadecimal value.
 *	</description>
 *
 *	<param type="const char" name="flag">fag for hexa or HEXA</param>
 *	<param type="unsigned int" name="c">number to convert</param>
 *
 *	<return>
 *		void
 *	</return>
 *
 */

void	ft_puthexa(const char flag, unsigned int c, int *nb_char_printed)
{
	char	*hexa;
	char	*maj_hexa;

	hexa = "0123456789abcdef";
	maj_hexa = "0123456789ABCDEF";
	if (c >= 16)
		ft_puthexa(flag, c / 16, nb_char_printed);
	if (flag == 'x')
		ft_putchar(hexa[c % 16], nb_char_printed);
	else
		ft_putchar(maj_hexa[c % 16], nb_char_printed);
}
