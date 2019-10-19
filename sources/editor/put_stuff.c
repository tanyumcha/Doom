/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:16:02 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/19 16:35:00 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	set_sprite(t_sdl *sdl, int x, int y)
{
	t_sprite	*cur_sprite;

	cur_sprite = find_last_sprite(sdl->sprites);
	if (check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
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
	if (sdl->button_pushed == MEDKIT_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cur_sprite->type = MEDKIT_PUSH;
		cur_sprite->x = x;
		cur_sprite->y = y;
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == ARMOR_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cur_sprite->type = ARMOR_PUSH;
		cur_sprite->x = x;
		cur_sprite->y = y;
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == POWER_UP_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cur_sprite->type = POWER_UP_PUSH;
		cur_sprite->x = x;
		cur_sprite->y = y;
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == RIFLE_AMMO_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cur_sprite->type = RIFLE_AMMO_PUSH;
		cur_sprite->x = x;
		cur_sprite->y = y;
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == PLASMA_GUN_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cur_sprite->type = PLASMA_GUN_PUSH;
		cur_sprite->x = x;
		cur_sprite->y = y;
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == PLASMA_AMMO_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cur_sprite->type = PLASMA_AMMO_PUSH;
		cur_sprite->x = x;
		cur_sprite->y = y;
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == BARREL_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cur_sprite->type = BARREL_PUSH;
		cur_sprite->x = x;
		cur_sprite->y = y;
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == AFRIT_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cur_sprite->type = AFRIT_PUSH;
		cur_sprite->x = x;
		cur_sprite->y = y;
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == CACODEMON_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cur_sprite->type = CACODEMON_PUSH;
		cur_sprite->x = x;
		cur_sprite->y = y;
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == IMP_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cur_sprite->type = IMP_PUSH;
		cur_sprite->x = x;
		cur_sprite->y = y;
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == JETPACK_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cur_sprite->type = JETPACK_PUSH;
		cur_sprite->x = x;
		cur_sprite->y = y;
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
}

void	set_player(t_sdl *sdl, int x, int y)
{
	if (check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
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
	if (sdl->mouse_position.x > 94 && sdl->mouse_position.x < (int)SIZE_WIN_X * 0.8 - 94
			&& sdl->mouse_position.y > 101 && sdl->mouse_position.y < SIZE_WIN_Y - 101)
	{
		if (sdl->type_pressed == PLAYER_TYPE)
			set_player(sdl, sdl->mouse_position.x, sdl->mouse_position.y);
		else if (sdl->type_pressed == SPRITE_TYPE)
			set_sprite(sdl, sdl->mouse_position.x, sdl->mouse_position.y);
	}
}
