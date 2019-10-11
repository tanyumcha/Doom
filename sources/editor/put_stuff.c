/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:16:02 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/11 14:09:58 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	set_sprite(t_sdl *sdl, t_sector *head, t_point *grid_field, t_sector **stuffbox, int i)
{
	(*stuffbox)->point[(*stuffbox)->size].x = grid_field[i].x;
	(*stuffbox)->point[(*stuffbox)->size].y = grid_field[i].y;
	printf("Sprite is available\n");
	draw(sdl, head, grid_field);
	(*stuffbox)->size++;
}

void	set_player(t_sdl *sdl, t_sector *head, t_point *grid_field, t_sector **stuffbox, int i)
{
	(*stuffbox)->point[1].x = grid_field[i].x;
	(*stuffbox)->point[1].y = grid_field[i].y;
	printf("Player is available\n");
	draw(sdl, head, grid_field);
	(*stuffbox)->size++;
}

void	set_stuff(t_sdl *sdl, t_sector *head, t_point *grid_field, t_sector **stuffbox)
{
	int i;

	i = 0;
	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
	if ((i = check_the_grid(grid_field, sdl->mouse_position.x, sdl->mouse_position.y)) >= 0)
	{
		printf("i = %d\n", i); // не выводится
		if ((*stuffbox)->size == 0 && (*stuffbox)->type_of_point == 1)
			set_player(sdl, head, grid_field, stuffbox, i);
		else if ((*stuffbox)->size > 1)// size 1 is always a player
		{
			if ((*stuffbox)->type_of_point == 2)
				set_sprite(sdl, head, grid_field, stuffbox, i);
		}
	}
}

void	pick_sprite(t_sector **stuffbox)
{
	(*stuffbox)->size = 1;
	(*stuffbox)->type_of_point = 2;
}

void	pick_player(t_sector **stuffbox)
{
	(*stuffbox)->size = 0;
	(*stuffbox)->num_of_sector = -1; // distinct sector for stuff
	(*stuffbox)->type_of_point = 1;
}

void	choose_type_of_point(t_sector **stuffbox, int type)
{
	if (type == 1)
		pick_player(stuffbox);
	if (type == 2)
		pick_sprite(stuffbox);
}
