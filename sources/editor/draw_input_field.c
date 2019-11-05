/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_input_field.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:20:10 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/05 13:51:54 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		input_field(t_sdl *sdl, SDL_Rect *button)
{
	SDL_Rect	*r;
	SDL_Color	*color_text;

	button->x = INPUT_FIELD_X1;
	button->y = INPUT_FIELD_Y1;
	button->w = INPUT_FIELD_X2 - INPUT_FIELD_X1;
	button->h = INPUT_FIELD_Y2 - INPUT_FIELD_Y1;
	draw_button(sdl, *button, "", INPUT_FIELD);

	SDL_RenderFillRect(sdl->renderer, button);
	// free(r);
	color_text = create_sdl_color(0, 0, 0, 255);
	r->x = sdl->map_name->x:
	r->y = sdl->map_name->y
	r->w = INPUT_LETTER_SIZE * sdl->map_name->text_size;
	r->h = sdl->map_name->size_y;
	// r = create_sdl_rect(sdl->map_name->x, sdl->map_name->y,
	// 	INPUT_LETTER_SIZE * sdl->map_name->text_size, sdl->map_name->size_y);
	draw_text(sdl, sdl->map_name->text, *r, *color_text);
	free(r);
}
