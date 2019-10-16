/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigloop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:26:54 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/16 15:16:25 by eharrag-         ###   ########.fr       */
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
			// else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_p == // переписать по нормальму
			//  		sdl->window_event.key.keysym.sym)

			// else if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
			// 		sdl->window_event.button.button == SDL_BUTTON_LEFT)
			// {
			// 	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
			// 	if ((sdl->mouse_position.x > BUTTON_PLAYER_X1 && sdl->mouse_position.x < BUTTON_PLAYER_X2) &&
			// 			(sdl->mouse_position.y > BUTTON_PLAYER_Y1 && sdl->mouse_position.y < BUTTON_PLAYER_Y2))
			// 	{
			// 		sdl->type_pressed = PLAYER_TYPE;
			// 		printf("Player");
			// 	}
			// }
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_s ==
					sdl->window_event.key.keysym.sym)
				sdl->type_pressed = SPRITE_TYPE;

			else if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
					sdl->window_event.button.button == SDL_BUTTON_LEFT)
			{
				SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
				if (sdl->type_pressed == WALL_TYPE)
					make_wall(sdl);
				if ((sdl->mouse_position.x > BUTTON_PLAYER_X1 && sdl->mouse_position.x < BUTTON_PLAYER_X2) &&
						(sdl->mouse_position.y > BUTTON_PLAYER_Y1 && sdl->mouse_position.y < BUTTON_PLAYER_Y2))
				{
					sdl->type_pressed = PLAYER_TYPE;
					printf("Player\n");
				}
				else if ((sdl->mouse_position.x > BUTTON_MEDKIT_X1 && sdl->mouse_position.x < BUTTON_MEDKIT_X2) &&
						(sdl->mouse_position.y > BUTTON_MEDKIT_Y1 && sdl->mouse_position.y < BUTTON_MEDKIT_Y2))
				{
					sdl->type_pressed = SPRITE_TYPE;
					printf("Medkit\n");
				}
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
