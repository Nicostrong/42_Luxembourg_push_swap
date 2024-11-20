/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:46:16 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/15 10:08:02 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * 
 * <cat>str</cat>
 *
 * <summary>
 *	static void	ft_ulongtohexa(unsigned long n)
 * </summary>
 *
 * <description>
 *	ft_ulongtohexa convert an unsigned long in hexadecimal value.
 * </description>
 *
 * <param type="unsigned long" name="n">number to convert</param>
 *
 * <return>
 *	number of char printed.
 * </return>
 *
 */

static void	ft_ulongtohexa(unsigned long n, int *nb_char_printed)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n >= 16)
		ft_ulongtohexa(n / 16, nb_char_printed);
	ft_putchar(hexa[n % 16], nb_char_printed);
}

/*
 * 	<cat>str</cat>
 *
 * <summary>
 *	void	ft_putaddress(void *ptr)
 * </summary>
 *
 * <description>
 *	ft_putaddress show the address memory in hexadecimal value.
 * </description>
 *
 * <param type="void *" name="ptr">pointer</param>
 *
 * <return>
 *	number of char printed.
 * </return>
 *
 */

void	ft_putaddress(void *ptr, int *nb_char_printed)
{
	unsigned long	adr;

	adr = (unsigned long)ptr;
	ft_putstr("0x", nb_char_printed);
	ft_ulongtohexa(adr, nb_char_printed);
}
