/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:51:57 by leaugust          #+#    #+#             */
/*   Updated: 2024/11/12 15:51:59 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	print_list(t_list **msg)
{
	t_list	*current;

	current = *msg;
	while (current)
	{
		ft_printf("%c", *(char *)current->content);
		current = current->next;
	}
	ft_printf("\n");
}

void	free_all(t_list **msg)
{
	t_list	*temp;

	while ((*msg))
	{
		temp = *msg;
		free((*msg)->content);
		(*msg)->content = NULL;
		*msg = (*msg)->next;
		free(temp);
		temp = NULL;
	}
}
