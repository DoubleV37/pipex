/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:42:32 by vviovi            #+#    #+#             */
/*   Updated: 2023/01/31 09:27:02 by vviovi           ###   ########.fr       */
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

void	pipex(t_cmd *cmds, int argc, char **env, char **argv)
{
	int	i;
	int	pipe_fd[2];
	int	pipe_fd2[2];

	i = 0;
	while (cmds[i].cmd)
	{
		if (i % 2 == 0 && i != argc - 4)
			pipe(pipe_fd);
		else if (argc > 5 && i % 2 != 0 && i != argc - 4)
			pipe(pipe_fd2);
		if (i == 0)
			pipex_start(cmds, i, pipe_fd, argv);
		else if (i == argc - 4 && i % 2 != 0)
			pipex_end_odd(cmds, i, pipe_fd, argv);
		else if (i == argc - 4 && i % 2 == 0)
			pipex_end_even(cmds, i, pipe_fd2, argv);
		else
			pipex_even_odd(cmds, i, pipe_fd, pipe_fd2);
		cmds[i].pid = exe_cmd(cmds, i, env);
		i++;
	}
	closefd(pipe_fd);
}

int	main(int argc, char **argv, char **env)
{
	int		is_heredoc;
	t_cmd	*cmds;

	is_heredoc = ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc"));
	if (argc < 5 || (!is_heredoc && argc < 6))
	{
		write(2, "Number of arguments incorrect !\n", 33);
		return (1);
	}
	if (!is_heredoc && ft_strlen(argv[1]) == ft_strlen("here_doc"))
		return (do_heredoc(argc, argv, env));
	cmds = is_valid_cmd(argc, argv, env, 2);
	if (!cmds)
	{
		clean_cmds(&cmds);
		return (1);
	}
	pipex(cmds, argc, env, argv);
	wait_child(cmds);
	clean_cmds(&cmds);
	return (0);
}
