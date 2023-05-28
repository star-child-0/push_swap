/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 09:18:41 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/28 10:30:02 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"


static void	exec_move_r(char *mov, t_intl **list_a, t_intl **list_b)
{
	if (!ft_strncmp(mov, "rra", 3))
		do_rrl(list_a);
	else if (!ft_strncmp(mov, "rrb", 3))
		do_rrl(list_b);
	else if (!ft_strncmp(mov, "rrr", 3))
	{
		do_rrl(list_a);
		do_rrl(list_b);
	}
	else if (!ft_strncmp(mov, "ra", 2))
		do_rl(list_a);
	else if (!ft_strncmp(mov, "rb", 2))
		do_rl(list_b);
	else if (!ft_strncmp(mov, "rr", 2))
	{
		do_rl(list_a);
		do_rl(list_b);
	}
	else
	{
		ft_putstr("Error\n");
		get_next_line(GNL_FREE);
		tintl_free_c(list_a);
		exit(0);
	}
}

static void	exec_move(char *mov, t_intl **list_a, t_intl **list_b)
{
	if (!ft_strncmp(mov, "sa", 2))
		do_sl(list_a);
	else if (!ft_strncmp(mov, "sb", 2))
		do_sl(list_b);
	else if (!ft_strncmp(mov, "ss", 2))
	{
		do_sl(list_a);
		do_sl(list_b);
	}
	else if (!ft_strncmp(mov, "pa", 2))
		do_pa(list_b, list_a);
	else if (!ft_strncmp(mov, "pb", 2))
		do_pb(list_a, list_b);
	else
		exec_move_r(mov, list_a, list_b);
}

void	read_moves(t_intl **list_a, t_intl **list_b)
{
	char	*mov;

	while (1)
	{
		mov = get_next_line(0);
		if (!mov)
			break ;
		exec_move(mov, list_a, list_b);
		free(mov);
	}
}
