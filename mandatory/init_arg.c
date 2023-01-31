/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:09:07 by vviovi            #+#    #+#             */
/*   Updated: 2023/01/31 15:00:42 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_valid_files(char **argv, int argc, int *fd1, int *fd2)
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
	*fd2 = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (*fd2 == -1 || open(argv[argc - 1], O_DIRECTORY) != -1)
	{
		if ((*fd1) != -1)
			close(*fd1);
		perror(0);
		return (0);
	}
	return (1);
}

char	**getpathfromenv(char **env)
{
	char	*path;
	char	**pathsplit;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
			pathsplit = ft_split(path, ':');
			free(path);
			return (pathsplit);
		}
		i++;
	}
	return (NULL);
}

static int	is_valid_path(t_cmd *cmd, char **pathenv, int indexpath)
{
	char	*cmdpath;

	cmdpath = ft_strjoin(pathenv[indexpath], "/");
	cmdpath = ft_strjoin_free_first_param(cmdpath, cmd->cmd[0]);
	if (access(cmdpath, F_OK | X_OK) != -1)
	{
		free(cmd->cmd[0]);
		cleandbltab(pathenv);
		cmd->cmd[0] = cmdpath;
		return (1);
	}
	free(cmdpath);
	return (0);
}

int	get_path_cmd(t_cmd *cmd, char **env)
{
	char	**pathenv;
	int		i;

	if (cmd->cmd[0] == NULL)
		return (0);
	if (access(cmd->cmd[0], F_OK | X_OK) != -1)
		return (1);
	i = 0;
	pathenv = getpathfromenv(env);
	while (pathenv && pathenv[i])
	{
		if (is_valid_path(cmd, pathenv, i))
			return (1);
		i++;
	}
	cleandbltab(pathenv);
	return (0);
}

t_cmd	*is_valid_cmd(int argc, char **argv, char **env)
{
	t_cmd	*cmds;
	int		nb;
	int		i;

	cmds = malloc(sizeof(t_cmd) * (argc - 2));
	if (cmds == NULL)
		error_exit();
	nb = 2;
	i = 0;
	while (nb < argc - 1)
	{
		cmds[i] = init_cmd();
		cmds[i].cmd = ft_split(argv[nb], ' ');
		clean_simple_quote(cmds[i]);
		if (!get_path_cmd(&cmds[i], env) || cmds[i].cmd == NULL)
			cmds[i].pid = -42;
		nb++;
		i++;
	}
	cmds[i].cmd = NULL;
	return (cmds);
}
