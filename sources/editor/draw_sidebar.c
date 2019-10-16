/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sidebar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:31:52 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/16 15:10:30 by eharrag-         ###   ########.fr       */
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

void			draw_button(t_sdl *sdl, SDL_Rect button, char *text)
{
	SDL_Color	*color_text;

	SDL_SetRenderDrawColor(sdl->renderer, 025, 000, 051, 255);
	SDL_RenderFillRect(sdl->renderer, &button);
	color_text = create_sdl_color(204, 153, 255, 255);
	draw_text(sdl, text, button, *color_text);
	free(color_text);
}

void			draw_buttons_on_sidebar(t_sdl *sdl)
{
	SDL_Rect	*button;
	int			num_of_sprites;
	int			i;

	i = 0;
	num_of_sprites = 12;
	button = (SDL_Rect *)malloc(sizeof(SDL_Rect));
	while (i <= num_of_sprites)
	{
		i++;
		button->x = SIZE_WIN_X * 0.8 + SIZE_WIN_X * 0.2 * 0.1;
		button->y = SIZE_WIN_Y * 0.1 * (i * 0.7);
		button->w = SIZE_WIN_X * 0.2 - SIZE_WIN_X * 0.2 * 0.2;
		button->h = SIZE_WIN_Y * 0.05;

		if (i == 1)
			draw_button(sdl, *button, " SET A PLAYER");
		else if (i == 2)
			draw_button(sdl, *button, " SET A MEDKIT");
		else
			draw_button(sdl, *button, " SET A CHA CHA CHA");
	}
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
