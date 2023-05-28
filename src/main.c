/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:43:33 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/28 08:53:06 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_intl	*list_a;
	t_intl	*list_b;
	int		*nums;

	list_a = NULL;
	list_b = NULL;
	nums = NULL;
	if (argc == 1)
		return (0);
	nums = argv_check(argc, argv, nums);
	if (!nums || !stackify(&list_a, nums, tot_nums(argv)))
	{
		ft_putstr("Error\n");
		return (0);
	}
	algorithm_selector(tintl_length(&list_a), &list_a, &list_b);
	tintl_free(&list_a);
	return (0);
}
