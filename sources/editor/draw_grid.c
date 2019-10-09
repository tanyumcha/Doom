/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 11:12:11 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/08 12:42:44 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	draw_hors(t_sdl *sdl, t_point *grid_field)
{
	int x;
	int y;

	y = 0;
	while (y < GRID_SIZE_Y)
	{
		x = 0;
		while (x < GRID_SIZE_X - 1)
		{
			x++;
			SDL_RenderDrawLine(sdl->renderer,
							grid_field[(y * GRID_SIZE_X + x) - 1].x,
							grid_field[(y * GRID_SIZE_X + x) - 1].y,
							grid_field[(y * GRID_SIZE_X + x)].x,
							grid_field[(y * GRID_SIZE_X + x)].y);
		}
		y++;
	}
}

void	draw_verts(t_sdl *sdl, t_point *grid_field)
{
	int x;
	int y;

	x = 0;
	while (x < GRID_SIZE_X)
	{
		y = 0;
		while (y < GRID_SIZE_Y - 1)
		{
			y++;
			SDL_RenderDrawLine(sdl->renderer,
							grid_field[(y * GRID_SIZE_X + x) - GRID_SIZE_X].x,
							grid_field[(y * GRID_SIZE_X + x) - GRID_SIZE_X].y,
							grid_field[(y * GRID_SIZE_X + x)].x,
							grid_field[(y * GRID_SIZE_X + x)].y);
		}
		x++;
	}
}

void	draw_grid(t_sdl *sdl, t_point *grid_field)
{
	SDL_Rect	grid;

	grid.x = 94;
	grid.y = 101;
	grid.w = (int)SIZE_WIN_X * 0.8 - grid.x * 2;
	grid.h = SIZE_WIN_Y - grid.y * 2;
	SDL_SetRenderDrawColor(sdl->renderer, 85, 26, 139, 0);
//	SDL_RenderDrawRect(sdl->renderer, &grid);
	draw_verts(sdl, grid_field);
	draw_hors(sdl, grid_field);
//	SDL_RenderPresent(sdl->renderer);
}
