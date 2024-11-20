/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 07:22:08 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 08:32:17 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_push(t_num **dest, t_num **src)
 * </summary>
 *
 * <description>
 *	ft_push move the first element of the linked list src to dest.
 * </description>
 *
 * <param type="t_num **" name="dest">destination list</param>
 * <param type="t_num **" name="src">source list</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_push(t_num **dest, t_num **src)
{
	t_num	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		if (*src)
			(*src)->before = NULL;
		if (*dest)
		{
			tmp->next = *dest;
			(*dest)->before = tmp;
		}
		else
			tmp->next = NULL;
		*dest = tmp;
	}
}

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_pa(t_num **dest, t_num **src)
 * </summary>
 *
 * <description>
 *	ft_push move the first element of the linked list B to list A.
 * </description>
 *
 * <param type="t_num **" name="dest">destination list</param>
 * <param type="t_num **" name="src">source list</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_pa(t_num **dest, t_num **src, t_info *info)
{
	ft_printf("pa\n");
	info->nb_val_a++;
	info->nb_val_b--;
	ft_push(dest, src);
}

/*
 * <cat>list</cat>
 *
 * <summary>
 * 	void	ft_pb(t_num **dest, t_num **src)
 * </summary>
 *
 * <description>
 *	ft_pb move the first element of the linked list A to list B.
 * </description>
 *
 * <param type="t_num **" name="dest">destination list</param>
 * <param type="t_num **" name="src">source list</param>
 *
 * <return>
 * 	void.
 * </return>
 *
 */

void	ft_pb(t_num **dest, t_num **src, t_info *info)
{
	ft_printf("pb\n");
	info->nb_val_a--;
	info->nb_val_b++;
	ft_push(dest, src);
}
