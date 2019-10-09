/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:04:11 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/09 17:03:04 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		check_the_grid(t_point *grid_field, int x, int y)
{
	int i;

	i = 0;
	while (i < GRID_SIZE)
	{
		if (x <= grid_field[i].x + POINT_SIZE / 2 && x >= grid_field[i].x - POINT_SIZE / 2 &&
				y <= grid_field[i].y + POINT_SIZE / 2 && y >= grid_field[i].y - POINT_SIZE / 2)
			return (i);
		i++;
	}
	return (-1);
}

void	save_the_grid(t_point *grid_field, int start_x, int start_y, int width, int height)
{
	int i;
	int x;
	int y;

	i = 0;
	y = start_y;
	while (i < GRID_SIZE)
	{
		while (y < start_y + height)
		{
			x = start_x;
			while (x < start_x + width)
			{
				grid_field[i].x = x;
				grid_field[i].y = y;
				x += STEP;
				i++;
			}
			y += STEP;
		}
	}
	// printf("i = %d\n", i);
	// printf("w = %d\n", width);
	// printf("h = %d\n", height);
	// printf("x = %d\n", grid_field[0].x);
	// printf("y = %d\n", grid_field[0].y);
	// printf("x = %d\n", grid_field[1].x);
	// printf("y = %d\n", grid_field[1].y);
	// printf("x = %d\n", grid_field[30].x);
	// printf("y = %d\n", grid_field[30].y);
	// printf("x = %d\n", grid_field[599].x);
	// printf("y = %d\n", grid_field[599].y);
}

void	init_grid(t_point *grid_field)
{
	SDL_Rect	grid;

	grid.x = 94;
	grid.y = 101;
	grid.w = (int)SIZE_WIN_X * 0.8 - grid.x * 2 + 1;
	grid.h = SIZE_WIN_Y - grid.y * 2 + 1;
	save_the_grid(grid_field, grid.x, grid.y, grid.w, grid.h);
}
