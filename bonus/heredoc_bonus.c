/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:30:07 by vviovi            #+#    #+#             */
/*   Updated: 2023/01/26 17:19:48 by vviovi           ###   ########.fr       */
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

void	pipexheredoc(t_cmd *cmds, int argc, int *fd, char **env)
{
	int	i;
	int	pipe_fd[2];
	int	pipe_fd2[2];

	i = 0;
	init_pipe(pipe_fd, pipe_fd2);
	while (cmds[i].cmd)
	{
		if (i % 2 == 0)
			pipe(pipe_fd);
		else if (argc > 6 && i % 2 != 0)
			pipe(pipe_fd2);
		if (i == 0)
			pipex_start(cmds, i, pipe_fd, fd);
		else if (i == argc - 5 && i % 2 != 0)
			pipex_end_odd(cmds, i, pipe_fd, fd);
		else if (i == argc - 5 && i % 2 == 0)
			pipex_end_even(cmds, i, pipe_fd2, fd);
		else
			pipex_even_odd(cmds, i, pipe_fd, pipe_fd2);
		cmds[i].pid = exe_cmd(cmds, i, env, fd);
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
	fd[0] = pipe_fd[0];
	return (1);
}

int	do_heredoc(int argc, char **argv, char **env)
{
	int		fd[2];
	t_cmd	*cmds;

	if (!get_heredoc(argv, fd))
		return (0);
	fd[1] = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	if (open(argv[argc - 1], O_DIRECTORY) != -1)
	{
		if (fd[1] != -1)
			close(fd[1]);
		perror(0);
		return (1);
	}
	cmds = is_valid_cmd(argc, argv, env, 3);
	pipexheredoc(cmds, argc, fd, env);
	wait_child(cmds);
	closefd(fd);
	clean_cmds(&cmds);
	return (0);
}
