/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:11:35 by niromano          #+#    #+#             */
/*   Updated: 2023/06/30 07:56:02 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// t_cmd	path_already_given(char *cmd, char **env, t_list *list)
// {
// 	t_cmd	cmd_init;

// 	cmd_init.cmd
// 	return (cmd_init);
// }

t_cmd	set_cmd(char *cmd, char **env, t_list *list)
{
	t_cmd	cmd_init;

//	if (cmd[0] == '/')
//		return (path_already_given(cmd, env, list));
	cmd_init.cmd = ft_split(cmd, ' ');
	if (cmd_init.cmd == NULL)
		malloc_error(list);
	cmd_init.path = check_path(cmd_init.cmd, env, list);
	if (cmd_init.path == NULL)
	{
		free_mat(cmd_init.cmd);
		ft_putstr_fd("Command not found\n", 2);
		ft_lstclear(&list);
		exit(EXIT_FAILURE);
	}
	return (cmd_init);
}
