/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:05:23 by niromano          #+#    #+#             */
/*   Updated: 2023/06/29 10:15:55 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	int		tube[2];
	char	*file[3];
	t_list	*list_of_cmd;

	list_of_cmd = init_struct(argc, argv);
	if (pipe(tube) == -1)
		system_error(list_of_cmd);
	file[0] = argv[1];
	file[1] = argv[argc - 1];
	file[2] = NULL;
	pipex_start(env, list_of_cmd, file, tube);
//	multi_pipex(list_of_cmd);
	pipex_end(env, list_of_cmd, file, tube);
	close(tube[0]);
	close(tube[1]);
	wait_all(list_of_cmd);
	ft_lstclear(&list_of_cmd);
	return (0);
}
