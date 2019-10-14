/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:11:40 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/14 17:48:36 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	draw_a_player(t_sdl *sdl, t_point *player)
{
	SDL_Rect	newrect;

	SDL_SetRenderDrawColor(sdl->renderer, 50, 205, 50, 100);
	newrect.x = player->x - POINT_SIZE / 2;
	newrect.y = player->y - POINT_SIZE / 2;
	newrect.w = POINT_SIZE;
	newrect.h = POINT_SIZE;
	SDL_RenderFillRect(sdl->renderer, &newrect);
}

void	draw_a_point(t_sdl *sdl, t_point *point, int i)
{
	SDL_Rect	newrect;

	SDL_SetRenderDrawColor(sdl->renderer, 153, 204, 255, 0);
	newrect.x = point[i].x - POINT_SIZE / 2;
	newrect.y = point[i].y - POINT_SIZE / 2;
	newrect.w = POINT_SIZE;
	newrect.h = POINT_SIZE;
	SDL_RenderFillRect(sdl->renderer, &newrect);
}

void	draw_a_sector(t_sdl *sdl, t_sector *sector, int dots)
{
	int j;

	j = 0;
	while (j < dots)
	{
		draw_a_point(sdl, sector->point, j);
		if (j != 0)
			SDL_RenderDrawLine(sdl->renderer, sector->point[j - 1].x, sector->point[j - 1].y,
								sector->point[j].x, sector->point[j].y);
		j++;
	}
}

void	draw(t_sdl *sdl)
{
	t_sector *cur_sector;

	cur_sector = sdl->sectors;
	redraw(sdl);
	while (cur_sector != NULL)
	{
		if (cur_sector->type_of_point == 0)
			draw_a_sector(sdl, cur_sector, cur_sector->size);
		// else if (head->type_of_point == 2)
		// {
		// 	SDL_SetRenderDrawColor(sdl->renderer, 204, 102, 255, 0);
		// 	draw_a_point(sdl, head->point, head->type_of_point);
		// }
		cur_sector = cur_sector->next;
	}
	if (sdl->player->x != 0 && sdl->player->y != 0)
		draw_a_player(sdl, sdl->player);
	SDL_RenderPresent(sdl->renderer);
}
