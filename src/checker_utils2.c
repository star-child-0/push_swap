/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:05:51 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/28 09:15:20 by anvannin         ###   ########.fr       */
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

int	tot_nums_c(char **argv)
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
