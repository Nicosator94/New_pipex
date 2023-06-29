/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 08:05:03 by niromano          #+#    #+#             */
/*   Updated: 2023/06/29 08:06:59 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*multi_pipex(t_list *list_of_cmd)
{
	while (list_of_cmd->next != NULL)
	{
		list_of_cmd = list_of_cmd->next;
	}
	return (list_of_cmd);
}
