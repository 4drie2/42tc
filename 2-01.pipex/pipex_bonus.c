/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:20:01 by abidaux           #+#    #+#             */
/*   Updated: 2024/12/21 10:25:17 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../1-01.get_next_line/get_next_line.h"

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

void execute(char *argv, char **envp)
{
    char    **cmd;
    char    *path;

    cmd = ft_split(argv, ' ');
    path = get_path(cmd[0], envp);
    if (!path)
        return (ft_freestr(cmd), free(path), perror("Command not found"));
    if (execve(path, cmd, envp) == -1)
        return ((void)perror("execve failed"), ft_freestr(cmd), free(path));
    ft_freestr(cmd);
    free(path);
}

void child_process(int in_fd, int out_fd, char *cmd, char **envp)
{
    if (dup2(in_fd, 0) == -1 || dup2(out_fd, 1) == -1)
        return ((void)perror("dup2 error"));
    execute(cmd, envp);
}

void handle_pipes(int argc, char **argv, char **envp, int here_doc)
{
    int pipefd[2];
    int in_fd, out_fd;
    int i = here_doc ? 3 : 2;
    pid_t pid;

    in_fd = here_doc ? open(".here_doc_tmp", O_RDONLY) : open(argv[1], O_RDONLY);
    if (in_fd < 0)
        return (perror("Input file error"));
    while (i < argc - 2)
    {
        if (pipe(pipefd) == -1)
            return (perror("Pipe error"));
        if ((pid = fork()) == -1)
            return (perror("Fork error"));
        if (pid == 0)
        {
            close(pipefd[0]);
            child_process(in_fd, pipefd[1], argv[i], envp);
        }
        close(pipefd[1]);
        close(in_fd);
        in_fd = pipefd[0];
        i++;
    }
    out_fd = open(argv[argc - 1], here_doc ? (O_WRONLY | O_CREAT | O_APPEND) : (O_WRONLY | O_CREAT | O_TRUNC), 0644);
    if (out_fd < 0)
        return (perror("Output file error"));
    if ((pid = fork()) == -1)
        return (perror("Fork error"));
    if (pid == 0)
        child_process(in_fd, out_fd, argv[argc - 2], envp);
    close(in_fd);
    close(out_fd);
    while (wait(NULL) > 0);
}

void here_doc_mode(char *limiter)
{
    int     fd;
    char    *line;

    fd = open(".here_doc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return (perror("Here_doc temp file error"));
    while (1)
    {
        write(1, "heredoc> ", 9);
        line = get_next_line(0);
        if (!line || ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
        {
            free(line);
            break;
        }
        write(fd, line, ft_strlen(line));
        write(fd, "\n", 1);
        free(line);
    }
    close(fd);
}

int main(int argc, char **argv, char **envp)
{
    if (argc < 5)
        return (perror("Invalid arguments"), 1);
    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
    {
        if (argc < 6)
            return (perror("Invalid here_doc arguments"), 1);
        here_doc_mode(argv[2]);
        handle_pipes(argc, argv, envp, 1);
        unlink(".here_doc_tmp");
    }
    else
        handle_pipes(argc, argv, envp, 0);
    return (0);
}
