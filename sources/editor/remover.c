/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:39:39 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/27 10:29:24 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

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

void	remove_last_sprite(t_sprite **sprites)
{
	t_sprite *cur_sprite;
	t_sprite *prev_sprite;

	prev_sprite = *sprites;
	cur_sprite = (*sprites)->next;
	if (cur_sprite == NULL)
	{
		free(prev_sprite);
		*sprites = NULL;
		return ;
	}
	while (cur_sprite->next != NULL)
	{
		prev_sprite = cur_sprite;
		cur_sprite = cur_sprite->next;
	}
	if (cur_sprite->next == NULL)
	{
		prev_sprite->next = NULL;
		free(cur_sprite);
	}
}

void	remove_last_point(t_sdl *sdl, t_sector **head)
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
		sdl->count--;
		delete_point(prev_sector);
	}
}

void	reset(t_sdl *sdl)
{
	while (sdl->command_count > 0)
	{
		delete_last_command(sdl);
		sdl->command_count--;
	}
	sdl->count = 0;
}
