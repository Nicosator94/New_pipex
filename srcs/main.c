/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:05:23 by niromano          #+#    #+#             */
/*   Updated: 2023/06/30 08:00:57 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	int		temp_tube;
	int		infile;
	int		outfile;
	t_list	*list_of_cmd;

	list_of_cmd = init_struct(argc, argv);
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	temp_tube = pipex_start(env, list_of_cmd, infile);
//	multi_pipex(list_of_cmd);
	pipex_end(env, list_of_cmd, outfile, temp_tube);
	wait_all(list_of_cmd);
	ft_lstclear(&list_of_cmd);
	return (0);
}
