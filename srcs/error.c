/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:46:34 by niromano          #+#    #+#             */
/*   Updated: 2023/06/29 07:47:45 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	malloc_error(t_list *list)
{
	ft_lstclear(&list);
	ft_putstr_fd("Allocated memory failed\n", 2);
	exit(EXIT_FAILURE);
}

void	pipe_error(t_list *list)
{
	perror("Error ");
	ft_lstclear(&list);
	exit(EXIT_FAILURE);
}

void	check_file(int	file[2], t_list *list)
{
	if (file[0] == -1 && file[1] == -1)
	{
		perror("Error both files ");
		ft_lstclear(&list);
		exit(EXIT_FAILURE);
	}
	else if (file[0] == -1)
	{
		close(file[1]);
		perror("Error infile ");
		ft_lstclear(&list);
		exit(EXIT_FAILURE);
	}
	else if (file[1] == -1)
	{
		close(file[0]);
		perror("Error outfile ");
		ft_lstclear(&list);
		exit(EXIT_FAILURE);
	}
}
