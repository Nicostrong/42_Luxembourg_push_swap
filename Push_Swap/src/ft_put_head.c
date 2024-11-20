/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:42:33 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 08:32:21 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_put_in_head(t_num **src, t_num **dest, t_info *info)
 * </summary>
 *
 * <description>
 *	ft_put_in head put the node in src and the target on dest on the top of each
 *	 list.
 * </description>
 *
 * <param type="t_num **" name="src">list of node</param>
 * <param type="t_num **" name="dest">list of target</param>
 * <param type="t_info *" name="info">info struct</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_put_in_head(t_num **src, t_num **dest, t_info *info)
{
	int		min_cost;
	t_num	*node;
	t_num	*target;

	ft_set_all_info(src, dest, info);
	min_cost = ft_min_cost(*src);
	node = ft_get_node(*src, min_cost);
	target = ft_get_target(*dest, node->target);
	ft_make_move(node, target, src, dest);
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_put_in_head_rev(t_num **src, t_num **dest, t_info *info)
 * </summary>
 *
 * <description>
 *	ft_put_in head_re put the node in src and the target on dest on the top of 
 *	each list but for the return from B => to A.
 * </description>
 *
 * <param type="t_num **" name="src">list of node</param>
 * <param type="t_num **" name="dest">list of target</param>
 * <param type="t_info *" name="info">info struct</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_put_in_head_rev(t_num **src, t_num **dest, t_info *info)
{
	int		min_cost;
	t_num	*node;
	t_num	*target;

	ft_set_index(src, dest);
	ft_set_reverse(src, info->nb_val_a, dest, info->nb_val_b);
	ft_set_target_rev(src, dest);
	min_cost = ft_min_cost(*src);
	node = ft_get_node(*src, min_cost);
	target = ft_get_target(*dest, node->target);
	ft_make_move_rev(node, target, src, dest);
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_make_move(t_num *node, t_num *target, t_num **src, t_num **dest)
 * </summary>
 *
 * <description>
 *	ft_make_move execute all command to put the node and the target at the top 
 *	of the list.
 * </description>
 *
 * <param type="t_num **" name="node">node to move</param>
 * <param type="t_num **" name="target">target of the node</param>
 * <param type="t_num **" name="src">source list</param>
 * <param type="t_num **" name="dest">destination list</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_make_move(t_num *node, t_num *target, t_num **src, t_num **dest)
{
	while (!((*src)->value == node->value && (*dest)->value == target->value))
	{
		if ((*src)->value == node->value && !target->reverse)
			ft_rb(dest);
		else if ((*src)->value == node->value && target->reverse)
			ft_rrb(dest);
		else if ((*dest)->value == target->value && !node->reverse)
			ft_ra(src);
		else if ((*dest)->value == target->value && node->reverse)
			ft_rra(src);
		else if (node->reverse && target->reverse)
			ft_rrr(src, dest);
		else if (!node->reverse && !target->reverse)
			ft_rr(src, dest);
		else if (target->reverse)
			ft_rrb(dest);
		else if (!target->reverse)
			ft_rb(dest);
		else if (node->reverse)
			ft_rra(src);
		else if (!node->reverse)
			ft_ra(src);
		ft_set_index(src, dest);
	}
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void ft_make_move_rev(t_num *node, t_num *target, t_num **src, t_num **dest)
 * </summary>
 *
 * <description>
 *	ft_make_move_rev execute all command to put the node and the target at the 
 *	top of the list, but for the reverse.
 * </description>
 *
 * <param type="t_num **" name="node">node to move</param>
 * <param type="t_num **" name="target">target of the node</param>
 * <param type="t_num **" name="src">source list</param>
 * <param type="t_num **" name="dest">destination list</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_make_move_rev(t_num *node, t_num *target, t_num **src, t_num **dest)
{
	while (!((*src)->value == node->value && (*dest)->value == target->value))
	{
		if ((*src)->value == node->value && !target->reverse)
			ft_ra(dest);
		else if ((*src)->value == node->value && target->reverse)
			ft_rra(dest);
		else if ((*dest)->value == target->value && !node->reverse)
			ft_rb(src);
		else if ((*dest)->value == target->value && node->reverse)
			ft_rrb(src);
		else if (node->reverse && target->reverse)
			ft_rrr(src, dest);
		else if (!node->reverse && !target->reverse)
			ft_rr(src, dest);
		else if (target->reverse)
			ft_rra(dest);
		else if (!target->reverse)
			ft_ra(dest);
		else if (node->reverse)
			ft_rrb(src);
		else if (!node->reverse)
			ft_rb(src);
		ft_set_index(src, dest);
	}
}
