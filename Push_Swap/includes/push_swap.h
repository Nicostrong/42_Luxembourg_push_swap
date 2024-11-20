/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:39:41 by nfordoxc          #+#    #+#             */
/*   Updated: 2024/11/20 08:41:55 by nfordoxc         ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
 *	Standard library
 */

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*
 *	Personal library
 */
 
# include "../library/ft_printf/ft_printf.h"
# include "../library/libft/libft.h"

/*
 * 	linked list
 */

typedef struct s_lst_num
{
	struct s_lst_num	*before;
	struct s_lst_num	*next;
	int					value;
	int					index;
	int					target;
	int					cost;
	int					reverse;
}	t_num;

typedef struct s_lst_info
{
	int					val_min;
	int					val_max;
	int					nb_val_a;
	int					nb_val_b;
}	t_info;

/*
 * ft_lst_print.c
 */

void	lst_print(t_num *lst, char c);
void	lst_print_all(t_num *lst, char c);

/*
 * ft_lst.c
 */

t_num	*node_new(int content, int index);
t_num	*add_back(t_num *lst, t_num *new);
t_num	*add_front(t_num *lst, t_num *new);
t_num	*node_remove(t_num *node_to_remove);
t_num	*node_move(t_num *node_to_move, t_num *dest);

/*
 *	ft_del.c
 */

void	lst_del(t_num *lst);
void	lst_del_all(t_num *lst);

/*
 *	ft_parse_args.c
 */

t_num	*ft_arg_to_array(char *args);
t_num	*ft_parse_arg(int nb_arg, char **args);
t_num	*ft_args_to_list(int count, char **array, int isalloc);

/*
 *	ft_check_args.c
 */

int		check_args(int argc, char **argv);
int		ft_isuniq(long long nb, char **array);
int		ft_uniq_int(int nb_argc, char **array);
int		ft_only_digit(int nb_argc, char **array);

/*
 *	ft_info.c
 */

void	info_print(t_info *info);

t_info	*ft_init_info(void);
t_info	*ft_get_info(t_num *lst);

/*
 *	moves
 */

	/*
	 *	ft_pusch.c
	 */

void	ft_push(t_num **dest, t_num **src);
void	ft_pa(t_num **dest, t_num **src, t_info *info);
void	ft_pb(t_num **dest, t_num **src, t_info *info);

	/*
	 *	ft_swap.c
	 */

void	ft_swap(t_num **stack);
void	ft_sa(t_num **stack_a);
void	ft_sb(t_num **stack_b);
void	ft_ss(t_num **stack_a, t_num **stack_b);

	/*
	 *	ft_rotate.c
	 */

void	ft_rotate(t_num **stack);
void	ft_ra(t_num **stack_a);
void	ft_rb(t_num **stack_b);
void	ft_rr(t_num **stack_a, t_num **stack_b);

	/*
	 *	ft_reverse_rotate.c
	 */

void	ft_reverse_rotate(t_num **stack);
void	ft_rra(t_num **stack_a);
void	ft_rrb(t_num **stack_b);
void	ft_rrr(t_num **stack_a, t_num **stack_b);

/*
 *	ft_little_sort.c
 */

int		ft_min(t_num *stack);

void	ft_sort_three(t_num **stack);
void	ft_sort_four(t_num **stack, t_info *info);
void	ft_sort_five(t_num **stack_a, t_num **stack_b, t_info *info);
void	ft_put_min_in_b(t_num **stack_a, t_num **stack_b, t_info *info);

/*
 *	ft_set_info_lst.c
 */

void	ft_set_index(t_num **lst_a, t_num **lst_b);
void	ft_set_reverse(t_num **lst_a, int valina, t_num **lst_b, int valinb);
void	ft_set_target(t_num **lst_node, t_num **lst_target);
void	ft_set_cost(t_num **src, t_num **dest, t_info *info);
void	ft_set_all_info(t_num **lst_a, t_num **lst_b, t_info *info);

/*
 *	ft_set_rev_info_lst.c
 */

void	ft_set_target_rev(t_num **lst_node, t_num **lst_target);
void	ft_set_cost_rev(t_num **src, t_num **dest, t_info *info);
void	ft_set_all_rev_info(t_num **lst_a, t_num **lst_b, t_info *info);
/*
 *	ft_sort_utils.c
 */

int		ft_issort_asc(t_num *stack);
int		ft_issort_dec(t_num *stack);

void	ft_fusion(t_num **stack_a, t_num **stack_b, t_info *info);
void	ft_choose_sort(t_num **stack_a, t_info *info);
void	ft_split_list(t_num **stack_a, t_num **stack_b, t_info *info);

/*
 *	ft_sort.c
 */

int		ft_min_cost(t_num *lst);

void	ft_sort(t_num **stack_a, t_num **stack_b, t_info *info);

t_num	*ft_get_node(t_num *lst, int min_cost);
t_num	*ft_get_target(t_num *lst, int target);

/*
 *	ft_put_head.c
 */

void	ft_put_in_head(t_num **src, t_num **dest, t_info *info);
void	ft_put_in_head_rev(t_num **src, t_num **dest, t_info *info);
void	ft_make_move(t_num *node, t_num *target, t_num **src, t_num **dest);
void	ft_make_move_rev(t_num *node, t_num *target, t_num **src, t_num **dest);

/*
 *	ft_exit_error.c
 */

void	ft_exit_error(t_num *stack_a, t_info *info);

#endif
