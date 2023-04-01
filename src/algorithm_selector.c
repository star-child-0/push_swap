/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:55:45 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/01 15:51:29 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algorithm_selector(int argc, t_intl **list_a, t_intl **list_b)
{
	if ((*list_a)->content < (*list_a)->next->content && argc == 2)
		return ;
	if (argc == 2)
		sa(list_a);
	else if (argc == 3)
		size_3_algorithm(list_a);
	else if (argc >= 4 && argc <= 5)
		size_5_algorithm(argc, list_a, list_b);
	else if (argc >= 6)
		size_any_algorithm(list_a, list_b);
}
