/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:05:23 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 08:54:20 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

int	main(int argc, char *argv[], char **env)
{
	int		trigger;
	t_list	*list;

	if (argc < 5)
	{
		ft_putstr_fd("The number of arguments is under that 5\n", 2);
		exit(EXIT_FAILURE);
	}
	trigger = check_here_doc(argv[1]);
	list = init_struct(argc, argv, trigger);
	if (trigger == 1)
		here_doc(list, argc, argv, env);
	else
		pipex(list, argc, argv, env);
	wait_all(list);
	ft_lstclear(&list);
	return (0);
}
