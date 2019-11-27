/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_touch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:49:10 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/27 12:46:38 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** (x1, y1, x2, y2, x3, y3)
** (x1, y1, x2, y2, x4, y4)
** (x3, y3, x4, y4, x1, y1)
** (x3, y3, x4, y4, x2, y2)
**
** int x1 = cur_wall->x1;
** int y1 = cur_wall->y1;
** int x2 = cur_wall->x2;
** int y2 = cur_wall->y2;
** int x3 = cur_wall->neighbour_x1 = head->point[j].x;
** int y3 = cur_wall->neighbour_y1 = head->point[j - 1].y;
** int x4 = cur_wall->neighbour_x2 = head->point[j].x;
** int y4 = cur_wall->neighbour_y2 = head->point[j].y;
*/

void	check_the_touch(t_sector *cur_sector, int num, t_sector *head)
{
	int	j;

	while (head != NULL)
	{
		j = 1;
		while (j < head->size)
		{
			if (cur_sector->num_of_sector != head->num_of_sector)
			{
				if ((((cur_sector->walls[num].x1 == head->point[j - 1].x &&
						cur_sector->walls[num].y1 == head->point[j - 1].y) &&
						(cur_sector->walls[num].x2 == head->point[j].x &&
						cur_sector->walls[num].y2 == head->point[j].y)) ||
						((cur_sector->walls[num].x1 = head->point[j].x &&
						cur_sector->walls[num].y1 == head->point[j].y) &&
						(cur_sector->walls[num].x2 == head->point[j - 1].x &&
						cur_sector->walls[num].y2 == head->point[j - 1].y))))
					cur_sector->walls[num].portal = head->num_of_sector;
			}
			j++;
		}
		head = head->next;
	}
}

void	find_portals(t_sdl *sdl)
{
	t_sector	*cur_sector;
	t_sector	*head;
	int			i;

	cur_sector = sdl->sectors;
	head = sdl->sectors;
	while (cur_sector->next != NULL)
	{
		i = 0;
		while (i < cur_sector->num_of_walls)
		{
			check_the_touch(cur_sector, i, head);
			i++;
		}
		cur_sector = cur_sector->next;
	}
}
