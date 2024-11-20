/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 08:28:12 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 09:06:51 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	t_info	*ft_init_info(void)
 * </summary>
 *
 * <description>
 *	ft_init_info initialize a structure's info.
 * </description>
 *
 * <param type="void" name="">void</param>
 *
 * <return>
 *	a pointer to initialized list info.
 * </return>
 *
 */

t_info	*ft_init_info(void)
{
	t_info	*info;

	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!info)
	{
		ft_putendl_fd("Error.\n", 2);
		exit(EXIT_FAILURE);
	}
	info->val_min = 2147483647;
	info->val_max = -2147483648;
	return (info);
}

/*
 * <cat>lst</cat>
 *
 * <summary>
 *	t_info	*ft_get_info(t_num *lst)
 * </summary>
 *
 * <description>
 *	ft_get_info catch some information about the t_num list passed in parameter.
 * </description>
 *
 * <param type="t_num *" name="lst">list of integer</param>
 *
 * <return>
 *	a pointer to the list info with all informations settings.
 * </return>
 *
 */

t_info	*ft_get_info(t_num *lst)
{
	t_info	*info;

	info = ft_init_info();
	while (lst)
	{
		if (lst->value < info->val_min)
			info->val_min = lst->value;
		if (lst->value > info->val_max)
			info->val_max = lst->value;
		info->nb_val_a++;
		lst = lst->next;
	}
	return (info);
}

/*
 * <cat>print</cat>
 *
 * <summary>
 *	void	info_print(t_info *info)
 * </summary>
 *
 * <description>
 *	info_print print all value in the struct info.
 * </description>
 *
 * <param type="t_info *" name="info">structure with all info</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	info_print(t_info *info)
{
	ft_printf("\n==============================\n");
	ft_printf("INFOS :");
	ft_printf("\n==============================\n");
	ft_printf("MIN = %d\n", info->val_min);
	ft_printf("MAX = %d\n", info->val_max);
	ft_printf("NB VAL A = %d\n", info->nb_val_a);
	ft_printf("NB VAL B = %d\n", info->nb_val_b);
	ft_printf("\n==============================\n");
}
