/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:33:38 by vviovi            #+#    #+#             */
/*   Updated: 2023/01/31 13:00:28 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex_start(t_cmd *cmds, int i, int *pipe_fd, char **argv)
{
	open_input(argv, &cmds[i].fd_in);
	cmds[i].fd_out = pipe_fd[1];
	cmds[i].to_close[0] = pipe_fd[0];
}

void	pipex_end_even(t_cmd *cmds, int i, int *pipe_fd2, char **argv)
{
	cmds[i].fd_in = pipe_fd2[0];
	cmds[i].to_close[0] = pipe_fd2[1];
	open_output(argv, i + 4, &cmds[i].fd_out);
}

void	pipex_end_odd(t_cmd *cmds, int i, int *pipe_fd, char **argv)
{
	cmds[i].fd_in = pipe_fd[0];
	cmds[i].to_close[0] = pipe_fd[1];
	open_output(argv, i + 4, &cmds[i].fd_out);
}

void	pipex_even_odd(t_cmd *cmds, int i, int *pipe_fd, int *pipe_fd2)
{
	if (i % 2 == 0)
	{
		cmds[i].fd_in = pipe_fd2[0];
		cmds[i].fd_out = pipe_fd[1];
		cmds[i].to_close[0] = pipe_fd[0];
		cmds[i].to_close[1] = pipe_fd2[1];
	}
	else
	{
		cmds[i].fd_in = pipe_fd[0];
		cmds[i].fd_out = pipe_fd2[1];
		cmds[i].to_close[0] = pipe_fd2[0];
		cmds[i].to_close[1] = pipe_fd[1];
	}
}

int	open_input(char **argv, int *fd1)
{
	int	tmp;

	*fd1 = open(argv[1], O_RDONLY);
	if (*fd1 != -1)
	{
		tmp = open(argv[1], O_DIRECTORY);
		if (tmp != -1)
		{
			close(tmp);
			close(*fd1);
			*fd1 = -1;
		}
	}
	if (*fd1 == -1)
		perror(0);
	return (1);
}
