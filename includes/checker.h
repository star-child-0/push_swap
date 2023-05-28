/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:49:53 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/28 10:35:40 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

//	checker
void	read_moves(t_intl **list_a, t_intl **list_b);

//	checker_utils
int		*argv_check_c(int argc, char *argv[], int *nums);
t_intl	*ft_push_c(int content);
int		stackify_c(t_intl **list, int len, int *nums);
void	tintl_free_c(t_intl **list);
int		tot_nums_c(char **argv);

//	checker_utils2
int		tintl_length_c(t_intl **list);
void	list_print_c(t_intl **list);
int		is_tintl_ordered_c(t_intl **list);

//	checker_operations.c
void	do_sl(t_intl **list);
void	do_pa(t_intl **list_b, t_intl **list_a);
void	do_pb(t_intl **list_a, t_intl **list_b);
void	do_rl(t_intl **list);
void	do_rrl(t_intl **list);


#endif
