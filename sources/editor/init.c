/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:27:00 by djast             #+#    #+#             */
/*   Updated: 2019/10/19 12:18:03 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_sector	*init_sector()
{
	t_sector *sector;

	sector = (t_sector *)malloc(sizeof(t_sector));
	ft_bzero(sector->point, 100);
	sector->size = 0;
	sector->num_of_sector = 0;
	sector->type_of_point = 0;
	sector->z = 300;
	sector->next = NULL;
	return (sector);
}

void		init_sprites(t_sdl *sdl)
{
	sdl->sprites = (t_sprite *)malloc(sizeof(t_sprite));
	sdl->sprites->type = 0;
	sdl->sprites->x = 0;
	sdl->sprites->y = 0;
	sdl->sprites->next = NULL;
}

void		init_player(t_sdl *sdl)
{
	sdl->player = (t_point *)malloc(sizeof(t_point));
	sdl->player->x = 0;
	sdl->player->y = 0;
}

void		init_sdl(t_sdl *sdl)
{
	SDL_Init(SDL_INIT_VIDEO);
	sdl->window = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, SIZE_WIN_X, SIZE_WIN_Y,
					SDL_WINDOW_OPENGL);
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1,
					SDL_RENDERER_ACCELERATED);
	TTF_Init();
	sdl->font = TTF_OpenFont("resources/Samson.ttf", 200);
	// if(!sdl->font)
	// 	printf("TTF_OpenFont: %s\n", TTF_GetError());
	sdl->type_pressed = WALL_TYPE;
	sdl->sectors = NULL;
	sdl->commands = NULL;
	init_player(sdl);
	init_sprites(sdl);
	SDL_ShowCursor(1);
}
