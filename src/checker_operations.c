/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:04:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/28 10:58:26 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	do_sl(t_intl **list)
{
	int	temp;

	if (!(*list) || !(*list)->next)
		return ;
	if ((*list) && (*list)->next)
	{
		temp = (*list)->content;
		(*list)->content = (*list)->next->content;
		(*list)->next->content = temp;
	}
}

void	do_pa(t_intl **list_b, t_intl **list_a)
{
	t_intl	*tmp;

	if (!(*list_b))
		return ;
	tmp = (*list_b);
	if ((*list_b)->next)
	{
		(*list_b) = (*list_b)->next;
		tmp->next = (*list_a);
		(*list_a) = tmp;
	}
	else
	{
		tmp->next = (*list_a);
		(*list_a) = tmp;
		(*list_b) = NULL;
	}
}

void	do_pb(t_intl **list_a, t_intl **list_b)
{
	t_intl	*tmp;

	if (!(*list_a))
		return ;
	if (list_b != NULL)
	{
		tmp = (*list_a);
		(*list_a) = (*list_a)->next;
		tmp->next = (*list_b);
		(*list_b) = tmp;
	}
	else
	{
		(*list_b) = (*list_a);
		(*list_a) = (*list_a)->next;
		(*list_b)->next = NULL;
	}
}

void	do_rl(t_intl **list)
{
	int		temp;
	t_intl	*anchor;

	if (!(*list) || !(*list)->next)
		return ;
	anchor = (*list);
	while (anchor)
	{
		if (anchor && anchor->next)
		{
			temp = anchor->content;
			anchor->content = anchor->next->content;
			anchor->next->content = temp;
		}
		anchor = anchor->next;
	}
}

void	do_rrl(t_intl **list)
{
	t_intl	*last;
	t_intl	*tmp;

	if (!(*list))
		return ;
	last = (*list);
	tmp = (*list);
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = (*list);
	(*list) = last;
	tmp->next = NULL;
}
