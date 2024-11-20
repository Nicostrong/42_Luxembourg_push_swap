/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:53:08 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 09:08:46 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 *	t_num	*lst_new(int content, int index)
 * </summary>
 *
 * <description>
 *	lst_new create a new list and set the value with content.
 * </description>
 *
 * <param type="int" name="content">value to save in list</param>
 * <param type="int" name="index">position in list</param>
 *
 * <return>
 *	pointer to this list.
 * </return>
 *
 */

t_num	*node_new(int content, int index)
{
	t_num	*new;

	new = (t_num *)ft_calloc(1, sizeof(t_num));
	if (!new)
		exit(EXIT_FAILURE);
	new->before = NULL;
	new->value = content;
	new->index = index;
	new->target = -2147483648;
	new->next = NULL;
	return (new);
}

/*
 * <cat>list</cat>
 *
 * <summary>
 *	t_num	*node_move(t_num *node_to_move, t_num *dest)
 * </summary>
 *
 * <description>
 *	node_move move a node to a destination.
 * </description>
 *
 * <param type="t_num *" name="node_to_move">node to move</param>
 * <param type="t_num *" name="dest">destination of the list</param>
 *
 * <return>
 *	a pointer to the first element of dest.
 * </return>
 *
 */

t_num	*node_move(t_num *node_to_move, t_num *dest)
{
	t_num	*tmp;

	if (node_to_move == NULL)
		return (dest);
	tmp = node_remove(node_to_move);
	return (add_front(dest, tmp));
}

/*
 * <cat>list</cat>
 *
 * <summary>
 *	t_num	*node_remove(t_num *node_to_remove)
 * </summary>
 *
 * <description>
 *	node_remove remove a node in linked list.
 * </description>
 *
 * <param type="t_num *" name="node_to_remove">node to remove</param>
 *
 * <return>
 *	a pointer of the node removed.
 * </return>
 *
 */

t_num	*node_remove(t_num *node_to_remove)
{
	if (!node_to_remove)
		return (NULL);
	if (node_to_remove->before != NULL)
		node_to_remove->before->next = node_to_remove->next;
	if (node_to_remove->next != NULL)
		node_to_remove->next->before = node_to_remove->before;
	node_to_remove->next = NULL;
	node_to_remove->before = NULL;
	return (node_to_remove);
}

/*
 * <cat>list</cat>
 *
 * <summary>
 *	t_num	*add_back(t_num *lst, t_num *new)
 * </summary>
 *
 * <description>
 *	add_back add a new list at the end of linked list and set the address
 *	for before and next.
 * </description>
 *
 * <param type="t_num *" name="lst">linked list</param>
 * <param type="t_num *" name="new">new list to add back</param>
 *
 * <return>
 *	a pointer to the new linked list.
 * </return>
 *
 */

t_num	*add_back(t_num *lst, t_num *new)
{
	t_num	*first;

	if (!lst)
	{
		new->before = NULL;
		new->next = NULL;
		return (new);
	}
	first = lst;
	while (lst->next)
		lst = lst->next;
	if (lst->next == NULL)
	{
		lst->next = new;
		new->before = lst;
		new->next = NULL;
	}
	return (first);
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	t_num	*add_front(t_num *lst, t_num *new)
 * </summary>
 *
 * <description>
 *	add_front add the new list at the start of linked list.
 * </description>
 *
 * <param type="t_num *" name="lst">linked list</param>
 * <param type="t_num *" name="new">new list</param>
 *
 * <return>
 *	a pointer to the new linked list.
 * </return>
 *
 */

t_num	*add_front(t_num *lst, t_num *new)
{
	if (lst == NULL)
	{
		new->before = NULL;
		new->next = NULL;
		return (new);
	}
	new->next = lst;
	lst->before = new;
	return (new);
}
