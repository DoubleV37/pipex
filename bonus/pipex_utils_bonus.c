/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:33:38 by vviovi            #+#    #+#             */
/*   Updated: 2023/01/23 15:11:54 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex_start(t_cmd *cmds, int i, int *pipe_fd, int *fd)
{
	cmds[i].fd_in = fd[0];
	cmds[i].fd_out = pipe_fd[1];
	cmds[i].to_close[0] = pipe_fd[0];
	cmds[i].to_close[1] = fd[1];
}

void	pipex_end_even(t_cmd *cmds, int i, int *pipe_fd2, int *fd)
{
	cmds[i].fd_in = pipe_fd2[0];
	cmds[i].to_close[0] = pipe_fd2[1];
	cmds[i].fd_out = fd[1];
	cmds[i].to_close[1] = fd[0];
}

void	pipex_end_odd(t_cmd *cmds, int i, int *pipe_fd, int *fd)
{
	cmds[i].fd_in = pipe_fd[0];
	cmds[i].to_close[0] = pipe_fd[1];
	cmds[i].fd_out = fd[1];
	cmds[i].to_close[1] = fd[0];
}

void	pipex_even_odd(t_cmd *cmds, int i, int *pipe_fd, int *pipe_fd2)
{
	if (i % 2 == 0)
	{
		cmds[i].fd_in = pipe_fd2[0];
		cmds[i].fd_out = pipe_fd[1];
		cmds[i].to_close[0] = pipe_fd[0];
	}
	else
	{
		cmds[i].fd_in = pipe_fd[0];
		cmds[i].fd_out = pipe_fd2[1];
		cmds[i].to_close[0] = pipe_fd2[0];
	}
}
