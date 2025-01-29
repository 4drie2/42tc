/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:01:00 by abidaux           #+#    #+#             */
/*   Updated: 2025/01/23 12:08:33 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cellule
{
	int				a;
	struct cellule	*prev;
	struct cellule	*next;
}	t_lsc;

void	new_end(t_lsc **head, int value)
{
	t_lsc	*new;
	t_lsc	*temp;

	new = malloc(sizeof(t_lsc));
	if (!new)
		return (perror("malloc "));
	new->a = value;
	new->prev = NULL;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
 }

void	print_list(t_lsc *head)
{
	t_lsc	*temp;

	temp = head;
	while (temp)
	{
		printf("%d\n", temp->a);
		temp = temp->next;
	}
}

void	free_list(t_lsc *head)
{
	t_lsc	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	main(void)
{
	int		i;
	t_lsc	*tabc;

	tabc = malloc(sizeof(t_lsc));
	i = 4;
	tabc->a = i++;
	while (i <= 10)
		new_end(&tabc, i++);
	print_list(tabc);
	free_list(tabc);
}
