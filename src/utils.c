/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:00:48 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/28 09:36:09 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	nums_check(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if (!(ft_isdigit(av[i][j]) || av[i][j] == ' ' || av[i][j] == '+'
				||av[i][j] == '-'))
				return (0);
	}
	return (1);
}

static int	signs_check(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if ((av[i][j] == '+' || av[i][j] == '-')
				&& !ft_isdigit(av[i][j + 1]))
				return (0);
	}
	return (1);
}

static int	num_splitter(char **argv, int *nums, int len, int i)
{
	int		j;
	int		k;
	char	**split;

	k = 0;
	while (i < len + 1 && argv[i])
	{
		j = -1;
		split = ft_split(argv[i], ' ');
		while (split[++j])
		{
			if (ft_atol(split[j]) < INT_MIN || ft_atol(split[j]) > INT_MAX)
			{
				free(split);
				return (0);
			}
			nums[k] = ft_atoi(split[j]);
			k++;
		}
		free_matrix((void **)split);
		i++;
	}
	return (1);
}

static int	check_repetition(int *nums, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
			if (nums[i] == nums[j])
				return (0);
	}
	return (1);
}

int	*argv_check(int argc, char *argv[], int *nums)
{
	int	len;

	if (argc == 1 || !nums_check(argv) || !signs_check(argv))
		return (NULL);
	len = tot_nums(argv);
	if (!len)
		return (NULL);
	nums = (int *)malloc(sizeof(int) * len);
	if (!nums)
		return (0);
	if (!num_splitter(argv, nums, len, 1) || !check_repetition(nums, len))
	{
		free(nums);
		return (NULL);
	}
	return (nums);
}
