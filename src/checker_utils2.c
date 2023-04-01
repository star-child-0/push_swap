/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:05:51 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/01 16:24:16 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	is_tintl_ordered_c(t_intl **list)
{
	t_intl	*tmp;

	tmp = (*list);
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	tintl_length_c(t_intl **list)
{
	t_intl	*tmp;
	int		n;

	tmp = (*list);
	n = 1;
	while (tmp->next)
	{
		tmp = tmp->next;
		n++;
	}
	return (n);
}

void	list_print_c(t_intl **list)
{
	t_intl	*tmp;

	tmp = (*list);
	while (tmp)
	{
		if (tmp->next)
			ft_printf("%d, ", tmp->content);
		else
			ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}
