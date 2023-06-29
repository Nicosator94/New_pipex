/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:46:34 by niromano          #+#    #+#             */
/*   Updated: 2023/06/29 10:14:19 by niromano         ###   ########.fr       */
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
