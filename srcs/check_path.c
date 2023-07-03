/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:11:24 by niromano          #+#    #+#             */
/*   Updated: 2023/07/03 12:16:15 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*check_path(char **cmd, char **env, t_list *list)
{
	char	*path;
	char	*temp;
	char	**new_env;
	int		i;

	i = 0;
	new_env = set_env(env, list);
	temp = ft_strjoin("/", cmd[0]);
	if (temp == NULL)
		malloc_error(list);
	while (new_env[i] != NULL && new_env != NULL)
	{
		path = ft_strjoin(new_env[i], temp);
		if (path == NULL)
			malloc_error(list);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i ++;
	}
	free_mat(new_env);
	free(temp);
	return (NULL);
}
