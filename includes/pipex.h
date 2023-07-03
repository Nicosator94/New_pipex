/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:14:50 by niromano          #+#    #+#             */
/*   Updated: 2023/07/03 14:09:00 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "../libft/libft.h"

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
}	t_cmd;

char	*check_path(char **cmd, char **env, t_list *list);
char	**set_env(char **env, t_list *list);
t_cmd	set_cmd(char *cmd, char **env, t_list *list);
t_cmd	path_already_given(char *cmd, t_list *list);
t_list	*init_struct(int argc, char *argv[]);

int		pipex_start(char **env, t_list *list, int fd);
void	pipex_end(char **env, t_list *list, int outfile, int fd);

void	wait_all(t_list *list);

// Check_error

void	free_mat(char **mat);
void	malloc_error(t_list *list);
void	system_error(t_list *list);
void	check_file(int infile, int outfile, t_list *list);
void	exec_error(char **cmd, char *path, t_list *list);

#endif