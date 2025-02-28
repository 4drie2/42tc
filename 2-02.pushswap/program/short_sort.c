/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:14:26 by abidaux           #+#    #+#             */
/*   Updated: 2025/02/28 13:56:12 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack_node	*find_highest(t_stack_node *stack)
{
	t_stack_node	*highest_node;
	int				highest;

	if (!stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
