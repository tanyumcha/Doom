/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:05:37 by djast             #+#    #+#             */
/*   Updated: 2019/10/19 11:38:58 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int			main ()
{
	t_sdl		*sdl;
	int			i;

	i = 0;
	sdl = (t_sdl *)malloc(sizeof(t_sdl));
	init_sdl(sdl);
	sdl->sectors = init_sector();

	init_grid(sdl->grid_field);
	redraw(sdl);
	SDL_RenderPresent(sdl->renderer);
	big_loop(sdl);
	// while (1)
	// {
	// 	if (SDL_PollEvent(&sdl->window_event))
	// 	{
	// 		if (SDL_QUIT == sdl->window_event.type)
	// 			break;
	// 		else if (SDLK_ESCAPE == sdl->window_event.key.keysym.sym)
	// 			break;
	// 		if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
	// 				sdl->window_event.button.button == SDL_BUTTON_LEFT)
	// 			take_a_lap(sdl, grid_field, head, &sector);
	// 	}
	// }
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
}
