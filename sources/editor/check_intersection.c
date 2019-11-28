/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:55:28 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/28 15:47:30 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		count_intersection(t_sdl *sdl, t_sector *head, int count)
{
	count++;
	if (count % 2 == 1)
		sdl->sprite_in_sector = head->num_of_sector;
	printf("Count = %d\n", count);
	return (count);
}

void	find_intersection(t_sector *head, int i, int x2, int y2)
{
	head->rh = (YO - head->point[i + 1].y) *
			(head->point[i].x - head->point[i + 1].x) -
			(XO - head->point[i + 1].x) *
			(head->point[i].y - head->point[i + 1].y);
	head->sh = (YO - head->point[i + 1].y) * (x2 - XO) -
			(XO - head->point[i + 1].x) * (y2 - YO);
}

int		check_intersection(t_sdl *sdl, t_sector *head, int x2, int y2)
{
	int		i;
	int		count;

	count = 0;
	while (head != NULL)
	{
		i = 0;
		if (head->num_of_sector != -1)
		{
			while (i + 1 < head->size)
			{
				head->cmn = (x2 - XO) * (head->point[i].y - head->point[i + 1].y) -
						(y2 - YO) * (head->point[i].x - head->point[i + 1].x);
				if (head->cmn == 0)
				{
					i++;
					continue ;
				}
				find_intersection(head, i, x2, y2);
				if (head->rh / head->cmn >= 0 && head->rh / head->cmn <= 1 &&
						head->sh / head->cmn >= 0 && head->sh / head->cmn <= 1)
					count = count_intersection(sdl, head, count);
				i++;
			}
		}
		head = head->next;
	}
	return (count);
}

void	find_local_intersection(t_sector *head, int i, t_walls *wall)
{
	head->rh = (wall->neighbour_y1 - head->point[i + 1].y) *
			(head->point[i].x - head->point[i + 1].x) -
			(wall->neighbour_x1 - head->point[i + 1].x) *
			(head->point[i].y - head->point[i + 1].y);
	head->sh = (wall->neighbour_y1 - head->point[i + 1].y) *
			(wall->x2 - wall->neighbour_x1) - (wall->neighbour_x1 -
			head->point[i + 1].x) * (wall->y2 - wall->neighbour_y1);
}

int		check_local_intersection(t_sdl *sdl, t_sector *cur_sect, t_walls *wall)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i + 1 < cur_sect->size)
	{
		cur_sect->cmn = (wall->x2 - wall->neighbour_x1) *
				(cur_sect->point[i].y - cur_sect->point[i + 1].y) -
				(wall->y2 - wall->neighbour_y1) * (cur_sect->point[i].x -
				cur_sect->point[i + 1].x);
		if (cur_sect->cmn == 0)
		{
			i++;
			continue ;
		}
		find_local_intersection(cur_sect, i, wall);
		if (cur_sect->rh / cur_sect->cmn >= 0 &&
				cur_sect->rh / cur_sect->cmn <= 1 &&
				cur_sect->sh / cur_sect->cmn >= 0 &&
				cur_sect->sh / cur_sect->cmn <= 1)
			count = count_intersection(sdl, cur_sect, count);
		i++;
	}
	return (count);
}

// int		check_sect_intersects(t_sector *head, t_sector *cur_sect, t_walls *wall) // ВОТ ЭТО ДОПИСАТЬ!
// {
// 	int		i;
// 	int		count;

// 	count = 0;
// 	i = 0;
// 	if (cur_sect->num_of_sector != head->num_of_sector)
// 	{
// 		while (i + 1 < head->size)
// 		{
// 			head->cmn = (wall->x2 - wall->neighbour_x1) *
// 					(head->point[i].y - head->point[i + 1].y) -
// 					(wall->y2 - wall->neighbour_y1) * (head->point[i].x -
// 					head->point[i + 1].x);
// 			if (head->cmn == 0)
// 			{
// 				i++;
// 				continue ;
// 			}
// 			find_local_intersection(head, i, wall);
// 			if (head->rh / head->cmn >= 0 &&
// 					head->rh / head->cmn <= 1 &&
// 					head->sh / head->cmn >= 0 &&
// 					head->sh / head->cmn <= 1)
// 				count = count_intersection(sdl, head, count);
// 			i++;
// 		}
// 	}
// 	return (count);
// }
