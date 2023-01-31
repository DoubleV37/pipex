/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:42:48 by vviovi            #+#    #+#             */
/*   Updated: 2023/01/31 14:54:25 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

/*utils.c*/
void	clean_cmds(t_cmd **cmds);
void	cleandbltab(char **tab);
t_cmd	init_cmd(void);
void	error_exit(void);
void	display_error_cmd(t_cmd *cmds, int index_cmd);

/*init_arg.c*/
t_cmd	*is_valid_cmd(int argc, char **argv, char **env);
int		get_path_cmd(t_cmd *cmd, char **env);
char	**getpathfromenv(char **env);
int		is_valid_files(char **argv, int argc, int *fd1, int *fd2);

/*pipex_utils.c*/
void	pipex_start(t_cmd *cmds, int i, int *pipe_fd, int *fd);
void	pipex_end_even(t_cmd *cmds, int i, int *pipe_fd2, int *fd);
void	pipex_end_odd(t_cmd *cmds, int i, int *pipe_fd, int *fd);
void	pipex_even_odd(t_cmd *cmds, int i, int *pipe_fd, int *pipe_fd2);
void	clean_simple_quote(t_cmd cmd);

#endif
