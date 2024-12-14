/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:01:00 by abidaux           #+#    #+#             */
/*   Updated: 2024/12/12 15:52:13 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PeopleList {
	char *name;
	int age;
	struct PeopleList *next;
};

int main(void){
	struct PeopleList *MyList;

	MyList = malloc(sizeof(struct PeopleList));
	if (!MyList)
		return (perror("malloc MyList"), 0);
	return (0);
}
