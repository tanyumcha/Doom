/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:16:02 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/18 11:48:32 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	set_sprite(t_sdl *sdl, int x, int y)
{
	t_sprite	*cursprite;

	cursprite = sdl->sprites;
	if (sdl->button_pushed == MEDKIT_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cursprite->type = MEDKIT_PUSH;
		cursprite->x = x;
		cursprite->y = y;
		cursprite->next = (t_sprite *)malloc(sizeof(t_sprite));
		ft_bzero(cursprite->next, sizeof(t_sprite));
		printf("Medkit is available\n");
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == ARMOR_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cursprite->type = ARMOR_PUSH;
		cursprite->x = x;
		cursprite->y = y;
		cursprite->next = (t_sprite *)malloc(sizeof(t_sprite));
		ft_bzero(cursprite->next, sizeof(t_sprite));
		printf("Medkit is available\n");
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == POWER_UP_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cursprite->type = POWER_UP_PUSH;
		cursprite->x = x;
		cursprite->y = y;
		cursprite->next = (t_sprite *)malloc(sizeof(t_sprite));
		ft_bzero(cursprite->next, sizeof(t_sprite));
		printf("Power_up is available\n");
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == RIFLE_AMMO_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cursprite->type = RIFLE_AMMO_PUSH;
		cursprite->x = x;
		cursprite->y = y;
		cursprite->next = (t_sprite *)malloc(sizeof(t_sprite));
		ft_bzero(cursprite->next, sizeof(t_sprite));
		printf("Rifle ammo is available\n");
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == PLASMA_GUN_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cursprite->type = PLASMA_GUN_PUSH;
		cursprite->x = x;
		cursprite->y = y;
		cursprite->next = (t_sprite *)malloc(sizeof(t_sprite));
		ft_bzero(cursprite->next, sizeof(t_sprite));
		printf("Plasma gun is available\n");
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == PLASMA_AMMO_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cursprite->type = PLASMA_AMMO_PUSH;
		cursprite->x = x;
		cursprite->y = y;
		cursprite->next = (t_sprite *)malloc(sizeof(t_sprite));
		ft_bzero(cursprite->next, sizeof(t_sprite));
		printf("Plasma ammo is available\n");
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	else if (sdl->button_pushed == BARREL_PUSH && check_intersection(sdl->sectors, 0, 0, x, y) % 2 == 1)
	{
		cursprite->type = BARREL_PUSH;
		cursprite->x = x;
		cursprite->y = y;
		cursprite->next = (t_sprite *)malloc(sizeof(t_sprite));
		ft_bzero(cursprite->next, sizeof(t_sprite));
		printf("Plasma ammo is available\n");
		add_command(&(sdl->commands), SPRITE_TYPE);
	}
	cursprite = cursprite->next;
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
