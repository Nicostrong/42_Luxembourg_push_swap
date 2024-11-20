/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:40:15 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 08:32:12 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>args</cat>
 *
 * <summary>
 *	t_num	*ft_arg_to_array(char *args)
 * </summary>
 *
 * <description>
 *	ft_arg_to_array catch a string passed in param to a program. This string 
 *	contain some info separated by a single char.
 * </description>
 *
 * <param type="char *" name="args">string contain somes args</param>
 *
 * <return>
 *	pass an array to ft_arg_to_list to return a linked list.
 * </return>
 *
 */

t_num	*ft_arg_to_array(char *args)
{
	char	**array_arg;
	int		nb_arg;

	nb_arg = ft_countsection(args, ' ');
	array_arg = ft_split(args, ' ');
	return (ft_args_to_list(nb_arg, array_arg, 1));
}

/*
 * <cat>args</cat>
 *
 * <summary>
 *	t_num	*ft_arg_to_list(int count, char **array, int isalloc)
 * </summary>
 *
 * <param type="int" name="count">number of arg in the array</param>
 * <param type="char **" name="array">array of args</param>
 * <param type="int" name="isalloc">indicat if the array is allowed</param>
 *
 * <return>
 *	the first element of a linked list.
 * </return>
 *
 */

t_num	*ft_args_to_list(int count, char **array, int isalloc)
{
	int		index;
	t_num	*stack;
	t_num	*new_lst;

	index = 0;
	stack = NULL;
	while (index < count)
	{
		new_lst = node_new(ft_atoi(array[index]), index);
		stack = add_back(stack, new_lst);
		index++;
	}
	if (isalloc)
		ft_free_array(array);
	return (stack);
}

/*
 * <cat>args</cat>
 *
 * <summary>
 *	t_num	*ft_parse_arg(int nb_arg, char **args)
 * </summary>
 *
 * <description>
 *	ft_parse_arg call the correct function to catch the args.
 * </description>
 *
 * <param type="int" name="nb_arg">number of arg in the array</param>
 * <param type="char **" name="array">array of args</param>
 *
 * <return>
 *	the first element of a linked list.
 * </return>
 *
 */

t_num	*ft_parse_arg(int nb_arg, char **args)
{
	if (nb_arg == 1)
		return (ft_arg_to_array(args[nb_arg]));
	return (ft_args_to_list(nb_arg, ++args, 0));
}
