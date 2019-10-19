/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:39:39 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/19 10:59:47 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

// void	remove_last_sprite(t_sprite *sprites)
// {
// 	while (sprites != NULL)
// 		sprites = sprites->next;

// }

void	delete_sprites(t_sprite *sprites)
{
	while (sprites != NULL) // доделать
	{
		sprites->type = 0;
		sprites->x = 0;
		sprites->y = 0;
		sprites = sprites->next;
	}
}

void	delete_player(t_point *player)
{
	player->x = 0;
	player->y = 0;
}

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

void	reset(t_sector **head, t_point	*player, t_sprite *sprites)
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
	delete_player(player);
	delete_sprites(sprites);
}
