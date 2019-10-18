/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigloop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:26:54 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/18 13:13:45 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	clicks(t_sdl *sdl)
{
	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
	if (sdl->type_pressed == WALL_TYPE)
		make_wall(sdl);
	if ((sdl->mouse_position.x > BUTTON_PLAYER_X1 && sdl->mouse_position.x < BUTTON_PLAYER_X2) &&
			(sdl->mouse_position.y > BUTTON_PLAYER_Y1 && sdl->mouse_position.y < BUTTON_PLAYER_Y2))
	{
		sdl->type_pressed = PLAYER_TYPE;
		sdl->button_pushed = PLAYER_PUSH;
		printf("Player\n");
	}
	else if ((sdl->mouse_position.x > BUTTON_MEDKIT_X1 && sdl->mouse_position.x < BUTTON_MEDKIT_X2) &&
			(sdl->mouse_position.y > BUTTON_MEDKIT_Y1 && sdl->mouse_position.y < BUTTON_MEDKIT_Y2))
	{
		sdl->type_pressed = SPRITE_TYPE;
		sdl->button_pushed = MEDKIT_PUSH;
		printf("Medkit\n");
	}
	else if ((sdl->mouse_position.x > BUTTON_ARMOR_X1 && sdl->mouse_position.x < BUTTON_ARMOR_X2) &&
			(sdl->mouse_position.y > BUTTON_ARMOR_Y1 && sdl->mouse_position.y < BUTTON_ARMOR_Y2))
	{
		sdl->type_pressed = SPRITE_TYPE;
		sdl->button_pushed = ARMOR_PUSH;
		printf("Armor\n");
	}
	else if ((sdl->mouse_position.x > BUTTON_POWER_UP_X1 && sdl->mouse_position.x < BUTTON_POWER_UP_X2) &&
			(sdl->mouse_position.y > BUTTON_POWER_UP_Y1 && sdl->mouse_position.y < BUTTON_POWER_UP_Y2))
	{
		sdl->type_pressed = SPRITE_TYPE;
		sdl->button_pushed = POWER_UP_PUSH;
		printf("Power up\n");
	}
	else if ((sdl->mouse_position.x > BUTTON_RIFLE_AMMO_X1 && sdl->mouse_position.x < BUTTON_RIFLE_AMMO_X2) &&
			(sdl->mouse_position.y > BUTTON_RIFLE_AMMO_Y1 && sdl->mouse_position.y < BUTTON_RIFLE_AMMO_Y2))
	{
		sdl->type_pressed = SPRITE_TYPE;
		sdl->button_pushed = RIFLE_AMMO_PUSH;
		printf("Rifle ammo\n");
	}
	else if ((sdl->mouse_position.x > BUTTON_PLASMA_GUN_X1 && sdl->mouse_position.x < BUTTON_PLASMA_GUN_X2) &&
			(sdl->mouse_position.y > BUTTON_PLASMA_GUN_Y1 && sdl->mouse_position.y < BUTTON_PLASMA_GUN_Y2))
	{
		sdl->type_pressed = SPRITE_TYPE;
		sdl->button_pushed = PLASMA_GUN_PUSH;
		printf("Plasma gun\n");
	}
	else if ((sdl->mouse_position.x > BUTTON_PLASMA_AMMO_X1 && sdl->mouse_position.x < BUTTON_PLASMA_AMMO_X2) &&
			(sdl->mouse_position.y > BUTTON_PLASMA_AMMO_Y1 && sdl->mouse_position.y < BUTTON_PLASMA_AMMO_Y2))
	{
		sdl->type_pressed = SPRITE_TYPE;
		sdl->button_pushed = PLASMA_AMMO_PUSH;
		printf("Plasma ammo\n");
	}
	else if ((sdl->mouse_position.x > BUTTON_BARREL_X1 && sdl->mouse_position.x < BUTTON_BARREL_X2) &&
			(sdl->mouse_position.y > BUTTON_BARREL_Y1 && sdl->mouse_position.y < BUTTON_BARREL_Y2))
	{
		sdl->type_pressed = SPRITE_TYPE;
		sdl->button_pushed = BARREL_PUSH;
		printf("Barrel\n");
	}
	else if ((sdl->mouse_position.x > BUTTON_AFRIT_X1 && sdl->mouse_position.x < BUTTON_AFRIT_X2) &&
			(sdl->mouse_position.y > BUTTON_AFRIT_Y1 && sdl->mouse_position.y < BUTTON_AFRIT_Y2))
	{
		sdl->type_pressed = SPRITE_TYPE;
		sdl->button_pushed = AFRIT_PUSH;
		printf("Afrit\n");
	}
	else if ((sdl->mouse_position.x > BUTTON_CACODEMON_X1 && sdl->mouse_position.x < BUTTON_CACODEMON_X2) &&
			(sdl->mouse_position.y > BUTTON_CACODEMON_Y1 && sdl->mouse_position.y < BUTTON_CACODEMON_Y2))
	{
		sdl->type_pressed = SPRITE_TYPE;
		sdl->button_pushed = CACODEMON_PUSH;
		printf("Cacodemon\n");
	}
	else if ((sdl->mouse_position.x > BUTTON_IMP_X1 && sdl->mouse_position.x < BUTTON_IMP_X2) &&
			(sdl->mouse_position.y > BUTTON_IMP_Y1 && sdl->mouse_position.y < BUTTON_IMP_Y2))
	{
		sdl->type_pressed = SPRITE_TYPE;
		sdl->button_pushed = IMP_PUSH;
		printf("Imp\n");
	}
	else if ((sdl->mouse_position.x > BUTTON_WALL_X1 && sdl->mouse_position.x < BUTTON_WALL_X2) &&
			(sdl->mouse_position.y > BUTTON_WALL_Y1 && sdl->mouse_position.y < BUTTON_WALL_Y2))
	{
		sdl->type_pressed = WALL_TYPE;
		sdl->button_pushed = WALL_PUSH;
		printf("Wall\n");
	}
	else if (sdl->type_pressed == PLAYER_TYPE || sdl->type_pressed == SPRITE_TYPE)
		make_player_or_sprite(sdl);
}

void	big_loop(t_sdl *sdl)
{
	while (1)
	{
		if (SDL_PollEvent(&sdl->window_event))
		{
			if (SDL_QUIT ==	sdl->window_event.type)
				exit(0);
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_ESCAPE ==
					sdl->window_event.key.keysym.sym)
				exit(0);
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_BACKSPACE ==
					sdl->window_event.key.keysym.sym)
				delete_last_command(sdl);
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_r ==
					sdl->window_event.key.keysym.sym)
				reset(&(sdl->sectors), sdl->player, sdl->sprites);

			// else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_w == // переписать по нормальму
			//  		sdl->window_event.key.keysym.sym)
			//  	sdl->type_pressed = WALL_TYPE;


			// else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_p == // переписать по нормальму
			//  		sdl->window_event.key.keysym.sym)

			// else if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
			// 		sdl->window_event.button.button == SDL_BUTTON_LEFT)
			// {
			// 	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
			// 	if ((sdl->mouse_position.x > BUTTON_PLAYER_X1 && sdl->mouse_position.x < BUTTON_PLAYER_X2) &&
			// 			(sdl->mouse_position.y > BUTTON_PLAYER_Y1 && sdl->mouse_position.y < BUTTON_PLAYER_Y2))
			// 	{
			// 		sdl->type_pressed = PLAYER_TYPE;
			// 		printf("Player");
			// 	}
			// }

			// else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_s ==
			// 		sdl->window_event.key.keysym.sym)
			// 	sdl->type_pressed = SPRITE_TYPE;

			else if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
					sdl->window_event.button.button == SDL_BUTTON_LEFT)
				clicks(sdl);
			draw(sdl);
		}
	}
}
