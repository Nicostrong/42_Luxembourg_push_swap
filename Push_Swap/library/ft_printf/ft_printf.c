/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:59:56 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/15 10:03:31 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * 	<cat>str</cat>
 *
 * 	<summary>
 *		char	*ft_strchr(const char *s, int c)
 *	</summary>
 *
 *	<description>
 *		ft_strchr chearch the first occurence of the char c and return a pointer
 *		to this occurence.
 *	</description>
 *
 *	<param type="const void *" name="s">string to parce</param>
 *	<param type="int" name="c">char to find</param>
 *
 *	<return>
 *		a pointer to the first occurence of the char c or 0 if the char c not in
 *		the string.
 *	</return>
 *
 */

static char	*ft_strchr(const char *s, int c)
{
	if (c > 127)
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

/*
 * <cat>str</cat>
 *
 * <summary>
 *	static int	ft_flag(va_list args, const char flag)
 * </summary>
 *
 * <description>
 *	ft_flag check the flag and call the correct function with the correct
 *	variable.
 * </description>
 *
 * <param type="va_list" name="args">list of variables</param>
 * <param type="const char" name="flag">flag</param>
 *
 * <return>
 *	number of char printed.
 * </return>
 *
 */

static void	ft_flag(va_list args, const char flag, int *nb_char_printed)
{
	void	*ptr;

	if (flag == 'c')
		ft_putchar(va_arg(args, int), nb_char_printed);
	else if (flag == 's')
		ft_putstr(va_arg(args, char *), nb_char_printed);
	else if (flag == 'd' || flag == 'i')
		ft_putnbr(va_arg(args, int), nb_char_printed);
	else if (flag == 'x' || flag == 'X')
		ft_puthexa(flag, va_arg(args, unsigned int), nb_char_printed);
	else if (flag == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
			ft_putaddress(ptr, nb_char_printed);
		else
			ft_putstr("(nil)", nb_char_printed);
	}
	else if (flag == 'u')
		ft_putunsigned(va_arg(args, unsigned int), nb_char_printed);
	else if (flag == '%')
		ft_putchar('%', nb_char_printed);
	else
		return ;
}

/*
 * <cat>print</cat>
 *
 * <summary>
 *	int	ft_printf(const char *s, ...)
 * </summary>
 *
 * <description>
 *	ft_printf make the same think like the native printf in c lib.
 * </description>
 *
 * <param type="const char *" name="s">string with insert tag</param>
 * <param type="va_list" name="...">list of variable to evaluate</param>
 *
 * <return>
 * 	the number of char printing.
 * </return>
 *
 */

int	ft_printf(const char *s, ...)
{
	int		nb_char_printed;
	int		index;
	char	*str;
	va_list	lst_args;

	nb_char_printed = 0;
	index = 0;
	str = (char *)s;
	va_start(lst_args, s);
	while (str[index])
	{
		if (str[index] == '%' && ft_strchr("csdixXpu%", str[index + 1]))
		{
			ft_flag(lst_args, str[index + 1], &nb_char_printed);
			index++;
		}
		else
			ft_putchar(str[index], &nb_char_printed);
		index++;
	}
	va_end(lst_args);
	return (nb_char_printed);
}
