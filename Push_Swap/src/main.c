/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:33:27 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 08:33:22 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>program</cat>
 *
 * <summary>
 *	pusch_swap
 * </summary>
 *
 * <description>
 *	pusch_swap is a program to sort a list of integer passed in argument.
 *	All argument are integer and uniq. It's outup all instruction to sort the
 *	list.
 * </description>
 *
 * <param type="int" name="argc">number of arguments</param>
 * <param type="char **" name="argv">list of integer to sort</param>
 *
 * <return>
 *	print all instructions to sort the list, one instruction by line.
 *	Error if there are an error on the arguments.
 * </return>
 *
 */

int	main(int argc, char **argv)
{
	t_num	*stack_a;
	t_info	*info;

	if (argc < 2)
		return (0);
	if (!check_args(argc, argv))
		ft_exit_error(NULL, NULL);
	stack_a = ft_parse_arg(--argc, argv);
	info = ft_get_info(stack_a);
	if (!ft_issort_asc(stack_a) && info->nb_val_a > 1)
		ft_choose_sort(&stack_a, info);
	lst_del_all(stack_a);
	free(info);
	exit(EXIT_SUCCESS);
}
