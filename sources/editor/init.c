/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:27:00 by djast             #+#    #+#             */
/*   Updated: 2019/11/23 16:02:57 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_input_field	*init_input_field(int x1, int y1, int x2, int y2)
{
	t_input_field	*field;

	field = (t_input_field *)malloc(sizeof(t_input_field));
	field->x = x1;
	field->y = y1;
	field->size_x = x2 - x1;
	field->size_y = y2 - y1;
	field->max_text_size = 20;
	field->text = ft_strnew(field->max_text_size);
	field->text_size = 0;
	return (field);
}

t_sprite	*init_sprite(void)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	sprite->type = 0;
	sprite->x = 0;
	sprite->y = 0;
	sprite->sector = 0;
	sprite->next = NULL;
	return (sprite);
}

// t_walls		*init_wall(void)
// {
// 	t_walls	*wall;

// 	wall = (t_walls *)malloc(sizeof(t_walls));
// 	wall->portal = -1;
// 	wall->wall_id = 0;
// 	wall->x1 = 0;
// 	wall->y1 = 0;
// 	wall->x2 = 0;
// 	wall->y2 = 0;
// 	wall->neighbour_x1 = 0;
// 	wall->neighbour_y1 = 0;
// 	wall->neighbour_x2 = 0;
// 	wall->neighbour_y2 = 0;
// 	wall->next = NULL;
// 	return (wall);
// }

t_sector	*init_sector(void)
{
	t_sector	*sector;

	sector = (t_sector *)malloc(sizeof(t_sector));
	ft_bzero(sector->point, 1000);
	ft_bzero(sector->walls, 1000);
	sector->size = 0;
	sector->total_num_of_obj = 0;
	sector->num_of_sector = 0;
	sector->num_of_walls = 0;
	sector->type_of_point = 0;
	sector->z = 300;
	sector->cmn = 0;
	sector->sh = 0;
	sector->rh = 0;
	sector->next = NULL;
	return (sector);
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
	sdl->command_count = 0;
	sdl->sprites = NULL;
	sdl->sprite_in_sector = 0;
	sdl->count = 0;
	sdl->map_name = init_input_field(INPUT_FIELD_X1, INPUT_FIELD_Y1,
									INPUT_FIELD_X2, INPUT_FIELD_Y2);
	init_player(sdl);
	SDL_ShowCursor(1);
}
