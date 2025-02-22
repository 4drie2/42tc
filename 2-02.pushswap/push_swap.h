/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:28:59 by abidaux           #+#    #+#             */
/*   Updated: 2025/02/22 16:28:47 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack_node
{
	int						nbr;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct	s_stack_node	*target_node;
	struct	s_stack_node	*next;
	struct	s_stack_node	*prev;
}	t_stack_node;

// Handle errors

// Stack initialisation

// Nodes initialisation

// Stacks utils

// Commands

// Algorithms

#endif
