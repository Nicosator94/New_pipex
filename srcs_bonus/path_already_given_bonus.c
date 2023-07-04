/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_already_given_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:49:53 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 09:25:39 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

int	len_without_cmd(char *cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '/')
			j = i;
		i ++;
	}
	return (j);
}

char	**search_cmd(char *cmd)
{
	char	**mat_cmd;
	char	*temp;
	int		i;

	i = len_without_cmd(cmd);
	temp = ft_strdup(&cmd[i]);
	if (temp == NULL)
		return (NULL);
	mat_cmd = ft_split(temp, ' ');
	free(temp);
	return (mat_cmd);
}

t_cmd	path_already_given(char *cmd, t_list *list)
{
	t_cmd	cmd_init;
	char	**temp;

	temp = ft_split(cmd, ' ');
	if (temp == NULL)
		malloc_error(list);
	cmd_init.path = ft_strdup(temp[0]);
	free_mat(temp);
	if (cmd_init.path == NULL)
		malloc_error(list);
	cmd_init.cmd = search_cmd(cmd);
	if (cmd_init.cmd == NULL)
	{
		free(cmd_init.path);
		malloc_error(list);
	}
	return (cmd_init);
}
