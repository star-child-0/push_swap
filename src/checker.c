/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:49:26 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/28 11:01:11 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	ft_free(t_intl **list_a, t_intl **list_b)
{
	get_next_line(GNL_FREE);
	if (*list_a && tintl_length_c(list_a))
		tintl_free_c(list_a);
	if (*list_b && tintl_length_c(list_b))
		tintl_free_c(list_b);
}

int	main(int argc, char *argv[])
{
	t_intl	*list_a;
	t_intl	*list_b;
	int		*nums;

	list_a = NULL;
	list_b = NULL;
	nums = NULL;
	if (argc == 1 && !argv[1])
		return (0);
	nums = argv_check_c(argc, argv, nums);
	if (!nums || !stackify_c(&list_a, tot_nums_c(argv), nums))
	{
		ft_putstr("Error\n");
		return (0);
	}
	read_moves(&list_a, &list_b);
	// list_print_c(&list_a);
	if ((list_b && tintl_length_c(&list_b)) || (!list_a && list_b))
		ft_printf("KO\n");
	else if (is_tintl_ordered_c(&list_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free(&list_a, &list_b);
	return (0);
}
