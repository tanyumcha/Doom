/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:11:40 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/10 16:05:23 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	draw_a_point(t_sdl *sdl, t_point *point, int i)
{
	SDL_Rect	newrect;

	newrect.x = point[i].x - POINT_SIZE / 2;
	newrect.y = point[i].y - POINT_SIZE / 2;
	newrect.w = POINT_SIZE;
	newrect.h = POINT_SIZE;
	SDL_RenderFillRect(sdl->renderer, &newrect);
}

void	draw_a_sector(t_sdl *sdl, t_sector *sector, int dots)
{
	int j;


	SDL_SetRenderDrawColor(sdl->renderer, 153, 204, 255, 0);
	draw_a_point(sdl, sector->point, 0);
	j = 1;
	while (j < dots)
	{
		draw_a_point(sdl, sector->point, j);
		SDL_RenderDrawLine(sdl->renderer, sector->point[j - 1].x, sector->point[j - 1].y,
							sector->point[j].x, sector->point[j].y);
		j++;
	}
}

void	draw(t_sdl *sdl, t_sector *head, t_point *grid_field)
{
	redraw(sdl, grid_field);
	while (head != NULL)
	{
		draw_a_sector(sdl, head, head->size);
		head = head->next;
	}
	SDL_RenderPresent(sdl->renderer);
}
