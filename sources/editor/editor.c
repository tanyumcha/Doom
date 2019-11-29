/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:05:37 by djast             #+#    #+#             */
/*   Updated: 2019/11/29 14:00:45 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int	main(void)
{
	t_sdl	*sdl;

	sleep(5);
	sdl = (t_sdl *)malloc(sizeof(t_sdl));
	init_sdl(sdl);
	SDL_ShowCursor(1);
	init_grid(sdl->grid_field);
	redraw(sdl);
	SDL_RenderPresent(sdl->renderer);
	big_loop(sdl);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
}
