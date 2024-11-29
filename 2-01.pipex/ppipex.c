/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppipex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:29:13 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/27 20:33:30 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include "libft/libft.h"

typedef struct s_cmd
{
	char			*cmd;
	int				f_in;
	int				f_out;
	int				*tab_pipe;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	char	**av;
	char	**env;
	char	**path;
	char	**cmd_opt;
	int		len_args;
	int		hrdoc_f;
	char	*hrdoc;
	int		proc;
	int		fd[2];
	int		f_in;
	int		f_out;
	t_cmd	*cmd;
}	t_data;

typedef struct grab_line
{
	char		*ptr;
	char		*tmp;
	char		*buff;
	char		*line;
}	t_gnl;

/******* Function mandatory **********/
void	processes_making(t_data *data);
void	execute(char *cmd, t_data *data);

/******* Function bonus **********/
void	error(char *msg);
void	add_cmd(t_data *data);
void	pipeline(t_data *data);
void	run_heredoc(t_data *data);
char	*grab_line(int fd);

#endif

static void	get_path(t_data *data, char **env)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 5;
	while (env[i] && ft_strncmp(env[i], "PATH=", j))
		i++;
	if (!env[i])
		exit(2);
	ptr = ft_calloc(ft_strlen(&env[i][j]) + 1, sizeof(char));
	ft_strlcpy(ptr, &env[i][j], ft_strlen(&env[i][j]) + 1);
	data->path = ft_split(ptr, ':');
}

void	execute(char *cmd, t_data *data)
{
	int		i;
	char	*pth_cmd;
	char	*hold;

	i = 0;
	get_path(data, data->env);
	data->cmd_opt = ft_split(cmd, ' ');
	while (data->path[i])
	{
		hold = ft_strjoin("/", data->cmd_opt[0]);
		pth_cmd = ft_strjoin(data->path[i], hold);
		if (!access(pth_cmd, F_OK))
		{
			if (!access(pth_cmd, X_OK))
				execve(pth_cmd, data->cmd_opt, data->env);
			else
				perror("Permission denied :/\n");
		}
		free(hold);
		free(pth_cmd);
		i++;
	}
	perror("Invalid command! :/\n");
	exit(1);
}

void	processes_making(t_data *data)
{
	if (pipe(data->fd) < 0)
		exit (2);
	data->proc = fork();
	if (data->proc < 0)
	{
		perror("fork fails :(\n");
		exit(2);
	}
	if (data->proc == 0)
	{
		close(data->fd[0]);
		dup2(data->f_in, STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
		execute(data->av[1], data);
	}
	if (data->proc > 0)
	{
		close(data->fd[1]);
		dup2(data->fd[0], STDIN_FILENO);
		dup2(data->f_out, STDOUT_FILENO);
		execute(data->av[2], data);
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac == 5)
	{
		data.f_in = open(av[1], O_RDONLY);
		if (data.f_in < 0)
			perror("file in fails to read :(\n");
		data.f_out = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0664);
		if (data.f_out < 0)
			perror("file out fails to create :(\n");
		data.av = &av[1];
		data.env = env;
		processes_making(&data);
	}
	else
		perror("Check your argument!\n");
}
