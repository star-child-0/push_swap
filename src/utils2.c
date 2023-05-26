/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:53:41 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 18:00:17 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	tot_nums(char **argv)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (ft_isdigit(argv[i][j]) || argv[i][j] == ' ' || argv[i][j] == '-'
				|| argv[i][j] == '+')
			{
				while (argv[i][j] == ' ' || argv[i][j] == '-'
					|| argv[i][j] == '+' || ft_isdigit(argv[i][j + 1]))
					j++;
				if (argv[i][j] == '\0')
					break ;
				if (ft_isdigit(argv[i][j]))
					len++;
			}
		}
	}
	return (len);
}

int	check_repetition(int *nums)
{
	int	i;
	int	j;

	i = 0;
	while (++i && nums[i])
	{
		j = i;
		while (++j && nums[j])
			if (nums[i] == nums[j])
				return (0);
	}
	return (1);
}

int	stackify(t_intl **list, int *nums)
{
	int		i;
	t_intl	*node;

	for (int j = 0; nums[j]; j++)
		ft_printf("%d,", j, nums[j]);
	ft_printf("\n");

	node = (t_intl *) malloc(sizeof(t_intl));
	if (!node)
		return (0);
	node->content = nums[0];
	node->next = NULL;
	(*list) = node;
	if (!list)
		return (0);
	i = 0;
	while (nums[++i])
	{
		(*list)->next = tintl_push(nums[i]);
		(*list) = (*list)->next;
	}
	(*list) = node;
	return (1);
}
