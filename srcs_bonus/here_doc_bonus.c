/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 08:27:23 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 11:22:21 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

void	gnl_to_temp(int temp, char *limiter)
{
	char	*s;

	limiter = ft_strjoin(limiter, "\n");
	s = get_next_line(0, limiter);
	while (ft_strncmp(s, limiter, ft_strlen(s)) != 0)
	{
		ft_putstr_fd(s, temp);
		free(s);
		s = get_next_line(0, limiter);
	}
	free(limiter);
}

int	set_temp_here_doc(t_list *list, char *limiter)
{
	pid_t	pid;
	int		tube[2];

	if (pipe(tube) == -1)
		system_error(list);
	pid = fork();
	if (pid == -1)
		system_error(list);
	wait(NULL);
	if (pid == 0)
	{
		close(tube[0]);
		gnl_to_temp(tube[1], limiter);
		close(tube[1]);
		ft_lstclear(&list);
		exit(EXIT_SUCCESS);
	}
	close(tube[1]);
	return (tube[0]);
}

void	here_doc(t_list *list, int argc, char *argv[], char **env)
{
	int	outfile;
	int	temp_tube;

	if (argc < 6)
	{
		ft_putstr_fd("The number of arguments is under that 6\n", 2);
		ft_lstclear(&list);
		exit(EXIT_FAILURE);
	}
	temp_tube = set_temp_here_doc(list, argv[2]);
	temp_tube = pipex_start(env, list, temp_tube);
	temp_tube = multi_pipex(env, list, temp_tube);
	outfile = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (outfile != -1)
		pipex_end(env, list, outfile, temp_tube);
	else
		without_outfile(argv[argc - 1], temp_tube);
}

int	check_here_doc(char *argv)
{
	int	trigger;

	trigger = 0;
	if (ft_strncmp(argv, "here_doc", 9) == 0 && access("here_doc", F_OK) == -1)
		trigger = 1;
	return (trigger);
}
