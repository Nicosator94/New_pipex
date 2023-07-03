/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:05:23 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 01:40:11 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

int	check_here_doc(void)
{
	int	trigger;

	trigger = 0;
	if (access("here_doc", F_OK) == -1)
		trigger = 1;
	return (trigger);
}

void	here_doc(t_list *list, char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	close(fd);
	ft_lstclear(&list);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[], char **env)
{
	int		temp_tube;
	int		infile;
	int		outfile;
	int		trigger;
	t_list	*list;

	if (argc < 5)
	{
		ft_putstr_fd("The number of arguments is under that 5\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		trigger = check_here_doc();
	list = init_struct(argc, argv, trigger);
	if (trigger == 1)
		here_doc(list, argv[argc -1]);
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
	wait_all(list);
	ft_lstclear(&list);
	return (0);
}
