/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:14:58 by niromano          #+#    #+#             */
/*   Updated: 2023/06/29 07:35:09 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	malloc_error(t_list *list)
{
	ft_lstclear(&list);
	ft_putstr_fd("Allocated memory failed\n", 2);
	exit(EXIT_FAILURE);
}

t_list	*init_struct(int argc, char *argv[])
{
	t_list	*new_list;
	t_list	*temp;
	int		i;

	new_list = ft_lstnew(argv[2]);
	if (new_list == NULL)
		malloc_error(new_list);
	i = 3;
	while (i < argc - 1)
	{
		temp = ft_lstnew(argv[i]);
		if (temp == NULL)
			malloc_error(new_list);
		ft_lstadd_back(&new_list, temp);
		i ++;
	}
	return (new_list);
}
