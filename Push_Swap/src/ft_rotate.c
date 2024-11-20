/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 07:58:22 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 08:32:29 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_rotate(t_num **stack)
 * </summary>
 *
 * <description>
 *	ft_rotate move the first element of the linked list stack to the end.
 * </description>
 *
 * <param type="t_num **" name="sack">linked list to modificate</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_rotate(t_num **stack)
{
	t_num	*last;
	t_num	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	*stack = last->next;
	(*stack)->before = NULL;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	last->before = tmp;
	last->next = NULL;
}

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_ra(t_num **stack_a)
 * </summary>
 *
 * <description>
 *	ft_ra move the first element of the linked list A to the end.
 * </description>
 *
 * <param type="t_num **" name="sack_a">linked list A to modificate</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_ra(t_num **stack_a)
{
	ft_printf("ra\n");
	ft_rotate(stack_a);
}

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_rb(t_num **stack_b)
 * </summary>
 *
 * <description>
 *	ft_rb move the first element of the linked list B to the end.
 * </description>
 *
 * <param type="t_num **" name="sack_b">linked list B to modificate</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_rb(t_num **stack_b)
{
	ft_printf("rb\n");
	ft_rotate(stack_b);
}

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_rr(t_num **stack_a, t_num **stack_b)
 * </summary>
 *
 * <description>
 *	ft_rr move the first element of the linked list A to the end.
 *	And move the first element of the linked list B to the end.
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

void	ft_rr(t_num **stack_a, t_num **stack_b)
{
	ft_printf("rr\n");
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
