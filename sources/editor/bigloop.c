/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigloop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:26:54 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/14 17:49:33 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	big_loop(t_sdl *sdl)
{
	while (1)
	{
		if (SDL_PollEvent(&sdl->window_event))
		{
			if (SDL_QUIT ==	sdl->window_event.type)
				exit(0);
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_ESCAPE ==
					sdl->window_event.key.keysym.sym)
				exit(0);
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_BACKSPACE ==
					sdl->window_event.key.keysym.sym)
				delete_last_command(sdl);
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_r ==
					sdl->window_event.key.keysym.sym)
				reset(&(sdl->sectors));
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_w == // переписать по нормальму
			 		sdl->window_event.key.keysym.sym)
			 	sdl->type_pressed = WALL_TYPE;
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_p == // переписать по нормальму
			 		sdl->window_event.key.keysym.sym)
			 	sdl->type_pressed = PLAYER_TYPE;
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_s ==
					sdl->window_event.key.keysym.sym)
				sdl->type_pressed = SPRITE_TYPE;

			else if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
					sdl->window_event.button.button == SDL_BUTTON_LEFT)
			{
				if (sdl->type_pressed == WALL_TYPE)
					make_wall(sdl);
				else if (sdl->type_pressed == PLAYER_TYPE || sdl->type_pressed == SPRITE_TYPE)
					make_player_or_sprite(sdl);
				//else if (sdl->type_pressed == SPRITE_TYPE)
					//make_sprite(sdl);
			}
			// else if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
			// 		sdl->window_event.button.button == SDL_BUTTON_LEFT && sector->type_of_point > 0)
			// 	set_stuff(sdl, grid_field, &sector);
			draw(sdl);
		}
	}
}
