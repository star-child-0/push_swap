/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 09:15:28 by anvannin          #+#    #+#             */
/*   Updated: 2023/05/28 09:33:19 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_intl	*ft_push_c(int content)
{
	t_intl	*new;

	new = (t_intl *)malloc(sizeof(t_intl));
	new->content = content;
	new->next = NULL;
	return (new);
}

int	stackify_c(t_intl **list, int len, int *nums)
{
	int		i;
	t_intl	*node;

	node = (t_intl *) malloc(sizeof(t_intl));
	node->content = nums[0];
	node->next = NULL;
	(*list) = node;
	if (!list)
		return (0);
	i = 0;
	while (++i < len)
	{
		(*list)->next = ft_push_c(nums[i]);
		(*list) = (*list)->next;
	}
	(*list) = node;
	free(nums);
	return (1);
}

void	tintl_free_c(t_intl **list)
{
	t_intl	*tmp;

	while ((*list) != NULL)
	{
		tmp = (*list);
		(*list) = (*list)->next;
		free(tmp);
	}
}
