/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:25:28 by vviovi            #+#    #+#             */
/*   Updated: 2023/01/24 14:19:26 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	clean_cmds(t_cmd **cmds)
{
	int	i;

	if (!cmds)
		return ;
	i = 0;
	while ((*cmds) && (*cmds)[i].cmd)
	{
		cleandbltab((*cmds)[i].cmd);
		(*cmds)[i].cmd = NULL;
		i++;
	}
	if ((*cmds))
		free((*cmds));
	(*cmds) = NULL;
}

void	cleandbltab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

t_cmd	init_cmd(void)
{
	t_cmd	cmd;

	cmd.cmd = NULL;
	cmd.fd_in = -1;
	cmd.fd_out = -1;
	cmd.pid = 0;
	cmd.to_close[0] = -1;
	cmd.to_close[1] = -1;
	return (cmd);
}

void	error_exit(void)
{
	perror(0);
	exit(1);
}

void	display_error_cmd(t_cmd *cmds, int index_cmd)
{
	char	*str_error;

	str_error = ft_strjoin("command not found: ", cmds[index_cmd].cmd[0]);
	str_error = ft_strjoin_free_first_param(str_error, "\n");
	write(2, str_error, ft_strlen(str_error));
	free(str_error);
}
