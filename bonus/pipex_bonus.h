/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:42:48 by vviovi            #+#    #+#             */
/*   Updated: 2023/01/31 14:58:48 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char	**cmd;
	int		fd_in;
	int		fd_out;
	int		to_close[2];
	pid_t	pid;
}	t_cmd;

//utils_bonus.c
void	clean_cmds(t_cmd **cmds);
void	cleandbltab(char **tab);
t_cmd	init_cmd(void);
void	display_error_cmd(t_cmd *cmds, int index_cmd);
void	closefd(int *fd);

//init_arg_bonus.c
int		open_output(char **argv, int argc, int *fd2);
int		open_output_heredoc(char **argv, int argc, int *fd2);
t_cmd	*is_valid_cmd(int argc, char **argv, char **env, int indexstart);
int		get_path_cmd(t_cmd *cmd, char **env);
char	**getpathfromenv(char **env);

//pipex_utils_bonus.c
int		open_input(char **argv, int *fd1);
void	pipex_start(t_cmd *cmds, int i, int *pipe_fd, char **argv);
void	pipex_end_even(t_cmd *cmds, int i, int *pipe_fd2, char **argv);
void	pipex_end_odd(t_cmd *cmds, int i, int *pipe_fd, char **argv);
void	pipex_even_odd(t_cmd *cmds, int i, int *pipe_fd, int *pipe_fd2);

//heredoc_bonus.c
char	*get_line(int fd);
void	init_pipe(int *pipe_fd, int *pipe_fd2);
void	pipexheredoc(t_cmd *cmds, int argc, char **env, char **argv);
int		get_heredoc(char **argv, int *fd);
int		do_heredoc(int argc, char **argv, char **env);

//main.c
void	dupclose_fd(t_cmd *cmds, int index_cmd);
pid_t	exe_cmd(t_cmd *cmds, int index_cmd, char **env);
void	wait_child(t_cmd *cmds);
char	*get_line(int fd);
void	pipex(t_cmd *cmds, int argc, char **env, char **argv);

//pipex_utils_heredoc_bonus.c
void	clean_simple_quote(t_cmd cmd);
void	pipex_start_heredoc(t_cmd *cmds, int i, int *pipe_fd, char **argv);
void	pipex_end_even_heredoc(t_cmd *cmds, int i, int *pipe_fd2, char **argv);
void	pipex_end_odd_heredoc(t_cmd *cmds, int i, int *pipe_fd, char **argv);

#endif
