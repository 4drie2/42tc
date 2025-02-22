/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:28:07 by abidaux           #+#    #+#             */
/*   Updated: 2025/02/22 18:37:19 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **head)
{
	t_stack_node	*temp_head;
	t_stack_node	*temp_3;

	if (!head || !*head || !((*head)->next))
		return ;
	temp_head = *head;
	temp_3 = (*head)->next->next;
	(*head) = (*head)->next;
	(*head)->next = temp_head;
	(*head)->next->next = temp_3;
}

int	stack_len(t_stack_node **head)
{
	t_stack_node	*temp;
	int				count;

	temp = *head;
	count = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

bool	stack_sorted(t_stack_node **head)
{
	t_stack_node	*temp;

	temp = head;
	while (temp)
	{
		if (!temp->next)
			return (true);
		if (temp->nbr > temp->next->nbr)
			return (false);
		temp = temp->next;
	}
	return (true);
}

int main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ps_split(av[1], ' ');
	init_stack_a(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
