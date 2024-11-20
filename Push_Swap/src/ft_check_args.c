/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:33:21 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 08:30:25 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	check_args(int argc, char **argv)
 * </summary>
 *
 * <description>
 *	check_args check if all arguments passed are of type intger and unique.
 * </description>
 *
 * <param type="int" name="argc">number of arg in the array</param>
 * <param type="char **" name="argv">array of args</param>
 *
 * <return>
 *	1 if all arguments are integer and unique.
 *	0 if one argument isn't a digit.
 * </return>
 *
 */

int	check_args(int argc, char **argv)
{
	if (ft_only_digit(argc, argv))
		if (ft_uniq_int(argc, argv))
			return (1);
	return (0);
}

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_only_digit(int nb_argc, char **array)
 * </summary>
 *
 * <description>
 *	ft_only_digit check if all arguments are a digit || ' ' || '-' || '+'.
 *	In case with one argument with many values we accept space and sign '-' and 
 *	'+'.
 * </description>
 *
 * <param type="int" name="nb_arg">number of arg in the array</param>
 * <param type="char **" name="array">array of args</param>
 *
 * <return>
 *	1 if all arguments are a digits with space.
 *	0 if one argument isn't a digit.
 * </return>
 *
 */

int	ft_only_digit(int nb_argc, char **array)
{
	int		index;
	char	*ptr;

	index = 1;
	while (index < nb_argc)
	{
		ptr = array[index++];
		while (*ptr)
		{
			if (!(ft_isdigit(*ptr) \
			|| *ptr == ' ' || *ptr == '-' || *ptr == '+'))
				return (0);
			ptr++;
		}
	}
	return (1);
}

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_uniq_int(int nb_argc, char **array)
 * </summary>
 *
 * <description>
 *	ft_uniq_int check if all arguments are integer and unique.
 * </description>
 *
 * <param type="int" name="nb_arg">number of arg in the array</param>
 * <param type="char **" name="array">array of args</param>
 *
 * <return>
 *	1 if all arguments are integer.
 *	0 if one argument isn't a digit.
 * </return>
 *
 */

int	ft_uniq_int(int nb_argc, char **array)
{
	int			is_alloc;
	int			index;
	char		**array_arg;

	is_alloc = 0;
	if (nb_argc == 2)
	{
		array_arg = ft_split(array[nb_argc - 1], ' ');
		is_alloc = 1;
	}
	else
		array_arg = ++array;
	index = 0;
	while (array_arg[index] != NULL)
	{
		if (!ft_isint(ft_atoll(array_arg[index])))
			return (0);
		if (!ft_isuniq(ft_atoll(array_arg[index]), array_arg))
			return (0);
		index++;
	}
	if (is_alloc)
		ft_free_array(array_arg);
	return (1);
}

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_isuniq(long long nb, char **array)
 * </summary>
 *
 * <description>
 *	ft_isuniq check if all arguments are unique.
 * </description>
 *
 * <param type="long long" name="nb">number to check in array</param>
 * <param type="char **" name="array">array of values</param>
 *
 * <return>
 *	1 if the number is unique.
 *	0 if the number isn't unique.
 * </return>
 *
 */

int	ft_isuniq(long long nb, char **array)
{
	int	occ;
	int	index;

	occ = 0;
	index = 0;
	while (array[index] != NULL)
	{
		if (ft_atoll(array[index]) == nb)
			occ++;
		index++;
	}
	if (occ == 1)
		return (1);
	return (0);
}
