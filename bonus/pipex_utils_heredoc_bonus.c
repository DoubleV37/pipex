/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_heredoc_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:33:38 by vviovi            #+#    #+#             */
/*   Updated: 2023/01/31 14:31:52 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pipex_start_heredoc(t_cmd *cmds, int i, int *pipe_fd, char **argv)
{
	get_heredoc(argv, &cmds[i].fd_in);
	cmds[i].fd_out = pipe_fd[1];
	cmds[i].to_close[0] = pipe_fd[0];
}

void	pipex_end_even_heredoc(t_cmd *cmds, int i, int *pipe_fd2, char **argv)
{
	cmds[i].fd_in = pipe_fd2[0];
	cmds[i].to_close[0] = pipe_fd2[1];
	open_output_heredoc(argv, i + 5, &cmds[i].fd_out);
}

void	pipex_end_odd_heredoc(t_cmd *cmds, int i, int *pipe_fd, char **argv)
{
	cmds[i].fd_in = pipe_fd[0];
	cmds[i].to_close[0] = pipe_fd[1];
	open_output_heredoc(argv, i + 5, &cmds[i].fd_out);
}

int	open_output_heredoc(char **argv, int argc, int *fd2)
{
	*fd2 = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	if (*fd2 == -1 || open(argv[argc - 1], O_DIRECTORY) != -1)
	{
		perror(0);
		return (0);
	}
	return (1);
}

void	clean_simple_quote(t_cmd cmd)
{
	int	nb;
	int	i;
	int	j;

	nb = 1;
	while (cmd.cmd[nb])
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
