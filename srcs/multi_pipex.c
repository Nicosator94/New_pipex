/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 08:05:03 by niromano          #+#    #+#             */
/*   Updated: 2023/06/30 07:17:57 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	multi_pipex(t_list *list_of_cmd)
{
	list_of_cmd = list_of_cmd->next;
	while (list_of_cmd->next != NULL)
	{
		ft_printf("%s\n", list_of_cmd->content);
		list_of_cmd = list_of_cmd->next;
	}
}
