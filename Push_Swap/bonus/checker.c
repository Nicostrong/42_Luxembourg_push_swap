/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 08:35:50 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 08:44:20 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
 * <cat>program</cat>
 *
 * <summary>
 *	checker
 * </summary>
 *
 * <description>
 *	checker is a program to test if all instruction send by the pusch_swap prog 
 *	are corrects to sort all interger passed in argument.
 * </description>
 *
 * <param type="int" name="argc">number of arguments</param>
 * <param type="char **" name="argv">list of integer to sort</param>
 *
 * <return>
 *	OK if all instruction sort the list.
 *	KO if the list isn't sort.
 *	Error if there are an error like bad instruction or bad argument.
 * </return>
 *
 */

int	main(int argc, char **argv)
{
	t_num	*stack_a;
	t_num	*stack_b;

	if (argc < 2)
		return (0);
	if (!check_args(argc, argv))
		ft_exit_error(NULL, NULL);
	stack_a = ft_parse_arg(--argc, argv);
	stack_b = NULL;
	ft_execute_cmd(&stack_a, &stack_b);
	if (ft_issort_asc(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	lst_del_all(stack_a);
	lst_del_all(stack_b);
	exit(EXIT_SUCCESS);
}
