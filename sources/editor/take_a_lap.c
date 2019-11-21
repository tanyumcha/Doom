/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_lap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:46:30 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/21 15:37:41 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	add_point(t_sdl *sdl, t_sector **sector, int i)
{
	(*sector)->point[(*sector)->size].x = sdl->grid_field[i].x;
	(*sector)->point[(*sector)->size].y = sdl->grid_field[i].y;
	(*sector)->size++;
	if ((*sector)->num_of_sector > 0 && (*sector)->size > 0)// проверка начинается со второй точки второго сектора
		check_the_touch(sdl->sectors, (*sector), i);
	add_command(sdl, &(sdl->commands), WALL_TYPE);
}

int		dot_in_used(t_sector *sector, int x, int y)
{
	int i;

	i = 0;
	while (i < sector->size)
	{
		if (sector->point[i].x == x && sector->point[i].y == y)
			return (1);
		i++;
	}
	return (0);
}

void	make_wall(t_sdl *sdl)
{
	int			i;
	t_sector	*sector;

	sector = get_last_sector(sdl->sectors);
	if (sector == NULL)
	{
		sdl->sectors = init_sector();
		sector = sdl->sectors;
	}
	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
	if (sdl->mouse_position.x < (int)(SIZE_WIN_X * 0.8))
	{
		if ((i = check_the_grid(sdl->grid_field, sdl->mouse_position.x, sdl->mouse_position.y)) >= 0)
		{
			if (sector->size == 0) // для первой точки
			{
				add_point(sdl, &sector, i);
				sdl->count++;
				sector->num_of_sector = sdl->count;
			}
			else if (sector->size > 0 && dot_in_used(sector, sdl->grid_field[i].x, sdl->grid_field[i].y) == 0) // для всех, кроме первой и последней точки
				add_point(sdl, &sector, i);
			else if (sector->size > 2 && ((sdl->mouse_position.x >= sector->point[0].x - POINT_SIZE / 2 && //Для последней точки
					sdl->mouse_position.x <= sector->point[0].x + POINT_SIZE / 2) &&
					(sdl->mouse_position.y >= sector->point[0].y - POINT_SIZE / 2 &&
					sdl->mouse_position.y <= sector->point[0].y + POINT_SIZE / 2)))
			{
				add_point(sdl, &sector, i);
//				sector->num_of_sector = sdl->count;
				// printf("Portal is: %d", sector->neighbour);
				sector->next = init_sector();
				sector = sector->next;
//				sdl->count++;
				printf("SAVE\n");
			}
		}
	}
}
