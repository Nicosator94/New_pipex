/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:05:23 by niromano          #+#    #+#             */
/*   Updated: 2023/07/03 12:05:08 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char **env)
{
	int		temp_tube;
	int		infile;
	int		outfile;
	t_list	*list;

	list = init_struct(argc, argv);
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	check_file(infile, outfile, list);
	temp_tube = pipex_start(env, list, infile);
	temp_tube = multi_pipex(env, list, temp_tube);
	pipex_end(env, list, outfile, temp_tube);
	wait_all(list);
	ft_lstclear(&list);
	return (0);
}
