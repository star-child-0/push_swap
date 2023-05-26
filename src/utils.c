/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:00:48 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/26 17:55:32 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	num_splitter(char **argv, int **nums, int len, int i)
{
	int		j;
	int		k;
	char	**split;

	k = 0;
	while (i < len && argv[i])
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
			(*nums)[k] = ft_atoi(split[j]);
			k++;
			j++;
		}
		free(split);
		i++;
	}
	return (1);
}

static int	nums_split(char **argv, int **nums)
{
	int		len;

	len = tot_nums(argv);
	if (!len)
		return (0);
	*nums = (int *)malloc(sizeof(int) * len);
	if (!*nums)
		return (0);
	return (num_splitter(argv, nums, len, 1));
}

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

int	*argv_check(int argc, char *argv[], int *nums)
{
	if (argc == 1 || !nums_check(argv) || !signs_check(argv))
		return (NULL);
	if (!nums_split(argv, &nums) || !check_repetition(nums))
	{
		free(nums);
		return (NULL);
	}
	return (nums);
}
