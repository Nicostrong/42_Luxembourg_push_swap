/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:42:35 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 09:07:44 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_sort_three(t_num **stack)
 * </summary>
 *
 * <description>
 *	ft_sort_three sort a list of 3 int.
 * </description>
 *
 * <param type="t_num **" name="stack">list to sort</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_sort_three(t_num **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (!*stack || !(*stack)->next)
		return ;
	if (a > b && b < c && a < c)
		ft_sa(stack);
	else if (a > b && b > c)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else if (a > b && a > c && b < c)
		ft_ra(stack);
	else if (a < b && a > c)
		ft_rra(stack);
	else if (a < b && b > c && a < c)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_sort_four(t_num **stack)
 * </summary>
 *
 * <description>
 *	ft_sort_four sort a list of 4 int.
 * </description>
 *
 * <param type="t_num **" name="stack">list to sort</param>
 * <param type="t_info *" name="info">info struct</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_sort_four(t_num **stack, t_info *info)
{
	t_num	*lst_b;

	ft_pb(&lst_b, stack, info);
	ft_sort_three(stack);
	if (lst_b->value < (*stack)->value)
		ft_pa(stack, &lst_b, info);
	else if (lst_b->value > (*stack)->next->next->value)
	{
		ft_pa(stack, &lst_b, info);
		ft_ra(stack);
	}
	else if ((lst_b->value < (*stack)->next->value))
	{
		ft_ra(stack);
		ft_pa(stack, &lst_b, info);
		ft_rra(stack);
	}
	else if ((lst_b->value < (*stack)->next->next->value))
	{
		ft_rra(stack);
		ft_pa(stack, &lst_b, info);
		ft_rra(stack);
		ft_rra(stack);
	}
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_sort_five(t_num **stack_a, t_num **stack_b, t_info *info)
 * </summary>
 *
 * <description>
 *	ft_sort_five sort a list of 5 int.
 * </description>
 *
 * <param type="t_num **" name="stack_a">list to sort</param>
 * <param type="t_num **" name="stack_b">list auxiliare</param>
 * <param type="t_info *" name="info">info struct</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_sort_five(t_num **stack_a, t_num **stack_b, t_info *info)
{
	ft_put_min_in_b(stack_a, stack_b, info);
	ft_put_min_in_b(stack_a, stack_b, info);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b, info);
	ft_pa(stack_a, stack_b, info);
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_put_min_in_b(t_num **stack_a, t_num **stack_b, t_info *info)
 * </summary>
 *
 * <description>
 *	ft_put_min_in_b put the minimum value in stack_a on stack_b.
 * </description>
 *
 * <param type="t_num **" name="stack_a">list to sort</param>
 * <param type="t_num **" name="stack_b">list auxiliare</param>
 * <param type="t_info *" name="info">info struct</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_put_min_in_b(t_num **stack_a, t_num **stack_b, t_info *info)
{
	int	val_min;

	val_min = ft_min(*stack_a);
	while (*stack_a && (*stack_a)->value != val_min)
	{
		if ((*stack_a)->next->value == val_min
			|| (*stack_a)->next->next->value == val_min
			|| (*stack_a)->next->next->next->value == val_min)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
	ft_pb(stack_b, stack_a, info);
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	int	ft_min(t_num *stack)
 * </summary>
 *
 * <description>
 *	ft_min return the minumum value on the stack.
 * </description>
 *
 * <param type="t_num **" name="stack">list to parse</param>
 *
 * <return>
 *	the minimum value in stack.
 * </return>
 *
 */

int	ft_min(t_num *stack)
{
	int	min;

	min = 2147483647;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}
