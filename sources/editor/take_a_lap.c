/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_lap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:46:30 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/09 16:58:06 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		check_intersect(t_sector *head, int x1, int y1, int x2, int y2)
{
	int i;

	while (head != NULL)
	{
		i = 0;
		while (i + 1 < head->size)
			{
				printf("%d: otr1: %d %d - %d %d, otr2: %d %d - %d %d\n", i, x1, y1, x2, y2, head->point[i].x, head->point[i].y, head->point[i + 1].x,  head->point[i + 1].y);
				double common = (x2 - x1)*(head->point[i].y - head->point[i + 1].y) - (y2 - y1)*(head->point[i].x - head->point[i + 1].x);
				// if (common == 0)
				// {
				// 	i++;
				// 	continue ;
				// }
				double rH = (y1 - head->point[i + 1].y)*(head->point[i].x - head->point[i + 1].x) - (x1 - head->point[i + 1].x)*(head->point[i].y - head->point[i + 1].y);
				double sH = (y1 - head->point[i + 1].y)*(x2 - x1) - (x1 - head->point[i + 1].x)*(y2 - y1);
				printf("------------------\n");
				printf("%f %f\n", rH / common, sH / common);
				printf("%d\n", (x1 == head->point[0].x && y1 == head->point[0].y));
				if ((common == 0) ||
						((rH / common >= 0 && rH / common <= 1 && sH / common >= 0 && sH / common <= 1) && (x1 == head->point[i + 1].x && y1 == head->point[i + 1].y)) ||
						((rH / common == 1 && sH / common == 1) && ((x1 != head->point[i + 1].x && y1 != head->point[i + 1].y) && (x2 == head->point[0].x && y2 == head->point[0].y))))
				{
					i++;
					continue ;
				}
				else if (rH / common >= 0 && rH / common <= 1 && sH / common >= 0 && sH / common <= 1)
					return (1);
				i++;
			}
		head = head->next;
	}
	return (0);
}

void	last_point(t_sdl *sdl, t_sector *head, t_point *grid_field, t_sector **sector, int i)
{
	if (check_intersect(head, (*sector)->point[(*sector)->size - 1].x, (*sector)->point[(*sector)->size - 1].y, grid_field[i].x, grid_field[i].y) == 0)
	{
		// (*sector)->point[(*sector)->size].x = (*sector)->point[0].x;
		// (*sector)->point[(*sector)->size].y = (*sector)->point[0].y;
		(*sector)->point[(*sector)->size].x = grid_field[i].x;
		(*sector)->point[(*sector)->size].y = grid_field[i].y;
		draw(sdl, head, grid_field);
		(*sector)->next = init_sector();
		(*sector) = (*sector)->next;
		printf("SAVE\n");
	//	save_the_sector(sector->point);
		(*sector)->size = 0;
	}
}

int		check_the_touch(t_sector *head, t_sector **sector, int x, int y)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		while (i <= head->size)
			{
				if (x >= head->point[i].x - POINT_SIZE / 2 &&
						x <= head->point[i].x + POINT_SIZE / 2 &&
						y >= head->point[i].y - POINT_SIZE / 2 &&
						y <= head->point[i].y + POINT_SIZE / 2)
				{
					(*sector)->point[0].x = head->point[i].x;
					(*sector)->point[0].y = head->point[i].y;
					printf("touch i = %d\n", i);
					return (1);
				}
				i++;
			}
		head = head->next;
	}
	return (0);
}

void	middle_points(t_sdl *sdl, t_sector *head, t_point *grid_field, t_sector **sector, int i)
{
	if ((*sector)->size > 0)
	{
		if (check_intersect(head, (*sector)->point[(*sector)->size - 1].x, (*sector)->point[(*sector)->size - 1].y, grid_field[i].x, grid_field[i].y) == 0)
		{
			(*sector)->point[(*sector)->size].x = grid_field[i].x;
			(*sector)->point[(*sector)->size].y = grid_field[i].y;
			draw(sdl, head, grid_field);
			(*sector)->size++;
		}
	}
	else
	{
		(*sector)->point[(*sector)->size].x = grid_field[i].x;
		(*sector)->point[(*sector)->size].y = grid_field[i].y;
		draw(sdl, head, grid_field);
		(*sector)->size++;
	}
}

void	take_a_lap(t_sdl *sdl, t_point *grid_field, t_sector *head, t_sector **sector)
{
	int i;

	i = 0;
	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
//	SDL_Log("Mouse position: x=%i y=%i", sdl->mouse_position.x, sdl->mouse_position.y);
	if ((*sector)->size > 2 && ((sdl->mouse_position.x >= (*sector)->point[0].x - POINT_SIZE / 2 &&
			sdl->mouse_position.x <= (*sector)->point[0].x + POINT_SIZE / 2) &&
			(sdl->mouse_position.y >= (*sector)->point[0].y - POINT_SIZE / 2 &&
			sdl->mouse_position.y <= (*sector)->point[0].y + POINT_SIZE / 2)))
	// if ((*sector)->size > 2 && (i = check_the_grid(grid_field, sdl->mouse_position.x, sdl->mouse_position.y)) >= 0)
	{
		if ((i = check_the_grid(grid_field, sdl->mouse_position.x, sdl->mouse_position.y)) >= 0)
		{
	// 		(*sector)->point[(*sector)->size].x = (*sector)->point[0].x;
	// 		(*sector)->point[(*sector)->size].y = (*sector)->point[0].y;
	// 		draw(sdl, head, grid_field);
	// 		(*sector)->next = init_sector();
	// 		(*sector) = (*sector)->next;
	// 		printf("SAVE\n");
	// //		save_the_sector(sector->point);
	// 		(*sector)->size = 0;
			// if (check_intersect(head, (*sector)->point[(*sector)->size - 1].x, (*sector)->point[(*sector)->size - 1].y, grid_field[i].x, grid_field[i].y) == 0)
				last_point(sdl, head, grid_field, sector, i);
		}
	}
	else if (sdl->mouse_position.x < (int)(SIZE_WIN_X * 0.8))
	{
		if ((i = check_the_grid(grid_field, sdl->mouse_position.x, sdl->mouse_position.y)) >= 0)
		{
			// (*sector)->point[(*sector)->size].x = grid_field[i].x;
			// (*sector)->point[(*sector)->size].y = grid_field[i].y;
			// draw(sdl, head, grid_field);
			// (*sector)->size++;
			middle_points(sdl, head, grid_field, sector, i);
		}
	}
}
