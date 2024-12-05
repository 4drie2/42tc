/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:20:01 by abidaux           #+#    #+#             */
/*   Updated: 2024/12/05 18:57:05 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc == 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 9) == 0)
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
		while (i < argc - 2)
			child_proccess(argv[i++], envp);
		dup2(outfile, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
}
