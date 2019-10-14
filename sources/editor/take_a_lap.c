/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_lap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:46:30 by eharrag-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/11 13:13:02 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

// int		check_intersect(t_sector *head, int x1, int y1, int x2, int y2)
// {
// 	int i;

// 	while (head != NULL)
// 	{
// 		i = 0;
// 		while (i + 1 < head->size)
// 			{
// 				printf("%d: otr1: %d %d - %d %d, otr2: %d %d - %d %d\n", i, x1, y1, x2, y2, head->point[i].x, head->point[i].y, head->point[i + 1].x,  head->point[i + 1].y);
// 				double common = (x2 - x1)*(head->point[i].y - head->point[i + 1].y) - (y2 - y1)*(head->point[i].x - head->point[i + 1].x);
// 				// if (common == 0)
// 				// {
// 				// 	i++;
// 				// 	continue ;
// 				// }
// 				double rH = (y1 - head->point[i + 1].y)*(head->point[i].x - head->point[i + 1].x) - (x1 - head->point[i + 1].x)*(head->point[i].y - head->point[i + 1].y);
// 				double sH = (y1 - head->point[i + 1].y)*(x2 - x1) - (x1 - head->point[i + 1].x)*(y2 - y1);
// 				if ((common == 0) ||
// 						((rH / common >= 0 && rH / common <= 1 && sH / common >= 0 && sH / common <= 1) && (x1 == head->point[i + 1].x && y1 == head->point[i + 1].y)) ||
// 						((rH / common == 1 && sH / common == 1) && (x2 == head->point[0].x && y2 == head->point[0].y) && (x1 == head->point[head->size - 1].x && y1 == head->point[head->size - 1].y)))
// 				{
// 					i++;
// 					continue ;
// 				}
// 				else if (rH / common >= 0 && rH / common <= 1 && sH / common >= 0 && sH / common <= 1)
// 					return (1);
// 				i++;
// 			}
// 		head = head->next;
// 	}
// 	return (0);
// }

int		check_first_touch(t_sector *head, t_sector *sector, int x, int y)
{
	int i;

	printf("cft\n");
	while (head->next != NULL)
	{
		i = 0;
		while (i < head->size)
		{
			if (head->point[i].x == x && head->point[i].y == y)
			{
				sector->contact_sector_id = head->id;
				sector->count_contact = 1;
				return (1);
			}
			i++;
		}
		head = head->next;
	}
	return (0);
	// int i;

	// i = 0;
	// while (head != NULL)
	// {
	// 	while (i <= head->size)
	// 		{
	// 			if (x >= head->point[i].x - POINT_SIZE / 2 &&
	// 					x <= head->point[i].x + POINT_SIZE / 2 &&
	// 					y >= head->point[i].y - POINT_SIZE / 2 &&
	// 					y <= head->point[i].y + POINT_SIZE / 2)
	// 			{
	// 				(*sector)->point[0].x = head->point[i].x;
	// 				(*sector)->point[0].y = head->point[i].y;
	// 				printf("touch i = %d\n", i);
	// 				return (1);
	// 			}
	// 			i++;
	// 		}
	// 	head = head->next;
	// }
	// return (0);
}

void	add_point(t_point *grid_field, t_sector **sector, int i)
{
<<<<<<< HEAD
		// if (check_intersect(head, (*sector)->point[(*sector)->size - 1].x, (*sector)->point[(*sector)->size - 1].y, grid_field[i].x, grid_field[i].y) == 0)
		// {
	(*sector)->point[(*sector)->size].x = grid_field[i].x;
	(*sector)->point[(*sector)->size].y = grid_field[i].y;
	(*sector)->size++;
		//}
=======
	// if (check_intersect(head, (*sector)->point[(*sector)->size - 1].x, (*sector)->point[(*sector)->size - 1].y, grid_field[i].x, grid_field[i].y) == 0)
	// {
		(*sector)->point[(*sector)->size].x = grid_field[i].x;
		(*sector)->point[(*sector)->size].y = grid_field[i].y;
		draw(sdl, head, grid_field);
		(*sector)->next = init_sector();
		(*sector) = (*sector)->next;
		(*sector)->num_of_sector++;
		printf("SAVE\n");
	//	save_the_sector(sector->point);
		(*sector)->size = 0;
	// }
>>>>>>> 725e4d1643fc5941c3cf78feafca59c5b30be3d0
}

int	dot_in_used(t_sector *sector, int x, int y)
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

int		check_id_contact_sector(t_sector *head, int x, int y, int id_check)
{
<<<<<<< HEAD
	int i;

	while (head->next != NULL)
	{
		i = 0;
		while (i < head->size)
		{
			if (head->point[i].x == x && head->point[i].y == y)
			{
				printf("%d %d\n", head->id, id_check);
				if (head->id == id_check)
					return (1);
			}
			i++;
		}
		head = head->next;
	}
	return (0);
=======
	// if ((*sector)->size > 0)
	// {
	// 	if (check_intersect(head, (*sector)->point[(*sector)->size - 1].x, (*sector)->point[(*sector)->size - 1].y, grid_field[i].x, grid_field[i].y) == 0)
	// 	{
	// 		(*sector)->point[(*sector)->size].x = grid_field[i].x;
	// 		(*sector)->point[(*sector)->size].y = grid_field[i].y;
	// 		draw(sdl, head, grid_field);
	// 		(*sector)->size++;
	// 	}
	// }
	// else
	// {
		(*sector)->point[(*sector)->size].x = grid_field[i].x;
		(*sector)->point[(*sector)->size].y = grid_field[i].y;
		draw(sdl, head, grid_field);
		(*sector)->size++;
	// }
>>>>>>> 725e4d1643fc5941c3cf78feafca59c5b30be3d0
}

void	take_a_lap(t_sdl *sdl, t_point *grid_field, t_sector *head, t_sector **sector)
{
	int i;

	i = 0;
	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
	if (sdl->mouse_position.x < (int)(SIZE_WIN_X * 0.8))
	{
		if ((i = check_the_grid(grid_field, sdl->mouse_position.x, sdl->mouse_position.y)) >= 0)
		{
<<<<<<< HEAD
			printf("sector size: %d\n", (*sector)->size);
			if ((*sector)->size == 0 && ((sdl->sect_count > 0 && check_first_touch(head, *sector, grid_field[i].x, grid_field[i].y) == 1) || sdl->sect_count == 0)) // для первой точки
			{
				printf("in\n");
				add_point(grid_field, sector, i);
				draw(sdl, head, grid_field);
				printf("touch\n");
			}
			else if ((*sector)->size > 0 && dot_in_used(*sector, grid_field[i].x, grid_field[i].y) == 0) // для всех, кроме первой и последней точки
			{
				if (sdl->sect_count > 0)
				{
					if (check_id_contact_sector(head, grid_field[i].x, grid_field[i].y, (*sector)->contact_sector_id) == 1)
					{
						printf("CONTACT!\n");
						add_point(grid_field, sector, i);
						(*sector)->count_contact++;
					}
					else if ((*sector)->count_contact >= 2)
					{
						add_point(grid_field, sector, i);
					}
				}
				else
					add_point(grid_field, sector, i);
				draw(sdl, head, grid_field);
			}
			else if ((*sector)->size > 2 && ((sdl->mouse_position.x >= (*sector)->point[0].x - POINT_SIZE / 2 && //Для последней точки
				sdl->mouse_position.x <= (*sector)->point[0].x + POINT_SIZE / 2) &&
				(sdl->mouse_position.y >= (*sector)->point[0].y - POINT_SIZE / 2 &&
				sdl->mouse_position.y <= (*sector)->point[0].y + POINT_SIZE / 2)))
			{
				add_point(grid_field, sector, i);
				draw(sdl, head, grid_field);
				(*sector)->next = init_sector(++sdl->sect_count);
				(*sector) = (*sector)->next;
				printf("SAVE\n");
				(*sector)->size = 0;
				
			}
=======
			// if (sect_num > 0 && check_the_touch(head, sector, sdl->mouse_position.x, sdl->mouse_position.y) == 1)
			// 	{
			// 		printf("in\n");
			// 		(*sector)->point[(*sector)->size].x = sdl->mouse_position.x;
			// 		(*sector)->point[(*sector)->size].y = sdl->mouse_position.y;
			// 		draw(sdl, head, grid_field);
			// 		(*sector)->size++;
			// 		printf("touch\n");
			// 	}
			// else if (sect_num < 0 || (sect_num > -1 && (*sector)->size > 2)) // для первого сектора и следующей точки после двух касаний
			// // (*sector)->point[(*sector)->size].x = grid_field[i].x;
			// // (*sector)->point[(*sector)->size].y = grid_field[i].y;
			// // draw(sdl, head, grid_field);
			// // (*sector)->size++;
				middle_points(sdl, head, grid_field, sector, i);
>>>>>>> 725e4d1643fc5941c3cf78feafca59c5b30be3d0
		}
	}
}
