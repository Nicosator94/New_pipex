/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:12:32 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 10:22:27 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

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
		if (execve(cmd.path, cmd.cmd, NULL) == -1)
			exec_error(cmd.cmd, cmd.path, list);
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
		if (execve(cmd.path, cmd.cmd, NULL) == -1)
			exec_error(cmd.cmd, cmd.path, list);
	}
	close(outfile);
	close(fd);
}

void	pipex(t_list *list, int argc, char *argv[], char **env)
{
	int	infile;
	int	outfile;
	int	temp_tube;

	infile = open(argv[1], O_RDONLY);
	if (infile != -1)
		temp_tube = pipex_start(env, list, infile);
	else
		temp_tube = without_infile(list, argv[1]);
	temp_tube = multi_pipex(env, list, temp_tube);
	outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (outfile != -1)
		pipex_end(env, list, outfile, temp_tube);
	else
		without_outfile(argv[argc - 1], temp_tube);
}
