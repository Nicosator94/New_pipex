/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:14:50 by niromano          #+#    #+#             */
/*   Updated: 2023/06/28 14:31:53 by niromano         ###   ########.fr       */
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

char	**init_cmd(char *cmd);
char	*check_path(char **cmd, char **env);
char	**set_env(char **env);

#endif