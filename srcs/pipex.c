/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:12:32 by niromano          #+#    #+#             */
/*   Updated: 2023/06/29 10:17:02 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(char **env, t_list *list, char *file[3], int tube[2])
{
	pid_t	pid;
	t_cmd	cmd;
	int		fd;

	pid = fork();
	if (pid == -1)
		system_error(list);
	if (pid == 0)
	{
		fd = open(file[0], O_RDONLY);
		if (fd == -1)
			system_error(list);
		cmd = set_cmd(list->content, env, list);
		close(tube[0]);
		dup2(fd, 0);
		dup2(tube[1], 1);
		close(fd);
		close(tube[1]);
		execve(cmd.path, cmd.cmd, NULL);
	}
}

void	pipex_end(char **env, t_list *list, char *file[3], int tube[2])
{
	pid_t	pid;
	t_cmd	cmd;
	t_list	*temp;
	int		fd;

	temp = list;
	while (list->next != NULL)
		list = list->next;
	pid = fork();
	if (pid == -1)
		system_error(temp);
	if (pid == 0)
	{
		fd = open(file[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == -1)
			system_error(temp);
		cmd = set_cmd(list->content, env, temp);
		close(tube[1]);
		dup2(tube[0], 0);
		dup2(fd, 1);
		close(fd);
		close(tube[0]);
		execve(cmd.path, cmd.cmd, NULL);
	}
}
