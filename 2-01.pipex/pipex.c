/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:22:46 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/19 21:36:21 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void	luke(int pipefd[], char **argv)
{
	close(pipefd[0]);
	if (dup2(pipefd[1], 1) == -1)
		return((void)write(2, "erreur 2", 8));
	int fd = open(argv[1], O_RDONLY);
	if (dup2(fd, 0) == -1)
		return((void)write(2, "erreur 3", 8));
	char **cmd = ft_split(argv[2], ' ');
	char *root = ft_strjoin("/bin/", cmd[0]);
	char *envp[] = {NULL};
	if (execve(root, cmd, envp) == -1)
		return((void)write(2, "erreur 4", 8));
	close(pipefd[1]);
}

void	vador(int pipefd[], char **argv)
{
	close(pipefd[1]);
	if (dup2(pipefd[0], 0) == -1)
		return((void)write(2, "erreur 4", 8));
	int fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (dup2(fd, 1) == -1)
		return((void)write(2, "erreur 5", 8));
	char **cmd = ft_split(argv[3], ' ');
	char *root = ft_strjoin("/bin/", cmd[0]);
	char *envp[] = {NULL};
	if (execve(root, cmd, envp) == -1)
		return((void)write(2, "erreur 6", 8));
	close(pipefd[0]);
}

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
		luke(pipefd, argv);
	}
	else
	{
		vador(pipefd, argv);
		waitpid(pid, NULL, 0);
	}
	return (0);
}


