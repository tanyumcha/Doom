/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sidebar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:31:52 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/17 10:50:19 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void			draw_text(t_sdl *sdl, char *text, SDL_Rect button, SDL_Color color)
{
	sdl->surface = TTF_RenderText_Solid(sdl->font, text, color);
	SDL_DestroyTexture(sdl->text);
	sdl->text = SDL_CreateTextureFromSurface(sdl->renderer,
											sdl->surface);
	SDL_FreeSurface(sdl->surface);
	SDL_RenderCopy(sdl->renderer, sdl->text, NULL, &button);
}

SDL_Color		*create_sdl_color(int r, int g, int b, int a)
{
	SDL_Color *color;

	color = (SDL_Color *)malloc(sizeof(SDL_Color));
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = a;
	return (color);
}

void			draw_button(t_sdl *sdl, SDL_Rect button, char *text, int color)
{
	SDL_Color	*color_text;

	if (color == COLOR_PUSHED && sdl->type_pressed == PLAYER_TYPE)
		SDL_SetRenderDrawColor(sdl->renderer, 50, 205, 50, 255);

	else if (color == COLOR_UNPUSHED)
		SDL_SetRenderDrawColor(sdl->renderer, 025, 000, 051, 255);

	SDL_RenderFillRect(sdl->renderer, &button);
	color_text = create_sdl_color(204, 153, 255, 255);
	draw_text(sdl, text, button, *color_text);
	free(color_text);
}

void			draw_buttons_on_sidebar(t_sdl *sdl)
{
	SDL_Rect	*button;

	button = (SDL_Rect *)malloc(sizeof(SDL_Rect));

	button->x = SIZE_WIN_X * 0.8 + SIZE_WIN_X * 0.2 * 0.1;
	button->y = SIZE_WIN_Y * 0.1 * (1 * 0.7);
	button->w = SIZE_WIN_X * 0.2 - SIZE_WIN_X * 0.2 * 0.2;
	button->h = SIZE_WIN_Y * 0.05;

	if (sdl->button_pushed == PLAYER_PUSH)
		draw_button(sdl, *button, " PLAYER", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " PLAYER", COLOR_UNPUSHED);

	button->x = SIZE_WIN_X * 0.8 + SIZE_WIN_X * 0.2 * 0.1;
	button->y = SIZE_WIN_Y * 0.1 * (2 * 0.7);
	button->w = SIZE_WIN_X * 0.2 - SIZE_WIN_X * 0.2 * 0.2;
	button->h = SIZE_WIN_Y * 0.05;
	if (sdl->button_pushed == SPRITE_PUSH)
		draw_button(sdl, *button, " SET A MEDKIT", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " SET A MEDKIT", COLOR_UNPUSHED);

	button->x = SIZE_WIN_X * 0.8 + SIZE_WIN_X * 0.2 * 0.1;
	button->y = SIZE_WIN_Y * 0.1 * (3 * 0.7);
	button->w = SIZE_WIN_X * 0.2 - SIZE_WIN_X * 0.2 * 0.2;
	button->h = SIZE_WIN_Y * 0.05;
	if (sdl->button_pushed == SPRITE_PUSH)
		draw_button(sdl, *button, " SET CHA CHA CHA", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " SET CHA CHA CHA", COLOR_UNPUSHED);

	free(button);
}

void			draw_sidebar(t_sdl *sdl)
{
	SDL_Rect	sidebar;

	sidebar.x = SIZE_WIN_X * 0.8;
	sidebar.y = 0;
	sidebar.w = SIZE_WIN_X * 0.2;
	sidebar.h = SIZE_WIN_Y;
	SDL_SetRenderDrawColor(sdl->renderer, 20, 20, 40, 0);
	SDL_RenderFillRect(sdl->renderer, &sidebar);
	draw_buttons_on_sidebar(sdl);
}
