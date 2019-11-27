/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:58:34 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/27 14:02:19 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	textinput(t_sdl *sdl)
{
	if (sdl->map_name->text_size + 1 < sdl->map_name->max_text_size)
	{
		ft_strcat(sdl->map_name->text, sdl->window_event.text.text);
		sdl->map_name->text_size++;
	}
}

void	text_events(t_sdl *sdl)
{
	if (sdl->window_event.type == SDL_KEYDOWN &&
			sdl->is_input == 1 && SDLK_BACKSPACE ==
			sdl->window_event.key.keysym.sym)
		delete_one_symbol(sdl);
	else if (sdl->window_event.type == SDL_TEXTINPUT && sdl->is_input == 1)
		textinput(sdl);
}

void	exit_events(t_sdl *sdl)
{
	if (SDL_QUIT == sdl->window_event.type)
		exit(0);
	else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_ESCAPE ==
			sdl->window_event.key.keysym.sym)
		exit(0);
}
