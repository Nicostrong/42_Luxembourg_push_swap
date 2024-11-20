/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 07:34:18 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 08:32:50 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_swap(t_num **stack)
 * </summary>
 *
 * <description>
 *	ft_swap switch the first element with the second on the linked list.
 * </description>
 *
 * <param type="t_num **" name="stack">linked list</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_swap(t_num	**stack)
{
	t_num	*first;
	t_num	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->before = second;
	first->next = second->next;
	if (second->next)
		first->next->before = first;
	second->next = first;
	second->before = NULL;
	*stack = second;
}

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_sa(t_num **stack_a)
 * </summary>
 *
 * <description>
 *	ft_sa switch the first element with the second on the linked list A.
 * </description>
 *
 * <param type="t_num **" name="stack_a">linked list</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_sa(t_num	**stack_a)
{
	ft_printf("sa\n");
	ft_swap(stack_a);
}

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_sb(t_num **stack_b)
 * </summary>
 *
 * <description>
 *	ft_sb switch the first element with the second on the linked list B.
 * </description>
 *
 * <param type="t_num **" name="stack_b">linked list</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_sb(t_num **stack_b)
{
	ft_printf("sb\n");
	ft_swap(stack_b);
}

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_ss(t_num **stack_a, t_num **stack_b)
 * </summary>
 *
 * <description>
 *	ft_ss switch the first element with the second on the linked list A and B.
 * </description>
 *
 * <param type="t_num **" name="stack_a">linked list A</param>
 * <param type="t_num **" name="stack_b">linked list B</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_ss(t_num **stack_a, t_num **stack_b)
{
	ft_printf("ss\n");
	ft_swap(stack_a);
	ft_swap(stack_b);
}
