/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:01:00 by abidaux           #+#    #+#             */
/*   Updated: 2025/01/11 16:20:59 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	new_end(t_lsc **head, int value)
{
	t_lsc	*new;
	t_lsc	*temp;

	new = malloc(sizeof(t_lsc));
	if (!new)
		return (perror("malloc "));
	new->a = value;
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
