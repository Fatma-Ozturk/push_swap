/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@42kocaeli.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:10:16 by faozturk          #+#    #+#             */
/*   Updated: 2022/06/21 11:37:55 by faozturk         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*tmp;
	t_list	*min;
	int		flag;

	tmp = *stack;
	flag = 0;
	min = NULL;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if ((tmp->index == -1) && (!flag || tmp->content < min->content))
		{
			flag = 1;
			min = tmp;
		}
		tmp = tmp->next;
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = get_next_min(stack);
	while (tmp)
	{
		tmp->index = i++;
		tmp = get_next_min(stack);
	}
}
