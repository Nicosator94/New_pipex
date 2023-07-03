/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:14:58 by niromano          #+#    #+#             */
/*   Updated: 2023/07/04 01:30:34 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/pipex_bonus.h"

t_list	*init_struct(int argc, char *argv[], int trigger)
{
	t_list	*new_list;
	t_list	*temp;
	int		i;

	new_list = ft_lstnew(argv[2 + trigger]);
	if (new_list == NULL)
		malloc_error(new_list);
	i = 3 + trigger;
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
