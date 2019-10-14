/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:39:39 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/11 11:02:45 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	remove_last_point(t_sdl *sdl, t_sector *head, t_point *grid_field, t_sector **sector)
{
	if ((*sector)->size > 0)
	{
		(*sector)->point[(*sector)->size].x = 0;
		(*sector)->point[(*sector)->size].y = 0;
		(*sector)->size--;
		draw(sdl, head, grid_field);
	}
	else if ((*sector)->size == 0)
	{
		(*sector)->point[(*sector)->size - 1].x = 0;
		(*sector)->point[(*sector)->size - 1].y = 0;
	}
}

void	remove_last_sector(t_sdl *sdl, t_sector *head, t_point *grid_field, t_sector *sector)
{
	if (sector != NULL)
	{
		ft_bzero(sector->point, 100);
		sector->size = 0;
		sector->next = NULL;
		draw(sdl, head, grid_field);
	}
}

void	reset(t_sdl *sdl, t_sector *head, t_point *grid_field)
{
	while (head != NULL)
	{
		ft_bzero(head->point, 100);
		head->size = 0;
		head = head->next;
	}
	draw(sdl, head, grid_field);
}
