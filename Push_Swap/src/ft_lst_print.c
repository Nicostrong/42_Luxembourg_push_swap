/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2008/04/20 10:34:39 by Nicostrong        #+#    #+#             */
/*   Updated: 2024/11/20 08:31:13 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>print</cat>
 *
 * <summary
 *	void	lst_print(t_num *lst)
 * </summary>
 *
 * <description>
 *	lst_print print the value of linked list.
 * </description>
 *
 * <param type="t_num *" name="lst">linked list</param>
 *
 * <return>
 *	void
 * </return>
 *
 */

void	lst_print(t_num *lst, char c)
{
	ft_printf("\n==============================\n");
	ft_printf("Value in list %c :\n", c);
	ft_printf("\n==============================\n");
	while (lst)
	{
		ft_printf("%d\n", lst->value);
		lst = lst->next;
	}
	ft_printf("\n==============================\n");
}

/*
 * <cat>print</cat>
 *
 * <summary
 *	void	lst_print_all(t_num *lst)
 * </summary>
 *
 * <description>
 *	lst_print_all print all variable of linked list.
 * </description>
 *
 * <param type="t_num *" name="lst">linked list</param>
 *
 * <return>
 *	void
 * </return>
 *
 */

void	lst_print_all(t_num *lst, char c)
{
	ft_printf("\n==============================\n");
	ft_printf("Info list %c :\n", c);
	ft_printf("\n==============================\n");
	while (lst)
	{
		ft_printf("Before	=>	%p\n", lst->before);
		ft_printf("Value	=> 	%d\n", lst->value);
		ft_printf("Index	=> 	%d\n", lst->index);
		ft_printf("Targer	=> 	%d\n", lst->target);
		ft_printf("Cost	=> 	%d\n", lst->cost);
		ft_printf("Reverse	=> 	%d\n", lst->reverse);
		ft_printf("Next	=> 	%p\n", lst->next);
		lst = lst->next;
	}
	ft_printf("\n==============================\n");
}
