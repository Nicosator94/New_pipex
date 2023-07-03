/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:46:34 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 01:10:03 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

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

void	exec_error(char **cmd, char *path, t_list *list)
{
	ft_putstr_fd("Command not found\n", 2);
	free_mat(cmd);
	free(path);
	ft_lstclear(&list);
	exit(EXIT_FAILURE);
}
