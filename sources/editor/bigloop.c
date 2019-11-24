/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigloop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:26:54 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/24 15:03:19 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	clicks2(t_sdl *sdl)
{
	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
	if ((sdl->mouse_position.x > BUTTON_ARMOR_X1 &&
			sdl->mouse_position.x < BUTTON_ARMOR_X2) &&
			(sdl->mouse_position.y > BUTTON_ARMOR_Y1 &&
			sdl->mouse_position.y < BUTTON_ARMOR_Y2))
	{
		sdl->type_pressed = SPRITE_TYPE;
		sdl->button_pushed = ARMOR_PUSH;
		printf("Armor\n");
	}
	else if ((sdl->mouse_position.x > BUTTON_POWER_UP_X1 &&
			sdl->mouse_position.x < BUTTON_POWER_UP_X2) &&
			(sdl->mouse_position.y > BUTTON_POWER_UP_Y1 &&
			sdl->mouse_position.y < BUTTON_POWER_UP_Y2))
	{
		sdl->type_pressed = SPRITE_TYPE;
		sdl->button_pushed = POWER_UP_PUSH;
		printf("Power up\n");
	}
	else
		clicks3(sdl);
}

void	clicks1(t_sdl *sdl)
{
	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
	if ((sdl->mouse_position.x > BUTTON_PLAYER_X1 &&
			sdl->mouse_position.x < BUTTON_PLAYER_X2) &&
			(sdl->mouse_position.y > BUTTON_PLAYER_Y1 &&
			sdl->mouse_position.y < BUTTON_PLAYER_Y2))
	{
		sdl->type_pressed = PLAYER_TYPE;
		sdl->button_pushed = PLAYER_PUSH;
		printf("Player\n");
	}
	else if ((sdl->mouse_position.x > BUTTON_MEDKIT_X1 &&
			sdl->mouse_position.x < BUTTON_MEDKIT_X2) &&
			(sdl->mouse_position.y > BUTTON_MEDKIT_Y1 &&
			sdl->mouse_position.y < BUTTON_MEDKIT_Y2))
	{
		sdl->type_pressed = SPRITE_TYPE;
		sdl->button_pushed = MEDKIT_PUSH;
		printf("Medkit\n");
	}
	else
		clicks2(sdl);
}

void	clicks0(t_sdl *sdl)
{
	if (sdl->button_pushed == WALL_PUSH)
		make_wall(sdl);
	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
	if ((sdl->mouse_position.x > BUTTON_WALL_X1 &&
			sdl->mouse_position.x < BUTTON_WALL_X2) &&
			(sdl->mouse_position.y > BUTTON_WALL_Y1 &&
			sdl->mouse_position.y < BUTTON_WALL_Y2))
	{
		sdl->type_pressed = WALL_TYPE;
		sdl->button_pushed = WALL_PUSH;
		printf("Wall\n");
	}
	else
		clicks1(sdl);
	if (sdl->type_pressed == PLAYER_TYPE || sdl->type_pressed == SPRITE_TYPE)
		make_player_or_sprite(sdl);
}

void	textinput(t_sdl *sdl)
{
	if (sdl->map_name->text_size + 1 < sdl->map_name->max_text_size)
	{
		ft_strcat(sdl->map_name->text, sdl->window_event.text.text);
		sdl->map_name->text_size++;
	}
}

void	delete_one_symbol(t_sdl *sdl)
{
	if (sdl->map_name->text_size > 0)
	{
		sdl->map_name->text_size--;
		sdl->map_name->text[sdl->map_name->text_size] = '\0';
	}
}

void	big_loop(t_sdl *sdl)
{
	while (1)
	{
		if (SDL_PollEvent(&sdl->window_event))
		{
			if (SDL_QUIT == sdl->window_event.type)
				exit(0);
			else if (bigscarycondition(sdl) == 1)
				save_click(sdl);
			else if (sdl->window_event.type == SDL_KEYDOWN && sdl->is_input == 1 && SDLK_BACKSPACE ==
					sdl->window_event.key.keysym.sym)
				delete_one_symbol(sdl);
			else if (sdl->window_event.type == SDL_TEXTINPUT && sdl->is_input == 1)
				textinput(sdl);
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_ESCAPE ==
					sdl->window_event.key.keysym.sym)
				exit(0);
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_BACKSPACE ==
					sdl->window_event.key.keysym.sym && sdl->is_input == 0)
				delete_last_command(sdl);
			else if (sdl->window_event.type == SDL_KEYDOWN && SDLK_DELETE ==
					sdl->window_event.key.keysym.sym)
				reset(sdl);//, &(sdl->sectors), sdl->player, sdl->sprites);
			else if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
					sdl->window_event.button.button == SDL_BUTTON_LEFT)
			{
				sdl->is_input = 0;
				clicks0(sdl);
			}
			draw(sdl);
		}
	}
}
