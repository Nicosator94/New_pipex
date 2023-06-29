/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:05:23 by niromano          #+#    #+#             */
/*   Updated: 2023/06/29 08:08:18 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	int		tube[2];
	int		file[2];
	t_list	*list_of_cmd;
	t_list	*temp;

	list_of_cmd = init_struct(argc, argv);
	temp = list_of_cmd;
	if (pipe(tube) == -1)
		pipe_error(list_of_cmd);
	file[0] = open(argv[1], O_RDONLY);
	file[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	check_file(file, list_of_cmd);
	pipex_start(env, list_of_cmd, file, tube);
	list_of_cmd = list_of_cmd->next;
	list_of_cmd = multi_pipex(list_of_cmd);
	pipex_end(env, list_of_cmd, file, tube);
	close(tube[0]);
	close(tube[1]);
	close(file[0]);
	close(file[1]);
	wait_all(temp);
	ft_lstclear(&temp);
	return (0);
}
