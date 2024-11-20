/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:14:38 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 08:32:41 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_choise_sort(t_num **stack_a, t_info *info)
 * </summary>
 *
 * <description>
 *	ft_choise_sort look for the info of the stack and shoise what to do to sort 
 *	efficiently the linked list.
 * </description>
 *
 * <param type="t_num *" name="stack_a">source of linked list</param>
 * <param type="t_info *" name="info">info of linked lists</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_choose_sort(t_num **stack_a, t_info *info)
{
	t_num	*stack_b;

	if (info->nb_val_a == 2)
		ft_sa(stack_a);
	else if (info->nb_val_a == 3)
		ft_sort_three(stack_a);
	else if (info->nb_val_a == 4)
		ft_sort_four(stack_a, info);
	else if (info->nb_val_a == 5)
		ft_sort_five(stack_a, &stack_b, info);
	else
	{
		ft_split_list(stack_a, &stack_b, info);
		ft_sort(stack_a, &stack_b, info);
	}
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_split_list(t_num **stack_a, t_num **stack_b, t_info *info)
 * </summary>
 *
 * <description>
 *	ft_split_list split the list in two list.
 * </description>
 *
 * <param type="t_num *" name="stack_a">source of linked list</param>
 * <param type="t_num *" name="stack_b">destination of linked lists</param>
 * <param type="t_info *" name="info">info of linked lists</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_split_list(t_num **stack_a, t_num **stack_b, t_info *info)
{
	t_num	*lst_b;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	lst_b = NULL;
	if (info->nb_val_a > 4)
		ft_pb(&lst_b, stack_a, info);
	ft_pb(&lst_b, stack_a, info);
	*stack_b = lst_b;
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_fusion(t_num **dest, t_num **src, t_info *info)
 * </summary>
 *
 * <description>
 *	ft_fusion make the fusion betwenn two list.
 * </description>
 *
 * <param type="t_num *" name="dest">destination of linked list</param>
 * <param type="t_num *" name="src">source of linked lists</param>
 * <param type="t_info *" name="info">info of linked lists</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_fusion(t_num **dest, t_num **src, t_info *info)
{
	t_num	*lst_a;
	t_num	*tmp;

	lst_a = *dest;
	tmp = *src;
	while (tmp)
	{
		ft_set_all_rev_info(&lst_a, &tmp, info);
		ft_put_in_head_rev(&tmp, &lst_a, info);
		ft_pa(&lst_a, &tmp, info);
	}
	ft_set_reverse(&lst_a, info->nb_val_a, &tmp, info->nb_val_b);
	*dest = lst_a;
	tmp = *dest;
	while (tmp->value != info->val_min)
		tmp = tmp->next;
	while (lst_a->value != tmp->value && !ft_issort_asc(*dest))
	{
		if (tmp->reverse)
			ft_rra(dest);
		else
			ft_ra(dest);
	}
}

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_issort_asc(t_num *stack)
 * </summary>
 *
 * <description>
 *	ft_issort_asc check if the value in the linked list are ascending sorted.
 * </description>
 *
 * <param type="t_num *" name="stack">linked list with values</param>
 *
 * <return>
 *	1 if all the list is ascending sortorted.
 *	0 if all the list isn't ascending sorted.
 * </return>
 *
 */

int	ft_issort_asc(t_num *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

/*
 * <cat>bool</cat>
 *
 * <summary>
 *	int	ft_issort_dec(t_num *stack)
 * </summary>
 *
 * <description>
 *	ft_issort_dec check if the value in the linked list are decending sorted.
 * </description>
 *
 * <param type="t_num *" name="stack">linked list with values</param>
 *
 * <return>
 *	1 if all the list is decending sortorted.
 *	0 if all the list isn't decending sorted.
 * </return>
 *
 */

int	ft_issort_dec(t_num *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}
