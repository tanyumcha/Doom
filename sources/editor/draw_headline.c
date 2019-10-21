/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_headline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:23:36 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/21 14:36:47 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	draw_headline(t_sdl *sdl)
{
	SDL_Rect	headline;

	headline.x = 94;
	headline.y = 25;
	headline.w = (int)SIZE_WIN_X * 0.8 - headline.x * 2;
	headline.h = 50;
	SDL_SetRenderDrawColor(sdl->renderer, 20, 20, 40, 0);
	SDL_RenderFillRect(sdl->renderer, &headline);
	draw_text(sdl,
		" Rm last command - BACKSPACE || Rm player - DELETE || Full reset - R",
		headline, *(create_sdl_color(204, 153, 255, 255)));
}
