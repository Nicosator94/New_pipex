/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:12:32 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 10:53:37 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_cmd(t_list *list, t_cmd cmd)
{
	if (cmd.path == NULL || cmd.cmd == NULL)
	{
		ft_putstr_fd("Command not found\n", 2);
		ft_lstclear(&list);
		exit(EXIT_FAILURE);
	}
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
		check_cmd(list, cmd);
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
		check_cmd(temp, cmd);
		if (execve(cmd.path, cmd.cmd, NULL) == -1)
			exec_error(cmd.cmd, cmd.path, temp);
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
	outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (outfile != -1)
		pipex_end(env, list, outfile, temp_tube);
	else
		without_outfile(argv[argc - 1], temp_tube);
}
