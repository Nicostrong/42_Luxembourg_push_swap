/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:48:12 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/15 10:06:01 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * 	<cat>print</cat>
 *
 * 	<summary>
 *		void	ft_putunsigned(unsigned int n)
 *	<\summary>
 *
 *	<remark>
 *		ft_putunsigned print an unsigned int.
 *	<\remark>
 *
 *	<param type="unsigned int" name="n">number to print<\param>
 *
 *	<return>
 *		void
 *	<\return>
 *
 */

void	ft_putunsigned(unsigned int n, int *nb_char_printed)
{
	if (n >= 10)
	{
		ft_putunsigned(n / 10, nb_char_printed);
		ft_putunsigned(n % 10, nb_char_printed);
	}
	else
		ft_putchar(n + '0', nb_char_printed);
}
