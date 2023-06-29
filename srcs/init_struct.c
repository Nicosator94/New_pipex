/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:14:58 by niromano          #+#    #+#             */
/*   Updated: 2023/06/29 07:15:06 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*init_struct(int argc, char *argv[])
{
	t_list	*new_list;
	int		i;

	new_list = ft_lstnew(argv[2]);
	i = 3;
	while (i < argc - 1)
	{
		ft_lstadd_back(&new_list, ft_lstnew(argv[i]));
		i ++;
	}
	return (new_list);
}
