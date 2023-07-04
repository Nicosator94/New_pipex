/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 08:05:03 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 10:45:42 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

int	more_pipex(char **env, char *content, t_list *list, int fd)
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
		cmd = set_cmd(content, env, list);
		close(tube[0]);
		dup2(fd, 0);
		dup2(tube[1], 1);
		close(fd);
		close(tube[1]);
		check_cmd(list, cmd);
		if (execve(cmd.path, cmd.cmd, NULL) == -1)
			exec_error(cmd.cmd, cmd.path, list);
	}
	close(fd);
	close(tube[1]);
	return (tube[0]);
}

int	multi_pipex(char **env, t_list *list, int fd)
{
	t_list	*temp;

	temp = list->next;
	while (temp->next != NULL)
	{
		fd = more_pipex(env, temp->content, list, fd);
		temp = temp->next;
	}
	return (fd);
}
