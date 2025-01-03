/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:01:00 by abidaux           #+#    #+#             */
/*   Updated: 2025/01/03 20:55:28 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cellule
{
	int		a;
	struct	cellule *suiv;
};

int main(int argc, char **argv)
{
	struct cellule *p, *q, *tete=NULL;
	int i;

	i = 0;
	while (++i < argc)
	{
		p = (struct cellule *)malloc(sizeof(struct cellule));
		p->a = atoi(argv[i]);
		p->suiv = NULL;
		if (tete == NULL)
			tete = p;
		else
			q->suiv = p;
		q = p;
	}
	printf("Elements de la liste : ");
	q = tete;
	while (q != NULL)
	{
		printf("%d ", q->a);
		q = q->suiv;
	}
	printf("\n");
	return (0);
}
