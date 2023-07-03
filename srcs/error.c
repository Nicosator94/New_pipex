/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:46:34 by niromano          #+#    #+#             */
/*   Updated: 2023/07/03 12:07:49 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	check_file(int infile, int outfile, t_list *list)
{
	if (infile == -1 && outfile == -1)
	{
		perror("Error both files ");
		ft_lstclear(&list);
		exit(EXIT_FAILURE);
	}
	else if (infile == -1)
	{
		perror("Error infile ");
		close(outfile);
		ft_lstclear(&list);
		exit(EXIT_FAILURE);
	}
	else if (outfile == -1)
	{
		perror("Error outfile ");
		close(infile);
		ft_lstclear(&list);
		exit(EXIT_FAILURE);
	}
}
