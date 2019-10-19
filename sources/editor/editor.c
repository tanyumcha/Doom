/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:05:37 by djast             #+#    #+#             */
/*   Updated: 2019/10/19 14:53:23 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int	main()
{
	t_sdl	*sdl;

	sdl = (t_sdl *)malloc(sizeof(t_sdl));
	init_sdl(sdl);
	// sdl->sectors = init_sector();
	// sdl->sprites = init_sprite();
	init_grid(sdl->grid_field);
	redraw(sdl);
	SDL_RenderPresent(sdl->renderer);
	big_loop(sdl);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
}
