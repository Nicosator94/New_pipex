/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_problem_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:58:17 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 01:09:33 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

int	without_infile(t_list *list, char *infile)
{
	int	tube[2];

	if (access(infile, F_OK) == -1)
		ft_putstr_fd("Error infile : No such file or directory\n", 2);
	else if (access(infile, R_OK) == -1)
		ft_putstr_fd("Error infile : Permission denied\n", 2);
	if (pipe(tube) == -1)
		system_error(list);
	close(tube[1]);
	return (tube[0]);
}

void	without_outfile(char *outfile, int fd)
{
	close(fd);
	if (access(outfile, W_OK) == -1)
		ft_putstr_fd("Error outfile : Permission denied\n", 2);
}
