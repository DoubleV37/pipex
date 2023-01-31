/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:33:38 by vviovi            #+#    #+#             */
/*   Updated: 2023/01/31 16:41:01 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	clean_simple_quote(t_cmd cmd)
{
	int	nb;
	int	i;
	int	j;

	nb = 1;
	while (cmd.cmd && cmd.cmd[0] && cmd.cmd[nb])
	{
		i = 0;
		while (cmd.cmd[nb][i])
		{
			if (cmd.cmd[nb][i] == '\'')
			{
				j = i;
				while (cmd.cmd[nb][j + 1])
				{
					cmd.cmd[nb][j] = cmd.cmd[nb][j + 1];
					j++;
				}
				cmd.cmd[nb][j] = '\0';
			}
			i++;
		}
		nb++;
	}
}
