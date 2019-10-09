/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:13:11 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/08 11:08:23 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	draw_sidebar(t_sdl *sdl)
{
	SDL_Rect	sidebar;

	sidebar.x = SIZE_WIN_X * 0.8;
	sidebar.y = 0;
	sidebar.w = SIZE_WIN_X * 0.2;
	sidebar.h = SIZE_WIN_Y;
	SDL_SetRenderDrawColor(sdl->renderer, 20, 20, 40, 0);
	SDL_RenderFillRect(sdl->renderer, &sidebar);
}

void	redraw(t_sdl *sdl, t_point *grid_field)
{
	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl->renderer);
	draw_sidebar(sdl);
	draw_grid(sdl, grid_field);
}
