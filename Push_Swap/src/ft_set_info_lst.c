/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_info_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:30:46 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 09:12:26 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_set_index(t_num **lst_a, t_num **lst_b)
 * </summary>
 *
 * <description>
 *	ft_set_index set the index value at all element of the list.
 *	if we want to index just one list, putt the second parametter to NULL.
 * </description>
 *
 * <param type="t_num **" name="lst_a">first linked list to index</param>
 * <param type="t_num **" name="lst_b">second linked list to index</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_set_index(t_num **lst_a, t_num **lst_b)
{
	int		index;
	t_num	*current;

	index = 0;
	current = *lst_a;
	while (current)
	{
		current->index = index;
		current = current->next;
		index++;
	}
	index = 0;
	if (lst_b == NULL)
		return ;
	current = *lst_b;
	while (current)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_set_reverse(t_num **lst_a, int valina, t_num **lst_b, int valinb)
 * </summary>
 *
 * <description>
 *	ft_set_reverse set a bool value to informe if it's important to use a 
 *	reverse function to move the node.
 *	If we need just one list, put NULL for the second and the third parameters.
 * </description>
 *
 * <param type="t_num **" name="lst_a">linked list a to analyse</param>
 * <param type="int" name="valina">number of element in the list a</param>
 * <param type="t_num **" name="lst_b">linked list b to analyse</param>
 * <param type="int" name="valinb">number of element in the list b</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_set_reverse(t_num **lst_a, int valina, t_num **lst_b, int valinb)
{
	t_num	*current;

	current = *lst_a;
	while (current)
	{
		if (current->index > (valina - 1) / 2)
			current->reverse = 1;
		else
			current->reverse = 0;
		current = current->next;
	}
	if (lst_b == NULL)
		return ;
	current = *lst_b;
	while (current)
	{
		if (current->index > (valinb - 1) / 2)
			current->reverse = 1;
		else
			current->reverse = 0;
		current = current->next;
	}
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_set_target(t_num **lst_node, t_num **lst_target)
 * </summary>
 *
 * <description>
 *	ft_set_target set the target value in stack_b. The target is the number just
 *	below the value. Like this we sort by desc.
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

void	ft_set_target(t_num **lst_node, t_num **lst_target)
{
	int		max_b;
	t_num	*lst_a;
	t_num	*lst_b;

	lst_a = *lst_node;
	while (lst_a)
	{
		lst_b = *lst_target;
		lst_a->target = -2147483648;
		max_b = -2147483648;
		while (lst_b)
		{
			if (lst_a->value > lst_b->value && lst_a->target < lst_b->value)
				lst_a->target = lst_b->value;
			if (lst_b->value > max_b)
				max_b = lst_b->value;
			lst_b = lst_b->next;
		}
		if (lst_a->target == -2147483648)
			lst_a->target = max_b;
		lst_a = lst_a->next;
	}
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	void	ft_set_cost(t_num **src, t_num **dest, t_info *info)
 * </summary>
 *
 * <description>
 *	ft_set_cost set how many mvt we need to push this node over the target.
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

void	ft_set_cost(t_num **src, t_num **dest, t_info *info)
{
	t_num	*current;
	t_num	*tmp;

	current = *src;
	while (current)
	{
		tmp = *dest;
		while (tmp && tmp->value != current->target)
			tmp = tmp->next;
		if (!current->reverse)
			current->cost = current->index;
		else
			current->cost = info->nb_val_a - current->index;
		if (tmp && tmp->reverse)
			current->cost += info->nb_val_b - tmp->index;
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

void	ft_set_all_info(t_num **lst_a, t_num **lst_b, t_info *info)
{
	ft_set_index(lst_a, lst_b);
	ft_set_reverse(lst_a, info->nb_val_a, lst_b, info->nb_val_b);
	ft_set_target(lst_a, lst_b);
	ft_set_cost(lst_a, lst_b, info);
}
