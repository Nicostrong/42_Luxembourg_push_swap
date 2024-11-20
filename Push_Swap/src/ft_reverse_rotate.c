/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:29:00 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 08:32:25 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_reverse_rotate(t_num **stack)
 * </summary>
 *
 * <description>
 *	ft_reverse_rotate move the last element of the linked list stack to the 
 *	firts.
 * </description>
 *
 * <param type="t_num **" name="sack">linked list to modificate</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_reverse_rotate(t_num **stack)
{
	t_num	*first;
	t_num	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	first = tmp;
	first->before->next = NULL;
	first->before = NULL;
	first->next = *stack;
	(*stack)->before = first;
	*stack = first;
}

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_rra(t_num **stack_a)
 * </summary>
 *
 * <description>
 *	ft_rra move the last element of the linked list A to the start.
 * </description>
 *
 * <param type="t_num **" name="sack_a">linked list A to modificate</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_rra(t_num **stack_a)
{
	ft_printf("rra\n");
	ft_reverse_rotate(stack_a);
}

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_rrb(t_num **stack_b)
 * </summary>
 *
 * <description>
 *	ft_rrb move the last element of the linked list B to the start.
 * </description>
 *
 * <param type="t_num **" name="sack_b">linked list B to modificate</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_rrb(t_num **stack_b)
{
	ft_printf("rrb\n");
	ft_reverse_rotate(stack_b);
}

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_rrr(t_num **stack_a, t_num **stack_b)
 * </summary>
 *
 * <description>
 *	ft_rrr move the last element of the linked list A to the start.
 *	And move the last element of the linked list B to the start.
 * </description>
 *
 * <param type="t_num **" name="sack_a">linked list A to modificate</param>
 * <param type="t_num **" name="sack_b">linked list B to modificate</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_rrr(t_num **stack_a, t_num **stack_b)
{
	ft_printf("rrr\n");
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
