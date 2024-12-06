/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:09:43 by abidaux           #+#    #+#             */
/*   Updated: 2024/12/06 17:38:08 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*postpath;
	char	*path;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = -1;
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
		++envp;
	paths = ft_split(*envp + 5, ':');
	postpath = ft_strjoin("/", cmd);
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], postpath);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
	}
	free(postpath);
	ft_freestr(paths);
	if (!path)
		return (perror("cmd not found in PATH"), NULL);
	return (path);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = get_path(cmd[0], envp);
	if (!path)
		return (ft_freestr(cmd), free(path), perror("path not found"));
	if (execve(path, cmd, envp) == -1)
		return ((void)perror("execve 1 failed"));
	return (ft_freestr(cmd), free(path));
}

void	child_process(int *pipefd, char **argv, char **envp)
{
	int		fd;

	close(pipefd[0]);
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		return ((void)perror("file1 cannot be read"));
	if (dup2(fd, 0) == -1)
		return ((void)perror("error dup2 file->fd[0]"));
	if (dup2(pipefd[1], 1) == -1)
		return ((void)perror("error dup2 fd[1]->pipe[1]"));
	execute(argv[2], envp);
	close(pipefd[1]);
	close(fd);
}

void	parent_process(int *pipefd, char **argv, char **envp)
{
	int		fd;

	close(pipefd[1]);
	if (dup2(pipefd[0], 0) == -1)
		return ((void)perror("erreur 4"));
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return ((void)perror("erreur 1.2 - file cannot be read"));
	if (dup2(fd, 1) == -1)
		return ((void)perror("erreur 5"));
	execute(argv[3], envp);
	close(pipefd[0]);
	close(fd);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	pid;

	if (argc != 5 || (!argv[1] || !argv[2] || !argv[3] || !argv[4] || !envp))
		return (perror("Bad argmt\nEx: ./pipex <in> <cmd1> <cmd2> <out>"), 0);
	if (pipe(pipefd) == -1)
		return (perror("erreur 0"), 0);
	pid = fork();
	if (pid == -1)
		return (perror("erreur 1"), 0);
	if (pid == 0)
		child_process(pipefd, argv, envp);
	else
	{
		waitpid(pid, NULL, 0);
		parent_process(pipefd, argv, envp);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}
