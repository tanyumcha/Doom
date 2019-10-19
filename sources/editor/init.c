/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:27:00 by djast             #+#    #+#             */
/*   Updated: 2019/10/19 15:05:23 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_sector	*init_sector()
{
	t_sector	*sector;

	sector = (t_sector *)malloc(sizeof(t_sector));
	ft_bzero(sector->point, 100);
	sector->size = 0;
	sector->num_of_sector = 0;
	sector->type_of_point = 0;
	sector->z = 300;
	sector->next = NULL;
	return (sector);
}

t_sprite	*init_sprite()
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	sprite->type = 0;
	sprite->x = 0;
	sprite->y = 0;
	sprite->next = NULL;
	return (sprite);
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
	sdl->button_pushed = WALL_PUSH;
	sdl->sectors = init_sector();
	sdl->commands = NULL;
	sdl->sprites = NULL;
	init_player(sdl);
	SDL_ShowCursor(1);
}
