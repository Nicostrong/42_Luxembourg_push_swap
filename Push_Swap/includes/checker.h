/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 08:38:49 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 08:45:21 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
 *	Personal library
 */

# include "./push_swap.h"
# include "../library/gnl/get_next_line.h"

/*
 *	checker_utils.c
 */

void	ft_error(t_num **stack_a, char *cmd);
void	ft_execute_cmd(t_num **stack_a, t_num **stack_b);
void	ft_litle_cmd(char *cmd, t_num **stack_a, t_num **stack_b);
void	ft_big_cmd(char *cmd, t_num **stack_a, t_num **stack_b);

#endif
