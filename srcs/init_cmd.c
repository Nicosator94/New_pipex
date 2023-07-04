/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:11:35 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 09:51:23 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	env_null(t_list *list)
{
	ft_putstr_fd("Command not found\n", 2);
	ft_lstclear(&list);
	exit(EXIT_FAILURE);
}

int	verify_env(char **env)
{
	int	trigger;
	int	i;

	i = 0;
	trigger = -1;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			trigger = 0;
		i ++;
	}
	return (trigger);
}

t_cmd	set_cmd(char *cmd, char **env, t_list *list)
{
	t_cmd	cmd_init;

	if (cmd[0] == '\0')
	{
		ft_putstr_fd("Command not found\n", 2);
		ft_lstclear(&list);
		exit(EXIT_FAILURE);
	}
	if (cmd[0] == '/' || cmd[0] == '.')
		return (path_already_given(cmd, list));
	if (verify_env(env) == -1)
		env_null(list);
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
