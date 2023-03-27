/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:53:41 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/16 18:58:53 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bin_mag(int n)
{
	int	m;

	m = 1;
	while (n > 1)
	{
		n /= 2;
		m++;
	}
	return (m);
}

int	*order_arr(int *arr, int len)
{
	int	i;
	int	j;
	int	t;

	i = -1;
	while (++i < len - 1)
	{
		j = -1;
		while (++j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	return (arr);
}
