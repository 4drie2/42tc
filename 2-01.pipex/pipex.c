/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:09:43 by abidaux           #+#    #+#             */
/*   Updated: 2024/12/04 18:10:52 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*postpath;
	char	*path;
	int		i;

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
	i = -1;
	while (paths[++i])
		free(paths[i]);
	if (!path)
		return (free(paths), perror("cmd not found in PATH"), NULL);
	return (free(paths), path);
}

void	luke(int pipefd[], char **argv, char **envp)
{
	char	**cmd;
	char	*root;
	int		fd;

	close(pipefd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return ((void)perror("erreur 1 - file cannot be read"));
	if (dup2(fd, 0) == -1)
		return ((void)perror("erreur 2 - file->fd[0]"));
	if (dup2(pipefd[1], 1) == -1)
		return ((void)perror("erreur 3 - fd[1]->pipe[1]"));
	cmd = ft_split(argv[2], ' ');
	root = get_path(cmd[0], envp);
	if (execve(root, cmd, envp) == -1)
		return ((void)perror("erreur 4 - execve 1 impossibe"));
	close(pipefd[1]);
	close(fd);
	return (free(root), free(cmd));
}

void	vador(int pipefd[], char **argv, char **envp)
{
	char	**cmd;
	char	*root;
	int		fd;

	close(pipefd[1]);
	if (dup2(pipefd[0], 0) == -1)
		return ((void)perror("erreur 4"));
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ((void)perror("erreur 1.2 - file cannot be read"));
	if (dup2(fd, 1) == -1)
		return ((void)perror("erreur 5"));
	cmd = ft_split(argv[3], ' ');
	root = get_path(cmd[0], envp);
	if (execve(root, cmd, envp) == -1)
		return ((void)perror("erreur 6"));
	close(pipefd[0]);
	close(fd);
	return (free(root), free(cmd));
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	pid;

	if (argc != 5 && (!argv[1] || !argv[2] || !argv[3] || !argv[4] || !envp))
		return (perror("Invalid arguments"), 0);
	if (pipe(pipefd) == -1)
		return (perror("erreur 0"), 0);
	pid = fork();
	if (pid == -1)
		return (perror("erreur 1"), 0);
	if (pid == 0)
		luke(pipefd, argv, envp);
	else
	{
		vador(pipefd, argv, envp);
		waitpid(pid, NULL, 0);
	}
	return (0);
}
