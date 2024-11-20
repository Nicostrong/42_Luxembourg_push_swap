/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:46:54 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/15 10:06:38 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * <cat>print</cat>
 *
 * <summary>
 *		void	ft_putnbr(int n)
 * </summary>
 *
 * <description>
 *		ft_putnbr_fd print the integer n.
 * </description>
 *
 * <param type="int" name="n">number to print</param>
 *
 * <return>
 *		void
 * </return>
 *
 */

void	ft_putnbr(int n, int *nb_char_printed)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", nb_char_printed);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', nb_char_printed);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, nb_char_printed);
		ft_putnbr(n % 10, nb_char_printed);
	}
	else
		ft_putchar(n + '0', nb_char_printed);
}
