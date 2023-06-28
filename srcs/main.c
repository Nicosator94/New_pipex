/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:05:23 by niromano          #+#    #+#             */
/*   Updated: 2023/06/28 15:21:24 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	set_cmd(char *cmd, char **env)
{
	t_cmd	cmd_init;
	
	cmd_init.cmd = init_cmd(cmd);
	cmd_init.path = check_path(cmd_init.cmd, env);
	return (cmd_init);
}

void	pipex_start(char **env, t_list *list, int file[2], int tube[2])
{
	pid_t	pid;
	t_cmd	cmd;
	
	pid = fork();
	if (pid == 0)
	{
		cmd = set_cmd(list->content, env);
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
	
	pid = fork();
	if (pid == 0)
	{
		cmd = set_cmd(list->content, env);
		close(file[0]);
		close(tube[1]);
		dup2(tube[0], 0);
		dup2(file[1], 1);
		close(file[1]);
		close(tube[0]);
		execve(cmd.path, cmd.cmd, NULL);
	}
}

t_list	*init_struct(int argc, char *argv[])
{
	t_list	*new_list;
	int		i;

	new_list = ft_lstnew(argv[2]);
	i = 3;
	while (i < argc - 1)
	{
		ft_lstadd_back(&new_list, ft_lstnew(argv[i]));
		i ++;
	}
	return (new_list);
}

void	wait_all(int time)
{
	int	n;

	n = 0;
	while (n < time)
	{
		wait(NULL);
		n ++;
	}
}

int	main(int argc, char *argv[], char **env)
{
	int		tube[2];
	int		file[2];
	t_list	*list_of_cmd;
	t_list	*temp;

	list_of_cmd = init_struct(argc, argv);
	temp = list_of_cmd;
	pipe(tube);
	file[0] = open(argv[1], O_RDONLY);
	file[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC);
	pipex_start(env, list_of_cmd, file, tube);
	list_of_cmd = list_of_cmd->next;
	while (list_of_cmd->next != NULL)
	{
		//multi_pipex();
		list_of_cmd = list_of_cmd->next;
	}
	pipex_end(env, list_of_cmd, file, tube);
	close(tube[0]);
	close(tube[1]);
	close(file[0]);
	close(file[1]);
	wait_all(2);
	ft_lstclear(&temp);
	return (0);
}
