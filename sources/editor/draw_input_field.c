/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_input_field.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:20:10 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/11 15:20:39 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		input_field(t_sdl *sdl)
{
	SDL_Rect	*field;
	SDL_Color	*color_text;
	char		*name;

	field = (SDL_Rect *)malloc(sizeof(SDL_Rect));
	field->x = INPUT_FIELD_X1;
	field->y = INPUT_FIELD_Y1;
	field->w = INPUT_FIELD_X2 - INPUT_FIELD_X1;
	field->h = INPUT_FIELD_Y2 - INPUT_FIELD_Y1;
	SDL_SetRenderDrawColor(sdl->renderer, 204, 204, 255, 255);
	SDL_RenderFillRect(sdl->renderer, field);
	free(field);
	color_text = create_sdl_color(0, 0, 0, 255); // почему-то цвет не меняется
	field->x = sdl->map_name->x;
	field->y = sdl->map_name->y;
	field->w = INPUT_LETTER_SIZE * sdl->map_name->text_size;
	field->h = sdl->map_name->size_y;
	if (sdl->button_pushed == SAVE_PUSH)
	{
		name = sdl->map_name->text;
		name = cut_the_end(name);
		draw_text(sdl, name, *field, *color_text);
	}
	else
		draw_text(sdl, sdl->map_name->text, *field, *color_text);
	free(field);
}
