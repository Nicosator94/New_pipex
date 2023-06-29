/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:14:50 by niromano          #+#    #+#             */
/*   Updated: 2023/06/29 07:56:26 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "libft/libft.h"

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
}	t_cmd;

char	*check_path(char **cmd, char **env);
char	**set_env(char **env);
t_cmd	set_cmd(char *cmd, char **env);
t_list	*init_struct(int argc, char *argv[]);

void	pipex_start(char **env, t_list *list, int file[2], int tube[2]);
void	pipex_end(char **env, t_list *list, int file[2], int tube[2]);

void	wait_all(t_list *list);

// Check_error

void	malloc_error(t_list *list);
void	pipe_error(t_list *list);
void	check_file(int	file[2], t_list *list);

#endif