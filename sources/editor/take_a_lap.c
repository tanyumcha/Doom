/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_lap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:46:30 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/28 15:47:23 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	save_wall(t_sector *sector, int i)
{
	if (i > 0)//сохраняем стену, с момента проставления второй точки сектора
	{
		sector->walls[i - 1].x1 = sector->point[i - 1].x;
		sector->walls[i - 1].y1 = sector->point[i - 1].y;
		sector->walls[i - 1].x2 = sector->point[i].x;
		sector->walls[i - 1].y2 = sector->point[i].y;
		sector->walls[i - 1].wall_id = i - 1;
		sector->walls[i - 1].portal = -1;
		sector->num_of_walls = sector->walls[i - 1].wall_id + 1;
	}
}

void	add_point(t_sdl *sdl, t_sector **sector, int i)
{
	(*sector)->point[(*sector)->size].x = sdl->grid_field[i].x;
	(*sector)->point[(*sector)->size].y = sdl->grid_field[i].y;
	if ((*sector)->size > 0)
		save_wall((*sector), (*sector)->size);
	(*sector)->size++;
	add_command(sdl, &(sdl->commands), WALL_TYPE);
}

int		is_inside_sector(t_sdl *sdl, int x, int y)
{
	(void)sdl;
	(void)x;
	(void)y;
	return (0);
}

void	check_wall(t_walls *walls, t_sector *sector, t_point *grid_field)
{
	walls->x1 = sector->point[sector->size - 2].x;//Дима, проверь, плз!
	walls->y1 = sector->point[sector->size - 2].y;
	walls->x2 = sector->point[sector->size - 1].x;
	walls->y2 = sector->point[sector->size - 1].y;
	walls->neighbour_x1 = grid_field->x;
	walls->neighbour_y1 = grid_field->y;
}

int		check_point(t_sector *head, t_sector *sector, int x, int y)
{
	int	i;

	while (head != NULL)
	{
		i = 0;
		while (i < head->size)
		{
			if (sector->num_of_sector != head->num_of_sector)
			{
				if (head->point[i].x == x && head->point[i].y == y)
					return (1);
			}
			i++;
		}
		head = head->next;
	}
	return (0);
}

void	make_wall(t_sdl *sdl)
{
	int			i;
	t_sector	*sector;
	t_walls		*walls;

	walls = (t_walls *)malloc(sizeof(t_walls));
	sector = get_last_sector(sdl->sectors);
	if (sector == NULL)
	{
		sdl->sectors = init_sector();
		sector = sdl->sectors;
	}
	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
	// if (sdl->mouse_position.x < SIZE_WIN_X * 0.8)//видимо нет необходимости, так как точки можем ставить только в грид
	// {
	if ((i = check_the_grid(sdl->grid_field, sdl->mouse_position.x,
							sdl->mouse_position.y)) >= 0)
	{
		if (sector->size > 1)
		{
			check_wall(walls, sector, &sdl->grid_field[i]);//Дима, проверь, плз!
			// walls->x1 = sector->point[sector->size - 2].x;
			// walls->y1 = sector->point[sector->size - 2].y;
			// walls->x2 = sector->point[sector->size - 1].x;
			// walls->y2 = sector->point[sector->size - 1].y;
			// walls->neighbour_x1 = sdl->grid_field[i].x;
			// walls->neighbour_y1 = sdl->grid_field[i].y;
		}
		// if (is_inside_sector(sdl, sector->num_of_sector, sdl->grid_field[i].x,
		// 					sdl->grid_field[i].y) == 0)
		// if (check_sect_intersects(sdl, sector->num_of_sector, sdl->grid_field[i].x, sdl->grid_field[i].y) % 2 == 0)
		if (check_intersection(sdl, sdl->sectors, sdl->grid_field[i].x, sdl->grid_field[i].y) % 2 == 0 ||
				((check_intersection(sdl, sdl->sectors, sdl->grid_field[i].x, sdl->grid_field[i].y) % 2 == 1 &&
				check_point(sdl->sectors, sector, sdl->grid_field[i].x, sdl->grid_field[i].y) == 1) //&&
				// check_sect_intersects(tsdl->sectors, sector, walls) == 0)) //ДОПИСАТЬ!!!
			which_of_points(sdl, sector, walls, i);
	// }
	}
	free(walls);
}
