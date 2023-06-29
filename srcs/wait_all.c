/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:15:41 by niromano          #+#    #+#             */
/*   Updated: 2023/06/29 08:00:35 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_all(t_list *list)
{
	int i = 1;
	while (list != NULL)
	{
		wait(NULL);
		ft_printf("%d\n", i);
		i ++;
		list = list->next;
	}
}
