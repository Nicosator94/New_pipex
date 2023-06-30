/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:33:06 by niromano          #+#    #+#             */
/*   Updated: 2023/06/30 11:23:20 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_line(char **env)
{
	int		i;
	char	*line;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			line = env[i];
			return (&line[5]);
		}
		i ++;
	}
	return (NULL);
}

char	**set_env(char **env, t_list *list)
{
	char	**new_env;
	char	*path_line;

	path_line = search_line(env);
	if (path_line == NULL)
		return (NULL);
	new_env = ft_split(path_line, ':');
	if (new_env == NULL)
		malloc_error(list);
	return (new_env);
}