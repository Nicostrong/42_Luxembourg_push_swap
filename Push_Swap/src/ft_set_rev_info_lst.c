/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_rev_info_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:28:28 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 09:13:16 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_set_target_rev(t_num **lst_node, t_num **lst_target)
 * </summary>
 *
 * <description>
 *	ft_set_target_rev set the target value in stack_a.The target is the number 
 *	just above the value. Like this we sort by desc.
 * </description>
 *
 * <param type="t_num **" name="lst_node">list with all node</param>
 * <param type="t_num **" name="lst_target">list with all target</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_set_target_rev(t_num **lst_node, t_num **lst_target)
{
	int		min_a;
	t_num	*lst_a;
	t_num	*lst_b;

	lst_b = *lst_node;
	while (lst_b)
	{
		lst_a = *lst_target;
		lst_b->target = 2147483647;
		min_a = 2147483647;
		while (lst_a)
		{
			if (lst_b->value < lst_a->value && lst_b->target > lst_a->value)
				lst_b->target = lst_a->value;
			if (lst_a->value < min_a)
				min_a = lst_a->value;
			lst_a = lst_a->next;
		}
		if (lst_b->target == 2147483647)
			lst_b->target = min_a;
		lst_b = lst_b->next;
	}
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_set_cost_rev(t_num **src, t_num **dest, t_info *info)
 * </summary>
 *
 * <description>
 *	ft_set_cost_rev set how many mvt we need to push this node over the target.
 * </description>
 *
 * <param type="t_num **" name="src">source list</param>
 * <param type="t_num **" name="dest">target list</param>
 * <param type="t_info *" name="info">informations about the list</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_set_cost_rev(t_num **src, t_num **dest, t_info *info)
{
	t_num	*current;
	t_num	*tmp;

	current = *src;
	while (current)
	{
		current->cost = 0;
		tmp = *dest;
		while (tmp && tmp->value != current->target)
			tmp = tmp->next;
		if (!current->reverse)
			current->cost = current->index;
		else
			current->cost = info->nb_val_b - current->index;
		if (tmp && tmp->reverse)
			current->cost += info->nb_val_a - tmp->index;
		else if (tmp)
			current->cost += tmp->index;
		current = current->next;
	}
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_set_all_info(t_num **lst_a, t_num **lst_b, t_info *info)
 * </summary>
 *
 * <description>
 *	ft_set_all_info set all info about each node. The index, the target, the 
 *	reverse and the cost.
 * </description>
 *
 * <param type="t_num **" name="lst_a">list 1</param>
 * <param type="t_num **" name="lst_b">list 2</param>
 * <param type="t_info *" name="info">informations about the list</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_set_all_rev_info(t_num **lst_a, t_num **lst_b, t_info *info)
{
	ft_set_index(lst_a, lst_b);
	ft_set_reverse(lst_a, info->nb_val_a, lst_b, info->nb_val_b);
	ft_set_target_rev(lst_b, lst_a);
	ft_set_cost_rev(lst_b, lst_a, info);
}
