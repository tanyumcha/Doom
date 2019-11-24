/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_lap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:46:30 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/24 16:23:35 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_walls	*find_last_wall(t_walls *wall)
{
	if (wall == NULL)
		return (NULL);
	while (wall->next != NULL)
		wall = wall->next;
	return (wall);
}

void	save_wall(t_sdl *sdl, t_walls *walls, t_sector *sector, int i)
{
	t_walls	*cur_wall;

	cur_wall = find_last_wall(walls);
	if (i > 0)//сохраняем стену, с момента проставления второй точки сектора
	{
		if (cur_wall == NULL)
		{
			walls = init_wall();
			cur_wall = walls;
		}
		else
		{
			cur_wall->next = init_wall();
			cur_wall = cur_wall->next;
		}
		cur_wall->x1 = sector->point[i - 1].x;
		cur_wall->y1 = sector->point[i - 1].y;
		cur_wall->x2 = sector->point[i].x;
		cur_wall->y2 = sector->point[i].y;
		cur_wall->wall_id = i - 1;

		// printf("x1 = %d\n", cur_wall->x1);
		// printf("y1 = %d\n", cur_wall->y1);
		// printf("x2 = %d\n", cur_wall->x2);
		// printf("y2 = %d\n", cur_wall->y2);
		// printf("wall id = %d\n", cur_wall->wall_id);
		if (sector->num_of_sector > 0)
			check_the_touch(cur_wall, sdl->sectors);// проверка начинается со второй точки второго сектора
	}
}

void	add_point(t_sdl *sdl, t_sector **sector, int i)
{
	(*sector)->point[(*sector)->size].x = sdl->grid_field[i].x;
	(*sector)->point[(*sector)->size].y = sdl->grid_field[i].y;
	if ((*sector)->size > 0)
	{
		save_wall(sdl, sdl->walls, (*sector), (*sector)->size);//сохраняем стену
		// if ((*sector)->num_of_sector > 0)
		// 	check_the_touch(sdl->sectors, (*sector), (*sector)->size);// проверка начинается со второй точки второго сектора
	}
	(*sector)->size++;
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

int		is_inside_sector(t_sdl *sdl, int x, int y)
{
	(void) sdl;
	(void) x;
	(void) y;
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
	if (sdl->mouse_position.x < (int)(SIZE_WIN_X * 0.8))
	{
		if ((i = check_the_grid(sdl->grid_field, sdl->mouse_position.x, sdl->mouse_position.y)) >= 0)
		{
			if (sector->size > 1)
			{
				walls->x1 = sector->point[sector->size - 2].x;
				walls->y1 = sector->point[sector->size - 2].y;
				walls->x2 = sector->point[sector->size - 1].x;
				walls->y2 = sector->point[sector->size - 1].y;
				walls->neighbour_x1 = sdl->grid_field[i].x;
				walls->neighbour_y1 = sdl->grid_field[i].y;
			}
			if (is_inside_sector(sdl, sdl->grid_field[i].x, sdl->grid_field[i].y) == 0)
			{
				if (sector->size == 0) // для первой точки
				{
					add_point(sdl, &sector, i);
					sdl->count++;
					sector->num_of_sector = sdl->count;
				}
				else if (sector->size > 0 && dot_in_used(sector, sdl->grid_field[i].x, sdl->grid_field[i].y) == 0 && check_local_intersection(sdl, sector, walls) < 2) // для всех, кроме первой и последней точки
				{
					if (sector->size > 1)
					{
						if (is_clockwise(walls))
							add_point(sdl, &sector, i);
					}
					else
						add_point(sdl, &sector, i);
				}
				else if (sector->size > 2 && ((sdl->mouse_position.x >= sector->point[0].x - POINT_SIZE / 2 && //Для последней точки
						sdl->mouse_position.x <= sector->point[0].x + POINT_SIZE / 2) &&
						(sdl->mouse_position.y >= sector->point[0].y - POINT_SIZE / 2 &&
						sdl->mouse_position.y <= sector->point[0].y + POINT_SIZE / 2)))
				{
					if (check_local_intersection(sdl, sector, walls) < 3)
					{
						sector->local_intersection = 0;
						add_point(sdl, &sector, i);
						// sector->num_of_sector = sdl->count;
						// printf("Portal is: %d", sector->neighbour);
						sector->next = init_sector();
						sector = sector->next;
						// sdl->count++;
						printf("SAVE\n");
					}
				}
			}
		}
	}
}
