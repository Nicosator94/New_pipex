/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:11:35 by niromano          #+#    #+#             */
/*   Updated: 2023/06/29 07:14:31 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**init_cmd(char *cmd)
{
	char	**new;

	new = ft_split(cmd, ' ');
	return (new);
}

t_cmd	set_cmd(char *cmd, char **env)
{
	t_cmd	cmd_init;
	
	cmd_init.cmd = init_cmd(cmd);
	cmd_init.path = check_path(cmd_init.cmd, env);
	return (cmd_init);
}
