/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:12:32 by niromano          #+#    #+#             */
/*   Updated: 2023/06/29 09:15:50 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_start(char **env, t_list *list, int file[2], int tube[2])
{
	pid_t	pid;
	t_cmd	cmd;
	
	pid = fork();
	if (pid == -1)
		system_error(list);
	if (pid == 0)
	{
		cmd = set_cmd(list->content, env, list);
		close(file[1]);
		close(tube[0]);
		dup2(file[0], 0);
		dup2(tube[1], 1);
		close(file[0]);
		close(tube[1]);
		execve(cmd.path, cmd.cmd, NULL);
	}
}

void	pipex_end(char **env, t_list *list, int file[2], int tube[2])
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
		close(file[0]);
		close(tube[1]);
		dup2(tube[0], 0);
		dup2(file[1], 1);
		close(file[1]);
		close(tube[0]);
		execve(cmd.path, cmd.cmd, NULL);
	}
}
