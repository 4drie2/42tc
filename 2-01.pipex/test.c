#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"


//   		UNLINK & ACCESS
// int main(void)
// {
// 	char *root = "/tmp";
// 	printf("access: %d\n", access(root, F_OK));
// 	if (access(root, F_OK) == 0)
// 		printf("unlink: %d", unlink("tmp"));
// 	return (0);
// }


/// 		unlink
/* int main(void)
{
	if (access("/tmp", F_OK) == 0)
		printf("unlink: %d", unlink("tmp"));
	return (0);
} */



// 				PIPE v0
/* #include "pipex.h"

void	luke(int pipefd[], char **argv)
{
	char	**cmd;
	char	*root;
	int		fd;

	close(pipefd[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return ((void)write(2, "erreur 1 - file cannot be read", 30));
	if (dup2(fd, 0) == -1)
		return ((void)write(2, "erreur 2 - file->fd[0]", 22));
	if (dup2(pipefd[1], 1) == -1)
		return ((void)write(2, "erreur 3 - fd[1]->pipe[1]", 25));
	cmd = ft_split(argv[2], ' ');
	root = ft_strjoin("/bin/", cmd[0]);
	if (execve(root, cmd, NULL) == -1)
		return ((void)write(2, "erreur 4 - execve 1 impossibe", 29));
	close(pipefd[1]);
	close(fd);
	return (free(root), free(cmd));
}

void	vador(int pipefd[], char **argv)
{
	char	**cmd;
	char	*root;
	int		fd;

	close(pipefd[1]);
	if (dup2(pipefd[0], 0) == -1)
		return ((void)write(2, "erreur 4", 8));
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ((void)write(2, "erreur 1.2 - file cannot be read", 32));
	if (dup2(fd, 1) == -1)
		return ((void)write(2, "erreur 5", 8));
	cmd = ft_split(argv[3], ' ');
	root = ft_strjoin("/bin/", cmd[0]);
	if (execve(root, cmd, NULL) == -1)
		return ((void)write(2, "erreur 6", 8));
	close(pipefd[0]);
	close(fd);
	return (free(root), free(cmd));
}

int	main(int argc, char **argv)
{
	int	pipefd[2];
	int	pid;

	//if (argc != 5)
	//	return (write(2, "erreur 0", 8), 0);
	if (argc != 5 && (!argv[1] || !argv[2] || !argv[3] || !argv[4]))
		return (write(2, "Invalid arguments\n", 18), 0);
	if (pipe(pipefd) == -1)
		return (write(2, "erreur 0", 8), 0);
	pid = fork();
	if (pid == -1)
		return (write(2, "erreur 1", 8), 0);
	if (pid == 0)
		luke(pipefd, argv);
	else
	{
		vador(pipefd, argv);
		waitpid(pid, NULL, 0);
	}
	return (0);
} */
// 					pipe v0 end


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
			break;
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

int main (int argc, char **argv, char **envp)
{
	char	*path;

	if (argc != 2 || !argv[1] || !envp)
		return (write(2, "Invalid arguments\n", 18), 0);
	path = get_path(argv[1], envp);
	if (!path)
		return (0);
	else
		printf(" bin: %s\npath: %s\n", argv[1], path);
	return (free(path), 0);
}
