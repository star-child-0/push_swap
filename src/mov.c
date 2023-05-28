/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:16:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/28 12:34:23 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ft_mov_b(int len)
{
	int	*mov_b;
	int	i;

	mov_b = (int *)malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
	{
		mov_b[i] = i;
		if (i > len / 2)
			mov_b[i] -= len;
	}
	return (mov_b);
}

static int	smallest_to_top(t_intl **list)
{
	int		i;
	t_intl	*tmp;

	tmp = (*list);
	i = 0;
	while (tmp)
	{
		if (tmp->content == tintl_smallest(list))
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/* int	*ft_mov_a(t_intl **list_a, t_intl **list_b, int len)
{
	int		i;
	int		j;
	int		*mov_a;
	t_intl	*tmp_a;
	t_intl	*tmp_b;

	mov_a = (int *)malloc(sizeof(int) * len);
	if (!mov_a)
		return (0);
	tmp_b = (*list_b);
	i = 0;
	while (tmp_b)
	{
		if (tmp_b->content > tintl_biggest(list_a))
			mov_a[i] = smallest_to_top(list_a);
		else
		{
			j = 1;
			tmp_a = (*list_a);

			while (tmp_a)
			{
				if ((tmp_b->content > tmp_a->content && tmp_a->next
						&& tmp_b->content < tmp_a->next->content))
					break ;
				else
					j++;
				tmp_a = tmp_a->next;
			}
			mov_a[i] = j;

			if (j > len / 2)
				mov_a[i] -= len;
		}

		tmp_b = tmp_b->next;
		i++;
	}

	return (mov_a);
}
 */

static int	ft_mov_a2(t_intl *tmp_a, int num)
{
	t_intl	*tmp_a2;

	tmp_a2 = tmp_a->next;
	while (tmp_a2)
	{
		if (tmp_a2->content < tmp_a->content
			&& tmp_a2->content > num)
			return (1);
		tmp_a2 = tmp_a2->next;
	}
	return (0);
}


int	*ft_mov_a(t_intl **list_a, t_intl **list_b, int len)
{
	int		i;
	int		j;
	int		*mov_a;
	t_intl	*tmp_b;
	t_intl	*tmp_a;

	mov_a = (int *)malloc(sizeof(int) * len);
	tmp_b = (*list_b);
	i = 0;
	while (tmp_b)
	{
		if (tmp_b->content > tintl_biggest(list_a))
			j = smallest_to_top(list_a);
		else
		{
			j = 0;
			tmp_a = (*list_a);
			while (tmp_a)
			{
				if (tmp_b->content < tmp_a->content)
				{
					if (!ft_mov_a2(tmp_a, tmp_b->content))
						break ;
				}
				j ++;
				tmp_a = tmp_a->next;
			}
		}

		if (j > tintl_length(list_a) / 2)
			j -= tintl_length(list_a);

		mov_a[i] = j;
		i++;
		tmp_b = tmp_b->next;
	}
	return (mov_a);
}

int	*find_best_mov(int *mov_a, int *mov_b, int len)
{
	int	*best;
	int	i;

	i = -1;
	best = (int *)malloc(sizeof(int) * len);
	while (++i < len)
	{
		if (mov_a[i] >= 0 && mov_b[i] >= 0
			&& mov_a[i] >= mov_b[i])
			best[i] = mov_a[i];
		else if (mov_a[i] >= 0 && mov_b[i] >= 0
			&& mov_a[i] < mov_b[i])
			best[i] = mov_b[i];
		else if (mov_a[i] < 0 && mov_b[i] < 0
			&& mov_a[i] > mov_b[i])
			best[i] = mov_a[i] * -1;
		else if (mov_a[i] < 0 && mov_b[i] < 0
			&& mov_a[i] < mov_b[i])
			best[i] = mov_b[i] * -1;
		else if (mov_a[i] >= 0 && mov_b[i] < 0)
			best[i] = mov_a[i] + (mov_b[i] * -1);
		else if (mov_a[i] < 0 && mov_b[i] >= 0)
			best[i] = mov_b[i] + (mov_a[i] * -1);
	}
	return (best);
}

int	find_best_pos(int *best, int len)
{
	int	i;
	int	small;
	int	small_i;

	i = 0;
	small = best[i];
	small_i = i;
	while (++i < len)
	{
		if (best[i] < small)
		{
			small = best[i];
			small_i = i;
		}
	}
	free(best);
	return (small_i);
}
