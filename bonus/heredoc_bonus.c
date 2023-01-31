/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:30:07 by vviovi            #+#    #+#             */
/*   Updated: 2023/01/31 10:46:17 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_line(int fd)
{
	char	*buffer;
	char	*res_str;
	int		nbread;

	buffer = ft_calloc(sizeof(char), 2);
	res_str = ft_calloc(sizeof(char), 1);
	nbread = 1;
	while (buffer[0] != '\n' && nbread > 0)
	{
		nbread = read(fd, buffer, 1);
		res_str = ft_strjoin_free_first_param(res_str, buffer);
	}
	free(buffer);
	return (res_str);
}

void	init_pipe(int *pipe_fd, int *pipe_fd2)
{
	pipe_fd[0] = -1;
	pipe_fd[1] = -1;
	pipe_fd2[0] = -1;
	pipe_fd2[1] = -1;
}

void	pipexheredoc(t_cmd *cmds, int argc, char **env, char **argv)
{
	int	i;
	int	pipe_fd[2];
	int	pipe_fd2[2];

	i = 0;
	init_pipe(pipe_fd, pipe_fd2);
	while (cmds[i].cmd)
	{
		if (i % 2 == 0 && i != argc - 5)
			pipe(pipe_fd);
		else if (argc > 6 && i % 2 != 0 && i != argc - 5)
			pipe(pipe_fd2);
		if (i == 0)
			pipex_start_heredoc(cmds, i, pipe_fd, argv);
		else if (i == argc - 5 && i % 2 != 0)
			pipex_end_odd_heredoc(cmds, i, pipe_fd, argv);
		else if (i == argc - 5 && i % 2 == 0)
			pipex_end_even_heredoc(cmds, i, pipe_fd2, argv);
		else
			pipex_even_odd(cmds, i, pipe_fd, pipe_fd2);
		cmds[i].pid = exe_cmd(cmds, i, env);
		i++;
	}
	closefd(pipe_fd);
	closefd(pipe_fd2);
}

int	get_heredoc(char **argv, int *fd)
{
	int		pipe_fd[2];
	char	*buffer;
	char	*strgnl;

	pipe(pipe_fd);
	buffer = ft_calloc(sizeof(char), 1);
	if (!buffer)
		return (0);
	strgnl = get_line(0);
	while (strgnl)
	{
		if (!ft_strncmp(strgnl, argv[2], ft_strlen(argv[2]))
			&& ft_strlen(argv[2]) == ft_strlen(strgnl) - 1)
			break ;
		buffer = ft_strjoin_free_first_param(buffer, strgnl);
		free(strgnl);
		strgnl = get_line(0);
	}
	free(strgnl);
	write(pipe_fd[1], buffer, ft_strlen(buffer));
	close(pipe_fd[1]);
	free(buffer);
	*fd = pipe_fd[0];
	return (1);
}

int	do_heredoc(int argc, char **argv, char **env)
{
	t_cmd	*cmds;

	cmds = is_valid_cmd(argc, argv, env, 3);
	pipexheredoc(cmds, argc, env, argv);
	wait_child(cmds);
	clean_cmds(&cmds);
	return (0);
}
