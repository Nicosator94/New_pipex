/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:12:32 by niromano          #+#    #+#             */
/*   Updated: 2023/06/30 08:00:32 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	file_fd_error(int fd, t_list *list)
{
	close(fd);
	system_error(list);
}

void	file_tube_error(int tube[2], t_list *list)
{
	close(tube[0]);
	close(tube[1]);
	system_error(list);
}

int	pipex_start(char **env, t_list *list, int fd)
{
	pid_t	pid;
	t_cmd	cmd;
	int		tube[2];

	if (pipe(tube) == -1)
		system_error(list);
	pid = fork();
	if (pid == -1)
		system_error(list);
	if (pid == 0)
	{
		cmd = set_cmd(list->content, env, list);
		close(tube[0]);
		dup2(fd, 0);
		dup2(tube[1], 1);
		close(fd);
		close(tube[1]);
		execve(cmd.path, cmd.cmd, NULL);
	}
	close(fd);
	close(tube[1]);
	return (tube[0]);
}

void	pipex_end(char **env, t_list *list, int outfile, int fd)
{
	pid_t	pid;
	t_cmd	cmd;
	t_list	*temp;

	temp = list;
	while (list->next != NULL)
		list = list->next;
	pid = fork();
	if (pid == -1)
		system_error(temp);
	if (pid == 0)
	{
		cmd = set_cmd(list->content, env, temp);
		dup2(fd, 0);
		dup2(outfile, 1);
		close(fd);
		close(outfile);
		execve(cmd.path, cmd.cmd, NULL);
	}
	close(outfile);
	close(fd);
}
