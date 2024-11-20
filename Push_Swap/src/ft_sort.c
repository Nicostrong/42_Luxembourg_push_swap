/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/04/20 16:06:25 by Nicostrong        #+#    #+#             */
/*   Updated: 2024/11/20 08:32:45 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_sort(t_num **stack_a, t_num **stack_b, t_info *info)
 * </summary>
 *
 * <description>
 *	ft_sort sort all integer on the stack_a. it can use a second stack to make 
 *	the sort.
 * </description>
 *
 * <param type="t_num **" name="stack_a">list with all integer</param>
 * <param type="t_num **" name="stack_b">list auxiliare</param>
 * <param type="t_info *" name="info">struct with all info</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_sort(t_num **stack_a, t_num **stack_b, t_info *info)
{
	t_num	*lst_a;
	t_num	*lst_b;

	lst_a = *stack_a;
	lst_b = *stack_b;
	while (info->nb_val_a > 3)
	{
		ft_put_in_head(&lst_a, &lst_b, info);
		ft_pb(&lst_b, &lst_a, info);
	}
	if (!ft_issort_asc(lst_a))
		ft_sort_three(&lst_a);
	ft_fusion(&lst_a, &lst_b, info);
	*stack_a = lst_a;
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	int	ft_min_cost(t_num *lst)
 * </summary>
 *
 * <description>
 *	ft_min_cost return the minimum value of tha variable cost on the struct lst.
 * </description>
 *
 * <param type="t_num *" name="lst">list to parse</param>
 * <param type="int" name="min_cost">min cost value</param>
 *
 * <return>
 *	pointer of the node.
 * </return>
 *
 */

int	ft_min_cost(t_num *lst)
{
	int	value;

	value = lst->cost;
	while (lst)
	{
		if (lst->cost < value)
			value = lst->cost;
		lst = lst->next;
	}
	return (value);
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	t_num	*ft_get_node(t_num *lst, int min_cost)
 * </summary>
 *
 * <description>
 *	ft_get_node retrun the pointer of the node.
 * </description>
 *
 * <param type="t_num *" name="lst">list to parse</param>
 * <param type="int" name="min_cost">min cost value</param>
 *
 * <return>
 *	pointer of the node.
 * </return>
 *
 */

t_num	*ft_get_node(t_num *lst, int min_cost)
{
	if (!lst)
		return (NULL);
	while (lst && lst->cost != min_cost)
		lst = lst->next;
	return (lst);
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	t_num	*ft_get_target(t_num *lst, int target)
 * </summary>
 *
 * <description>
 *	ft_get_target retrun the pointer of the target.
 * </description>
 *
 * <param type="t_num *" name="lst">list to parse</param>
 * <param type="int" name="target">target value</param>
 *
 * <return>
 *	pointer of the target.
 * </return>
 *
 */

t_num	*ft_get_target(t_num *lst, int target)
{
	if (!lst)
		return (NULL);
	while (lst && lst->value != target)
		lst = lst->next;
	return (lst);
}
