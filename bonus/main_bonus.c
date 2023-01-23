/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:42:32 by vviovi            #+#    #+#             */
/*   Updated: 2023/01/23 15:11:33 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	dupclose_fd(t_cmd *cmds, int index_cmd)
{
	if (cmds[index_cmd].fd_in > 2)
	{
		dup2(cmds[index_cmd].fd_in, 0);
		close(cmds[index_cmd].fd_in);
	}
	if (cmds[index_cmd].fd_out > 2)
	{
		dup2(cmds[index_cmd].fd_out, 1);
		close(cmds[index_cmd].fd_out);
	}
	if (cmds[index_cmd].to_close[0] > 2)
		close(cmds[index_cmd].to_close[0]);
	if (cmds[index_cmd].to_close[1] > 2)
		close(cmds[index_cmd].to_close[1]);
}

pid_t	exe_cmd(t_cmd *cmds, int index_cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dupclose_fd(cmds, index_cmd);
		if (cmds[index_cmd].pid != -42 && cmds[index_cmd].fd_in != -1
			&& cmds[index_cmd].fd_out != -1)
		{
			execve(cmds[index_cmd].cmd[0], cmds[index_cmd].cmd, env);
			perror(0);
		}
		else
			display_error_cmd(cmds, index_cmd);
		clean_cmds(&cmds);
		exit(1);
	}
	if (cmds[index_cmd].cmd && cmds[index_cmd].fd_in > 2)
		close(cmds[index_cmd].fd_in);
	if (cmds[index_cmd].cmd && cmds[index_cmd].fd_out > 2)
		close(cmds[index_cmd].fd_out);
	return (pid);
}

void	wait_child(t_cmd *cmds)
{
	int	i;

	i = 0;
	while (cmds[i].cmd)
	{
		if (cmds[i].pid != -42)
			waitpid(cmds[i].pid, NULL, 0);
		i++;
	}
}

void	pipex(t_cmd *cmds, int argc, int *fd, char **env)
{
	int	i;
	int	pipe_fd[2];
	int	pipe_fd2[2];

	i = 0;
	while (cmds[i].cmd)
	{
		if (i % 2 == 0)
			pipe(pipe_fd);
		else if (argc > 5 && i % 2 != 0)
			pipe(pipe_fd2);
		if (i == 0)
			pipex_start(cmds, i, pipe_fd, fd);
		else if (i == argc - 4 && i % 2 != 0)
			pipex_end_odd(cmds, i, pipe_fd, fd);
		else if (i == argc - 4 && i % 2 == 0)
			pipex_end_even(cmds, i, pipe_fd2, fd);
		else
			pipex_even_odd(cmds, i, pipe_fd, pipe_fd2);
		cmds[i].pid = exe_cmd(cmds, i, env);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	t_cmd	*cmds;

	if (argc < 5)
	{
		write(2, "Number of arguments incorrect !\n", 33);
		return (1);
	}
	cmds = is_valid_cmd(argc, argv, env);
	if (!cmds || !is_valid_files(argv, argc, &fd[0], &fd[1]))
	{
		clean_cmds(&cmds);
		return (1);
	}
	pipex(cmds, argc, fd, env);
	wait_child(cmds);
	if (fd[0] > 2)
		close(fd[0]);
	if (fd[1] > 2)
		close(fd[1]);
	clean_cmds(&cmds);
	return (0);
}
