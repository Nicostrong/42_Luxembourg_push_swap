/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:20:55 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 09:04:21 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
 * <cat>list</cat>
 *
 * <summary>
 *	void	ft_execute_cmd(t_num **stack_a, t_num **stack_b)
 * </summary>
 *
 * <description>
 *	ft_execute_cmd execute all instruction read on stdinput.
 * </description>
 *
 * <param type="t_num **" name="stack_a">list to sort</param>
 * <param type="t_num **" name="stack_b">list auxiliar</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_execute_cmd(t_num **stack_a, t_num **stack_b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (ft_strlen(cmd) == 3)
			ft_litle_cmd(cmd, stack_a, stack_b);
		else if (ft_strlen(cmd) == 4)
			ft_big_cmd(cmd, stack_a, stack_b);
		else if (ft_strlen(cmd) == 1)
			return (get_next_line(-1), ft_free(cmd));
		else
			ft_error(stack_a, cmd);
		ft_free(cmd);
		cmd = get_next_line(0);
	}
	ft_free(cmd);
	get_next_line(-1);
}

/*
 * <cat>list</cat>
 *
 * <summary>
 *	void	ft_litle_cmd(char *cmd, t_num **stack_a, t_num **stack_b)
 * </summary>
 *
 * <description>
 *	ft_litle_cmd execute all litle instruction read on stdinput
 * </description>
 *
 * <param type="t_num **" name="stack_a">list to sort</param>
 * <param type="t_num **" name="stack_b">list auxiliar</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_litle_cmd(char *cmd, t_num **stack_a, t_num **stack_b)
{
	if (!ft_strncmp((const char *)cmd, "sa", 2))
		ft_swap(stack_a);
	else if (!ft_strncmp((const char *)cmd, "sb", 2))
		ft_swap(stack_b);
	else if (!ft_strncmp((const char *)cmd, "pa", 2))
		ft_push(stack_a, stack_b);
	else if (!ft_strncmp((const char *)cmd, "pb", 2))
		ft_push(stack_b, stack_a);
	else if (!ft_strncmp((const char *)cmd, "ra", 2))
		ft_rotate(stack_a);
	else if (!ft_strncmp((const char *)cmd, "rb", 2))
		ft_rotate(stack_b);
	else if (!ft_strncmp((const char *)cmd, "rr", 2))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else if (!ft_strncmp((const char *)cmd, "ss", 2))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	else
		ft_error(stack_a, cmd);
}

/*
 * <cat>list</cat>
 *
 * <summary>
 *	void	ft_big_cmd(char *cmd, t_num **stack_a, t_num **stack_b)
 * </summary>
 *
 * <description>
 *	ft_big_cmd execute all litle instruction read on stdinput
 * </description>
 *
 * <param type="t_num **" name="stack_a">list to sort</param>
 * <param type="t_num **" name="stack_b">list auxiliar</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_big_cmd(char *cmd, t_num **stack_a, t_num **stack_b)
{
	if (!ft_strncmp((const char *)cmd, "rra", 3))
		ft_reverse_rotate(stack_a);
	else if (!ft_strncmp((const char *)cmd, "rrb", 3))
		ft_reverse_rotate(stack_b);
	else if (!ft_strncmp((const char *)cmd, "rrr", 3))
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
	}
	else
		ft_error(stack_a, cmd);
}

/*
 * <cat>memory</cat>
 *
 * <summary>
 *	void	ft_error(t_num **stack_a, char *cmd)
 * </summary>
 *
 * <description>
 *	ft_error free all alocation memory and call gnl to free the buffer.
 * </description>
 *
 * <param type="t_num **" name="stack_a">list to sort</param>
 * <param type="char *" name="cmd">pointer to the last commande</param>
 *
 * <return>
 *	void.
 * </return>
 *
 */

void	ft_error(t_num **stack_a, char *cmd)
{
	if (cmd)
		ft_free(cmd);
	get_next_line(-1);
	ft_exit_error(*stack_a, NULL);
}
