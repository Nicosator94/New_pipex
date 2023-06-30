/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:05:23 by niromano          #+#    #+#             */
/*   Updated: 2023/06/30 07:24:49 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	int		fd;
	char	*file[2];
	t_list	*list_of_cmd;

	list_of_cmd = init_struct(argc, argv);
	file[0] = argv[1];
	file[1] = argv[argc - 1];
	fd = pipex_start(env, list_of_cmd, file);
//	multi_pipex(list_of_cmd);
	pipex_end(env, list_of_cmd, file, fd);
	wait_all(list_of_cmd);
	ft_lstclear(&list_of_cmd);
	return (0);
}
