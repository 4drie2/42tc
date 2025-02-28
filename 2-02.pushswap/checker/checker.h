/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:49:24 by abidaux           #+#    #+#             */
/*   Updated: 2025/02/28 13:55:34 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 4
# include <fcntl.h>
# include "../program/push_swap.h"

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}	t_list;

size_t	gnl_strlen(char *str);
char	*gnl_strjoin(char *stash, char *buff);
char	*get_next_line(int fd);
char	*gnl_strchr(const char *string, int searchedChar);

#endif
