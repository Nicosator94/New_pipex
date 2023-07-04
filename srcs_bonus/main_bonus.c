/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:05:23 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 07:53:37 by niromano         ###   ########.fr       */
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
	pipex(list, argc, argv, env);
	wait_all(list);
	ft_lstclear(&list);
	return (0);
}
