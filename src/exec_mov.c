/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:31:55 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/28 12:34:14 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	mov(t_intl **list_a, t_intl **list_b)
{
	int	*mov_a;
	int	*mov_b;
	int	bp;
	int	len;

	len = tintl_length(list_b);
	while (len--)
	{
		// tintl_print(list_a);
		// tintl_print(list_b);

		mov_a = ft_mov_a(list_a, list_b, tintl_length(list_b));
		mov_b = ft_mov_b(tintl_length(list_b));

		// for (int i = 0; i < tintl_length(list_b); i++)
		// 	ft_printf("mov_a[%d]: %d\tmov_b[%d]: %d\n", i, mov_a[i], i, mov_b[i]);

		int *best_mov = find_best_mov(mov_a, mov_b, tintl_length(list_b));

		// for (int i = 0; i < tintl_length(list_b); i++)
		// 	ft_printf("best_mov[%d]: %d\n", i, best_mov[i]);

		bp = find_best_pos(best_mov, tintl_length(list_b));
		// ft_printf("bp: %d\n", bp);

		if (mov_a[bp] >= 0 && mov_b[bp] >= 0)
			mov_plusplus(list_a, list_b, mov_a[bp], mov_b[bp]);
		else if (mov_a[bp] >= 0 && mov_b[bp] < 0)
			mov_plusminus(list_a, list_b, mov_a[bp], mov_b[bp]);
		else if (mov_a[bp] < 0 && mov_b[bp] >= 0)
			mov_minusplus(list_a, list_b, mov_a[bp], mov_b[bp]);
		else if (mov_a[bp] < 0 && mov_b[bp] < 0)
			mov_minusminus(list_a, list_b, mov_a[bp], mov_b[bp]);
		pa(list_b, list_a);
		free(mov_a);
		free(mov_b);
	}
	// uncomment when list_a is sorted in segments
	mov_reorder(list_a);
}

void	mov_plusplus(t_intl **list_a, t_intl **list_b, int a, int b)
{
	while (a && b)
	{
		rr(list_a, list_b);
		a--;
		b--;
	}
	while (a-- > 0)
		ra(list_a);
	while (b-- > 0)
		rb(list_b);
}

void	mov_minusminus(t_intl **list_a, t_intl **list_b, int a, int b)
{
	while (a && b)
	{
		rrr(list_a, list_b);
		a++;
		b++;
	}
	while (a++ < 0)
		rra(list_a);
	while (b++ < 0)
		rrb(list_b);
}

void	mov_plusminus(t_intl **list_a, t_intl **list_b, int a, int b)
{
	while (a--)
		ra(list_a);
	while (b++ < 0)
		rrb(list_b);
}

void	mov_minusplus(t_intl **list_a, t_intl **list_b, int a, int b)
{
	while (a++ < 0)
		rra(list_a);
	while (b--)
		rb(list_b);
}
