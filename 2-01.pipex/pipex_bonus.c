/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:20:01 by abidaux           #+#    #+#             */
/*   Updated: 2024/12/06 15:03:38 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return ((void)perror("pipe failed"));
	pid = fork();
	if (pid == -1)
		return ((void)perror("fork failed"));
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	heredoc(char *limiter, int argc)
{
	pid_t	reader;
	int		pipefd[2];
	char	*line;

	if (argc < 6)
		return ((void)perror("heredoc failed"));
	if (pipe(pipefd) == -1)
		return ((void)perror("pipe failed"));
	reader = fork();
	if (reader == 0)
	{
		close(pipefd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(pipefd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(reader, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			heredoc(argv[2], argc);
		}
		else
		{
			i = 2;
			infile = open(argv[1], O_RDONLY);
			outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(infile, STDIN_FILENO);
		}
		while (i < (argc - 2))
			child_process(argv[i++], envp);
		dup2(outfile, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
}
