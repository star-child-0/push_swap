/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:01:50 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 14:56:20 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	size_3_algorithm(t_intl **list)
{
	if ((*list)->content > (*list)->next->content
		&& (*list)->next->content < (*list)->next->next->content
		&& (*list)->content < (*list)->next->next->content)
		sa(list);
	else if ((*list)->content > (*list)->next->content
		&& (*list)->next->content > (*list)->next->next->content
		&& (*list)->content > (*list)->next->next->content)
	{
		sa(list);
		rra(list);
	}
	else if ((*list)->content > (*list)->next->content
		&& (*list)->next->content < (*list)->next->next->content
		&& (*list)->content > (*list)->next->next->content)
		ra(list);
	else if ((*list)->content < (*list)->next->content
		&& (*list)->next->content > (*list)->next->next->content
		&& (*list)->content < (*list)->next->next->content)
	{
		sa(list);
		ra(list);
	}
	else
		rra(list);
}

void	size_5_algorithm(int argc, t_intl **list_a, t_intl **list_b)
{
	while (tintl_length(list_a) > 3)
	{
		if ((*list_a)->content == tintl_smallest(list_a)
			|| (*list_a)->content == tintl_biggest(list_a))
			pb(list_a, list_b);
		else
			ra(list_a);
	}
	if (!is_tintl_ordered(list_a))
		size_3_algorithm(list_a);
	if ((*list_b)->next && (*list_b)->content < (*list_b)->next->content)
		sb(list_b);
	pa(list_b, list_a);
	if (argc == 4)
	{
		if (tintl_biggest(list_a) == (*list_a)->content)
			ra(list_a);
		return ;
	}
	size_5_algorithm2(list_a, list_b);
}

void	size_5_algorithm2(t_intl **list_a, t_intl **list_b)
{
	if ((*list_a)->content == tintl_biggest(list_a))
	{
		if (tintl_smallest(list_a) > (*list_b)->content)
		{
			ra(list_a);
			pa(list_b, list_a);
		}
		else
		{
			pa(list_b, list_a);
			ra(list_a);
			ra(list_a);
		}
	}
	else if ((*list_b)->content < tintl_smallest(list_a))
		pa(list_b, list_a);
}

void	size_any_algorithm(t_intl **list_a, t_intl **list_b)
{
	lis_algorithm(list_a, list_b);
	mov(list_a, list_b);
}
