/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:43:33 by anvannin          #+#    #+#             */
/*   Updated: 2023/04/01 15:51:29 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_intl	*list_a;
	t_intl	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc == 1)
		return (0);
	if (!argv_check(argc, argv) || !stackify(&list_a, argc, argv))
	{
		ft_putstr("Error\n");
		return (0);
	}
	algorithm_selector(argc - 1, &list_a, &list_b);
	tintl_free(&list_a);
	return (0);
}
