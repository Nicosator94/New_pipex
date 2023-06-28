/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:11:24 by niromano          #+#    #+#             */
/*   Updated: 2023/06/28 14:47:23 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path(char **cmd, char **env)
{
	char	*path;
	char	*temp;
	char	**new_env;
	int		i;

	i = 0;
	new_env = set_env(env);
	temp = ft_strjoin("/", cmd[0]);
	while (env[i] != NULL)
	{
		path = ft_strjoin(new_env[i], temp);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		i ++;
	}
	return (NULL);
}
