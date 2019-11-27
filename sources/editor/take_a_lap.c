/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_lap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:46:30 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/24 17:25:26 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

// t_walls	*find_last_wall(t_walls *wall)
// {
// 	if (wall == NULL)
// 		return (NULL);
// 	while (wall->next != NULL)
// 		wall = wall->next;
// 	return (wall);
// }

void	save_wall(t_sector *sector, int i)
// void	save_wall(t_sector *head, t_sector *sector, int i)
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

		// printf("x1 = %d\n", cur_wall->x1);
		// printf("y1 = %d\n", cur_wall->y1);
		// printf("x2 = %d\n", cur_wall->x2);
		// printf("y2 = %d\n", cur_wall->y2);
		// printf("wall id = %d\n", cur_wall->wall_id);
		// if (sector->num_of_sector > 0)
		// 	check_the_touch(&sector->walls[i - 1], head);// проверка начинается со второй точки второго сектора
	}
}

void	add_point(t_sdl *sdl, t_sector **sector, int i)
{
	(*sector)->point[(*sector)->size].x = sdl->grid_field[i].x;
	(*sector)->point[(*sector)->size].y = sdl->grid_field[i].y;
	if ((*sector)->size > 0)
		save_wall((*sector), (*sector)->size);//сохраняем стену
		// save_wall(sdl->sectors, (*sector), (*sector)->size);//сохраняем стену
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
	int			j;
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
					add_point(sdl, &sector, i);
				else if (sector->size > 0 && dot_in_used(sector, sdl->grid_field[i].x, sdl->grid_field[i].y) == 0 && check_local_intersection(sdl, sector, walls) < 2) // для всех, кроме первой и последней точки
				{

					if (sector->size > 1)
					{
						if (is_clockwise(walls))
						{
							cut_the_rope(sdl, sector, i); //ДЕЛЕНИЕ НА ОТРЕЗКИ
							add_point(sdl, &sector, i);
						}
					}
					else
					{
						cut_the_rope(sdl, sector, i); //ДЕЛЕНИЕ НА ОТРЕЗКИ
						add_point(sdl, &sector, i);
					}
				}
				else if (sector->size > 2 && ((sdl->mouse_position.x >= sector->point[0].x - POINT_SIZE / 2 && //Для последней точки
						sdl->mouse_position.x <= sector->point[0].x + POINT_SIZE / 2) &&
						(sdl->mouse_position.y >= sector->point[0].y - POINT_SIZE / 2 &&
						sdl->mouse_position.y <= sector->point[0].y + POINT_SIZE / 2)))
				{
					if (check_local_intersection(sdl, sector, walls) < 3 && is_clockwise(walls))
					{
						cut_the_rope(sdl, sector, i); //ДЕЛЕНИЕ НА ОТРЕЗКИ
						add_point(sdl, &sector, i);
						j = 0;
						while (j < sector->size)
						{
							// printf("x = (%d; %d)\n", sector->point[j].x, sector->point[j].y);
							printf("wall[%d]_point1 = (%d; %d)\n", j, sector->walls[j].x1, sector->walls[j].y1);
							printf("wall[%d]_point2 = (%d; %d)\n", j, sector->walls[j].x2, sector->walls[j].y2);
							j++;
						}
						sector->num_of_sector = sdl->count;
						sector->next = init_sector();
						sector = sector->next;
						sdl->count++;
						printf("SAVE\n");
					}
				}
			}
		}
	}
}
