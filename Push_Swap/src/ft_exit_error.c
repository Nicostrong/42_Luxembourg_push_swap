/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:14:52 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 09:06:21 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>memory</cat>
 *
 * <summary>
 * 	void	ft_exit_error(t_num *stack_a, t_info *info)
 * </summary>
 *
 * <description>
 * 	ft_exit_error free all allocation memory before exiting.
 * </description>
 *
 * <param type="t_num *" name="stack_a">list to sort</param>
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_exit_error(t_num *stack_a, t_info *info)
{
	if (stack_a)
		lst_del_all(stack_a);
	ft_free(info);
	ft_putendl_fd("Error", 2);
	exit (EXIT_FAILURE);
}
