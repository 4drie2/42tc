/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:22:46 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/18 23:07:18 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char **argv)
{
	int		pipefd[2];
	int		pid;
	char	buff[100];

	if (pipe(pipefd) == -1)
		return(write(2, "erreur 0", 8), 0);
	pid = fork();
	if (pid == -1)
		return(write(2, "erreur 1", 8), 0);
	if (pid == 0)
	{
		close (pipefd[0]);
		if (dup2(pipefd[1], 1) == -1)
			return(write(2, "erreur 2", 8), 0);
		//write(1, "hello", 5);
		char *root ="/bin/ls"; // root
		char *cmd[] = {"ls", "-l", NULL};
		char *envp[] = {NULL};
		if (execve(root, cmd, envp) == -1)
			return(write(2, "erreur 3", 8), 0);
		close(pipefd[1]);
	}
	else
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], 0) == -1)
			return(write(2, "erreur 3", 8), 0);
		read(0, buff, 50);
		printf("nouveau message :%s\n", buff);
		close(pipefd[0]);
	}
	return (0);
}
