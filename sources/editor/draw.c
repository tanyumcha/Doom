/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:11:40 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/19 16:33:48 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	draw_a_sprite(t_sdl *sdl, t_sprite *sprites)
{
	SDL_Rect	newrect;

	while (sprites != NULL)
	{
		if (sprites->type == MEDKIT_PUSH)
			SDL_SetRenderDrawColor(sdl->renderer, 255, 051, 051, 0);
		else if (sprites->type == ARMOR_PUSH)
			SDL_SetRenderDrawColor(sdl->renderer, 051, 102, 153, 0);
		else if (sprites->type == POWER_UP_PUSH)
			SDL_SetRenderDrawColor(sdl->renderer, 051, 102, 051, 0);
		else if (sprites->type == RIFLE_AMMO_PUSH)
			SDL_SetRenderDrawColor(sdl->renderer, 204, 153, 000, 0);
		else if (sprites->type == PLASMA_GUN_PUSH)
			SDL_SetRenderDrawColor(sdl->renderer, 255, 255, 000, 0);
		else if (sprites->type == PLASMA_AMMO_PUSH)
			SDL_SetRenderDrawColor(sdl->renderer, 204, 255, 000, 0);
		else if (sprites->type == BARREL_PUSH)
			SDL_SetRenderDrawColor(sdl->renderer, 102, 051, 000, 0);
		else if (sprites->type == AFRIT_PUSH)
			SDL_SetRenderDrawColor(sdl->renderer, 204, 000, 000, 0);
		else if (sprites->type == CACODEMON_PUSH)
			SDL_SetRenderDrawColor(sdl->renderer, 150, 000, 100, 0);
		else if (sprites->type == IMP_PUSH)
			SDL_SetRenderDrawColor(sdl->renderer, 200, 100, 100, 0);
		else if (sprites->type == JETPACK_PUSH)
			SDL_SetRenderDrawColor(sdl->renderer, 000, 000, 255, 0);
		newrect.x = sprites->x - POINT_SIZE / 2;
		newrect.y = sprites->y - POINT_SIZE / 2;
		newrect.w = POINT_SIZE;
		newrect.h = POINT_SIZE;
		SDL_RenderFillRect(sdl->renderer, &newrect);
		sprites = sprites->next;
	}
}

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
		cur_sector = cur_sector->next;
	}
	if (sdl->player->x != 0 && sdl->player->y != 0)
		draw_a_player(sdl, sdl->player);
	draw_a_sprite(sdl, sdl->sprites);
	SDL_RenderPresent(sdl->renderer);
}
