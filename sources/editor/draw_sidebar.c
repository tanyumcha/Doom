/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sidebar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:31:52 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/19 12:27:34 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	draw_text(t_sdl *sdl, char *text, SDL_Rect button, SDL_Color color)
{
	sdl->surface = TTF_RenderText_Solid(sdl->font, text, color);
	SDL_DestroyTexture(sdl->text);
	sdl->text = SDL_CreateTextureFromSurface(sdl->renderer,
											sdl->surface);
	SDL_FreeSurface(sdl->surface);
	SDL_RenderCopy(sdl->renderer, sdl->text, NULL, &button);
}

void	choose_color_of_button(t_sdl *sdl, int color)
{
	if (color == COLOR_PUSHED && sdl->button_pushed == PLAYER_PUSH)
		SDL_SetRenderDrawColor(sdl->renderer, 50, 205, 50, 100);
	else if (color == COLOR_PUSHED && sdl->button_pushed == MEDKIT_PUSH)
		SDL_SetRenderDrawColor(sdl->renderer, 255, 051, 051, 0);
	else if (color == COLOR_PUSHED && sdl->button_pushed == ARMOR_PUSH)
		SDL_SetRenderDrawColor(sdl->renderer, 051, 102, 153, 0);
	else if (color == COLOR_PUSHED && sdl->button_pushed == POWER_UP_PUSH)
		SDL_SetRenderDrawColor(sdl->renderer, 051, 102, 051, 0);
	else if (color == COLOR_PUSHED && sdl->button_pushed == RIFLE_AMMO_PUSH)
		SDL_SetRenderDrawColor(sdl->renderer, 204, 153, 000, 0);
	else if (color == COLOR_PUSHED && sdl->button_pushed == PLASMA_GUN_PUSH)
		SDL_SetRenderDrawColor(sdl->renderer, 255, 255, 000, 0);
	else if (color == COLOR_PUSHED && sdl->button_pushed == PLASMA_AMMO_PUSH)
		SDL_SetRenderDrawColor(sdl->renderer, 204, 255, 000, 0);
	else if (color == COLOR_PUSHED && sdl->button_pushed == BARREL_PUSH)
		SDL_SetRenderDrawColor(sdl->renderer, 102, 051, 000, 0);
	else if (color == COLOR_PUSHED && sdl->button_pushed == AFRIT_PUSH)
		SDL_SetRenderDrawColor(sdl->renderer, 204, 000, 000, 0);
	else if (color == COLOR_PUSHED && sdl->button_pushed == CACODEMON_PUSH)
		SDL_SetRenderDrawColor(sdl->renderer, 150, 000, 100, 0);
	else if (color == COLOR_PUSHED && sdl->button_pushed == IMP_PUSH)
		SDL_SetRenderDrawColor(sdl->renderer, 200, 100, 100, 0);
	else if (color == COLOR_PUSHED && sdl->button_pushed == WALL_PUSH)
		SDL_SetRenderDrawColor(sdl->renderer, 153, 204, 255, 0);
}

void	draw_button(t_sdl *sdl, SDL_Rect button, char *text, int color)
{
	SDL_Color	*color_text;

	choose_color_of_button(sdl, color);
	if (color == COLOR_UNPUSHED)
		SDL_SetRenderDrawColor(sdl->renderer, 025, 000, 051, 255);
	SDL_RenderFillRect(sdl->renderer, &button);
	color_text = create_sdl_color(204, 153, 255, 255);
	draw_text(sdl, text, button, *color_text);
	free(color_text);
}

void	draw_buttons_on_sidebar(t_sdl *sdl)
{
	SDL_Rect	*button;

	button = (SDL_Rect *)malloc(sizeof(SDL_Rect));

	button->x = BUTTON_PLAYER_X1;
	button->y = BUTTON_PLAYER_Y1;
	button->w = BUTTON_PLAYER_X2 - BUTTON_PLAYER_X1;
	button->h = BUTTON_PLAYER_Y2 - BUTTON_PLAYER_Y1;
	if (sdl->button_pushed == PLAYER_PUSH)
		draw_button(sdl, *button, " PLAYER", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " PLAYER", COLOR_UNPUSHED);

	button->x = BUTTON_MEDKIT_X1;
	button->y = BUTTON_MEDKIT_Y1;
	button->w = BUTTON_MEDKIT_X2 - BUTTON_MEDKIT_X1;
	button->h = BUTTON_MEDKIT_Y2 - BUTTON_MEDKIT_Y1;
	if (sdl->button_pushed == MEDKIT_PUSH)
		draw_button(sdl, *button, " SET A MEDKIT", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " SET A MEDKIT", COLOR_UNPUSHED);

	button->x = BUTTON_ARMOR_X1;
	button->y = BUTTON_ARMOR_Y1;
	button->w = BUTTON_ARMOR_X2 - BUTTON_ARMOR_X1;
	button->h = BUTTON_ARMOR_Y2 - BUTTON_ARMOR_Y1;
	if (sdl->button_pushed == ARMOR_PUSH)
		draw_button(sdl, *button, " SET AN ARMOR", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " SET AN ARMOR", COLOR_UNPUSHED);

	button->x = BUTTON_POWER_UP_X1;
	button->y = BUTTON_POWER_UP_Y1;
	button->w = BUTTON_POWER_UP_X2 - BUTTON_POWER_UP_X1;
	button->h = BUTTON_POWER_UP_Y2 - BUTTON_POWER_UP_Y1;
	if (sdl->button_pushed == POWER_UP_PUSH)
		draw_button(sdl, *button, " SET POWER UP", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " SET POWER UP", COLOR_UNPUSHED);

	button->x = BUTTON_RIFLE_AMMO_X1;
	button->y = BUTTON_RIFLE_AMMO_Y1;
	button->w = BUTTON_RIFLE_AMMO_X2 - BUTTON_RIFLE_AMMO_X1;
	button->h = BUTTON_RIFLE_AMMO_Y2 - BUTTON_RIFLE_AMMO_Y1;
	if (sdl->button_pushed == RIFLE_AMMO_PUSH)
		draw_button(sdl, *button, " SET RIFLE AMMO", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " SET RIFLE AMMO", COLOR_UNPUSHED);

	button->x = BUTTON_PLASMA_GUN_X1;
	button->y = BUTTON_PLASMA_GUN_Y1;
	button->w = BUTTON_PLASMA_GUN_X2 - BUTTON_PLASMA_GUN_X1;
	button->h = BUTTON_PLASMA_GUN_Y2 - BUTTON_PLASMA_GUN_Y1;
	if (sdl->button_pushed == PLASMA_GUN_PUSH)
		draw_button(sdl, *button, " SET PLASMA GUN", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " SET PLASMA GUN", COLOR_UNPUSHED);

	button->x = BUTTON_PLASMA_AMMO_X1;
	button->y = BUTTON_PLASMA_AMMO_Y1;
	button->w = BUTTON_PLASMA_AMMO_X2 - BUTTON_PLASMA_AMMO_X1;
	button->h = BUTTON_PLASMA_AMMO_Y2 - BUTTON_PLASMA_AMMO_Y1;
	if (sdl->button_pushed == PLASMA_AMMO_PUSH)
		draw_button(sdl, *button, " SET PLASMA AMMO", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " SET PLASMA AMMO", COLOR_UNPUSHED);

	button->x = BUTTON_BARREL_X1;
	button->y = BUTTON_BARREL_Y1;
	button->w = BUTTON_BARREL_X2 - BUTTON_BARREL_X1;
	button->h = BUTTON_BARREL_Y2 - BUTTON_BARREL_Y1;
	if (sdl->button_pushed == BARREL_PUSH)
		draw_button(sdl, *button, " SET BARREL", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " SET BARREL", COLOR_UNPUSHED);

	button->x = BUTTON_AFRIT_X1;
	button->y = BUTTON_AFRIT_Y1;
	button->w = BUTTON_AFRIT_X2 - BUTTON_AFRIT_X1;
	button->h = BUTTON_AFRIT_Y2 - BUTTON_AFRIT_Y1;
	if (sdl->button_pushed == AFRIT_PUSH)
		draw_button(sdl, *button, " SET AFRIT", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " SET AFRIT", COLOR_UNPUSHED);

	button->x = BUTTON_CACODEMON_X1;
	button->y = BUTTON_CACODEMON_Y1;
	button->w = BUTTON_CACODEMON_X2 - BUTTON_CACODEMON_X1;
	button->h = BUTTON_CACODEMON_Y2 - BUTTON_CACODEMON_Y1;
	if (sdl->button_pushed == CACODEMON_PUSH)
		draw_button(sdl, *button, " SET CACODEMON", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " SET CACODEMON", COLOR_UNPUSHED);

	button->x = BUTTON_IMP_X1;
	button->y = BUTTON_IMP_Y1;
	button->w = BUTTON_IMP_X2 - BUTTON_IMP_X1;
	button->h = BUTTON_IMP_Y2 - BUTTON_IMP_Y1;
	if (sdl->button_pushed == IMP_PUSH)
		draw_button(sdl, *button, " SET IMP", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " SET IMP", COLOR_UNPUSHED);

	button->x = BUTTON_WALL_X1;
	button->y = BUTTON_WALL_Y1;
	button->w = BUTTON_WALL_X2 - BUTTON_WALL_X1;
	button->h = BUTTON_WALL_Y2 - BUTTON_WALL_Y1;
	if (sdl->button_pushed == WALL_PUSH)
		draw_button(sdl, *button, " WALL", COLOR_PUSHED);
	else
		draw_button(sdl, *button, " WALL", COLOR_UNPUSHED);

	free(button);
}

void	draw_sidebar(t_sdl *sdl)
{
	SDL_Rect	sidebar;

	sidebar.x = SIZE_WIN_X * 0.8;
	sidebar.y = 0;
	sidebar.w = SIZE_WIN_X * 0.2;
	sidebar.h = SIZE_WIN_Y;
	SDL_SetRenderDrawColor(sdl->renderer, 20, 20, 40, 0);
	SDL_RenderFillRect(sdl->renderer, &sidebar);
	draw_buttons_on_sidebar(sdl);
}
