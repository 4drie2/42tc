#include "pipex.h"

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*postpath;
	char	*path;
	int		i;

	i = -1;
	while (*envp && ft_strncmp(*envp, "PATH=", 5))
	{
		printf("Boucle\n");
		++envp;
	}
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

int main(int argc, char **argv, char **envp){
	printf("%s\n", get_path("ls", envp));
	printf("---------");
	printf("%s\n", get_path("ls", envp));
}
