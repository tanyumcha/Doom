/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_the_rope.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 11:43:08 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/24 17:33:37 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		get_conditional_by_status(status, j)
{
	if (status == 1)
	{
		if (j > 0)
			return (1);
		else
			return (0);
	}
	else if (status == 0)
	{
		if (j < GRID_SIZE)
			return (1);
		else
			return (0);
	}
	return (-1);
}

/*
 * x1 = sector->point[sector->size - 1].x;
 * y1 = sector->point[sector->size - 1].y;
 * x2 = sdl->grid_field[i].x;
 * y2 = sdl->grid_field[i].y;
 * check_x = sdl->grid_field[j].x;
 * check_y = sdl->grid_field[j].y;
 *
 * if ((check_x - x1) * (y2 - y1) - (check_y - y1) * (x2 - x1) == 0)
 * {
 * if (((check_x > x1 && check_x < x2) || (check_x < x1 && check_x > x2)) ||
 * ((check_y > y1 && check_y < y2) || (check_y < y1 && check_y > y2)))
 */

void	cut_the_rope(t_sdl *sdl, t_sector *sector, int i)
{
	int j;
	int status;

	if (sector->point[sector->size - 1].y > sdl->grid_field[i].y || sector->point[sector->size - 1].x > sdl->grid_field[i].x)
	{
		status = 1;
		j = GRID_SIZE;
	}
	else
	{
		status = 0;
		j = 0;
	}
	while (get_conditional_by_status(status, j))
	{
		if ((sdl->grid_field[j].x - sector->point[sector->size - 1].x) * (sdl->grid_field[i].y - sector->point[sector->size - 1].y) -
				(sdl->grid_field[j].y - sector->point[sector->size - 1].y) * (sdl->grid_field[i].x - sector->point[sector->size - 1].x) == 0)
		{
			// printf("I need your point\n");
			if (((sdl->grid_field[j].x > sector->point[sector->size - 1].x && sdl->grid_field[j].x < sdl->grid_field[i].x) ||
					(sdl->grid_field[j].x < sector->point[sector->size - 1].x && sdl->grid_field[j].x > sdl->grid_field[i].x)) ||
					((sdl->grid_field[j].y > sector->point[sector->size - 1].y && sdl->grid_field[j].y < sdl->grid_field[i].y) ||
					(sdl->grid_field[j].y < sector->point[sector->size - 1].y && sdl->grid_field[j].y > sdl->grid_field[i].y)))
				add_point(sdl, &sector, j);
		}
		j = status == 1 ? j - 1 : j + 1;
	}
}
