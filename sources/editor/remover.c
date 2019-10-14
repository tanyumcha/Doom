/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:39:39 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/14 16:54:42 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	delete_point(t_sector *sector)
{
	sector->point[sector->size - 1].x = 0;
	sector->point[sector->size - 1].y = 0;
	sector->size--;
}

void	remove_last_point(t_sector **head)
{
	t_sector *cur_sector;
	t_sector *prev_sector;

	prev_sector = *head;
	cur_sector = (*head)->next;
	if (cur_sector == NULL)
	{
		if (prev_sector->size > 0)
			delete_point(prev_sector);
		return ;
	}
	while (cur_sector->next != NULL)
	{
		prev_sector = cur_sector;
		cur_sector = cur_sector->next;
	}
	if (cur_sector->size > 0)
		delete_point(cur_sector);
	else if (cur_sector->size == 0)
	{
		prev_sector->next = NULL;
		free(cur_sector);
		delete_point(prev_sector);
	}
}

void	reset(t_sector **head)
{
	t_sector **prev;
	t_sector **cur;

	prev = head;
	cur = &((*head)->next);
	while (*cur != NULL)
	{
		free(*prev);
		*prev = *cur;
		*cur = (*cur)->next;
	}
	ft_bzero((*prev)->point, 100);
	(*prev)->size = 0;
}
