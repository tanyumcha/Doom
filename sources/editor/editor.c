/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:05:37 by djast             #+#    #+#             */
/*   Updated: 2019/10/08 15:38:31 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_sector	*init_sector()
{
	t_sector *sector;

	sector = (t_sector *)malloc(sizeof(t_sector));
	ft_bzero(sector->point, 100);
	sector->size = 0;
	sector->next = NULL;
	return (sector);
}

void		init_sdl(t_sdl *sdl)
{
	SDL_Init(SDL_INIT_VIDEO);
	sdl->window = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, SIZE_WIN_X, SIZE_WIN_Y,
					SDL_WINDOW_OPENGL);
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1,
					SDL_RENDERER_ACCELERATED);
	SDL_ShowCursor(1);
}

// void		take_a_lap(t_sdl *sdl, t_point *grid_field, t_sector *head, t_sector **sector)
// {
// 	int i;

// 	i = 0;
// 	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
// //	SDL_Log("Mouse position: x=%i y=%i", sdl->mouse_position.x, sdl->mouse_position.y);
// 	if ((*sector)->size > 2 && ((sdl->mouse_position.x >= (*sector)->point[0].x - POINT_SIZE / 2 &&
// 			sdl->mouse_position.x <= (*sector)->point[0].x + POINT_SIZE / 2) &&
// 			(sdl->mouse_position.y >= (*sector)->point[0].y - POINT_SIZE / 2 &&
// 			sdl->mouse_position.y <= (*sector)->point[0].y + POINT_SIZE / 2)))
// 	// if ((*sector)->size > 2 && (i = check_the_grid(grid_field, sdl->mouse_position.x, sdl->mouse_position.y)) >= 0)
// 	{
// 		if ((i = check_the_grid(grid_field, sdl->mouse_position.x, sdl->mouse_position.y)) >= 1)
// 		{
// 			(*sector)->point[(*sector)->size].x = (*sector)->point[0].x;
// 			(*sector)->point[(*sector)->size].y = (*sector)->point[0].y;
// 			// (*sector)->point[(*sector)->size].x = grid_field[i].x;
// 			// (*sector)->point[(*sector)->size].y = grid_field[i].y;
// 			draw(sdl, head, grid_field);
// 			(*sector)->next = init_sector();
// 			(*sector) = (*sector)->next;
// 			printf("SAVE\n");
// 	//		save_the_sector(sector->point);
// 			(*sector)->size = 0;
// 		}
// 	}
// 	else if (sdl->mouse_position.x < (int)(SIZE_WIN_X * 0.8))
// 	{
// 		if ((i = check_the_grid(grid_field, sdl->mouse_position.x, sdl->mouse_position.y)) >= 0)
// 		{
// 			(*sector)->point[(*sector)->size].x = grid_field[i].x;
// 			(*sector)->point[(*sector)->size].y = grid_field[i].y;
// 			draw(sdl, head, grid_field);
// 			(*sector)->size++;
// 		}
// 	}
// }

int			main ()
{
	t_sdl		*sdl;
	t_sector	*sector;
	t_sector	*head;
	t_point		grid_field[GRID_SIZE];
	int			i;

	i = 0;
	sdl = (t_sdl *)malloc(sizeof(t_sdl));
	sector = init_sector();;
	head = sector;
	init_sdl(sdl);
	init_grid(grid_field);
	redraw(sdl, grid_field);
	SDL_RenderPresent(sdl->renderer);
	big_loop(sdl, grid_field, head, sector);
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
