/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:46:34 by niromano          #+#    #+#             */
/*   Updated: 2023/06/29 09:33:41 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
	{
		free(mat[i]);
		i ++;
	}
	free(mat);
}

void	malloc_error(t_list *list)
{
	ft_putstr_fd("Allocated memory failed\n", 2);
	ft_lstclear(&list);
	exit(EXIT_FAILURE);
}

void	system_error(t_list *list)
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
