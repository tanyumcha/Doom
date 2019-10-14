/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigloop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:26:54 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/10 14:37:05 by eharrag-         ###   ########.fr       */
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
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_d ==
					sdl->window_event.key.keysym.sym)
				remove_last_point(sdl, head, grid_field, &sector);
			if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
					sdl->window_event.button.button == SDL_BUTTON_LEFT)
				take_a_lap(sdl, grid_field, head, &sector);
		}
	}
}
