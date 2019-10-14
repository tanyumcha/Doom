/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigloop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:26:54 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/11 14:09:54 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	big_loop(t_sdl *sdl, t_point *grid_field, t_sector *head, t_sector *sector)
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
				remove_last_point(sdl, head, grid_field, &sector);
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_DELETE ==
					sdl->window_event.key.keysym.sym)
				remove_last_sector(sdl, head, grid_field, sector);
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_r ==
					sdl->window_event.key.keysym.sym)
				reset(sdl, head, grid_field);

			// else if (sdl->window_event.type == SDL_KEYDOWN && (SDLK_p ==
			// 		sdl->window_event.key.keysym.sym || SDLK_s ==
			// 		sdl->window_event.key.keysym.sym)) // || и другие
			// 	choose_type_of_point(&sector, sdl->window_event.key.keysym.sym);
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_p == // переписать по нормальму
					sdl->window_event.key.keysym.sym)
				choose_type_of_point(&sector, 1);
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_s ==
					sdl->window_event.key.keysym.sym)
				choose_type_of_point(&sector, 2);

			if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
					sdl->window_event.button.button == SDL_BUTTON_LEFT)
				take_a_lap(sdl, grid_field, head, &sector);
			else if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
					sdl->window_event.button.button == SDL_BUTTON_LEFT && sector->type_of_point > 0)
				set_stuff(sdl, head, grid_field, &sector);
		}
	}
}
