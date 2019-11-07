/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:16:02 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/06 15:01:18 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	fill_a_sprite(t_sdl *sdl, t_sprite *cur_sprite, int x, int y)
{
	cur_sprite->type = sdl->button_pushed;
	cur_sprite->x = x;
	cur_sprite->y = y;
	cur_sprite->sector = sdl->sprite_in_sector;
	printf("sprite_in_sector %d\n", cur_sprite->sector);
	add_command(&(sdl->commands), SPRITE_TYPE);
}

void	set_sprite(t_sdl *sdl, int x, int y)
{
	t_sprite	*cur_sprite;

	cur_sprite = find_last_sprite(sdl->sprites);
	if (check_intersection(sdl, sdl->sectors, x, y) % 2 == 1)
	{
		if (cur_sprite == NULL)
		{
			sdl->sprites = init_sprite();
			cur_sprite = sdl->sprites;
		}
		else
		{
			cur_sprite->next = init_sprite();
			cur_sprite = cur_sprite->next;
		}
	}
	if (sdl->button_pushed >= MEDKIT_PUSH && sdl->button_pushed <= WALL_PUSH &&
			check_intersection(sdl, sdl->sectors, x, y) % 2 == 1)
		fill_a_sprite(sdl, cur_sprite, x, y);
}

void	set_player(t_sdl *sdl, int x, int y)
{
	if (check_intersection(sdl, sdl->sectors, x, y) % 2 == 1)
	{
		sdl->player->x = x;
		sdl->player->y = y;
		printf("Player is available\n");
		add_command(&(sdl->commands), PLAYER_TYPE);
	}
}

void	make_player_or_sprite(t_sdl *sdl)
{
	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
	if (sdl->mouse_position.x > 94 &&
			sdl->mouse_position.x < (int)SIZE_WIN_X * 0.8 - 94
			&& sdl->mouse_position.y > 101 &&
			sdl->mouse_position.y < SIZE_WIN_Y - 101)
	{
		if (sdl->type_pressed == PLAYER_TYPE)
			set_player(sdl, sdl->mouse_position.x, sdl->mouse_position.y);
		else if (sdl->type_pressed == SPRITE_TYPE)
			set_sprite(sdl, sdl->mouse_position.x, sdl->mouse_position.y);
	}
}
