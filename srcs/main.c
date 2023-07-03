/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:05:23 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 01:06:20 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char **env)
{
	int		temp_tube;
	int		infile;
	int		outfile;
	t_list	*list;

	if (argc != 5)
	{
		ft_putstr_fd("The number of arguments is not 5\n", 2);
		exit(EXIT_FAILURE);
	}
	list = init_struct(argc, argv);
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
	wait_all(list);
	ft_lstclear(&list);
	return (0);
}
