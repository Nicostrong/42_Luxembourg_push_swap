/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2008/04/20 10:00:40 by Nicostrong        #+#    #+#             */
/*   Updated: 2024/11/20 09:06:13 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 *	void	lst_del(t_num *del)
 * </summary>
 *
 * <description>
 *	lst_del remove the list on linked list.
 * </description>
 *
 * <param type="t_num *" name="del">list to del</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	lst_del(t_num *del)
{
	if (del == NULL)
		return ;
	if (del->before != NULL)
		del->before->next = del->next;
	if (del->next != NULL)
		del->next->before = del->before;
	ft_free(del);
}

/*
 * <cat>list</cat>
 *
 * <summary>
 *	void	lst_del_all(t_num *lst)
 * </summary>
 *
 * <description>
 *	lst_del remove all list on linked list.
 * </description>
 *
 * <param type="t_num *" name="lst">linked list to del</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	lst_del_all(t_num *lst)
{
	t_num	*tmp;

	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		lst_del(tmp);
	}
	ft_free(lst);
}
