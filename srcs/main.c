/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:05:23 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 09:46:32 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char **env)
{
	t_list	*list;

	if (argc != 5)
	{
		ft_putstr_fd("The number of arguments is not 5\n", 2);
		exit(EXIT_FAILURE);
	}
	list = init_struct(argc, argv);
	pipex(list, argc, argv, env);
	wait_all(list);
	ft_lstclear(&list);
	return (0);
}
