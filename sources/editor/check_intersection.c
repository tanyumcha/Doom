/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:55:28 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/23 09:13:27 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		count_intersection(t_sdl *sdl, t_sector *head, int count)
{
	count++;
	if (count % 2 == 1)
		sdl->sprite_in_sector = head->num_of_sector;
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
		head = head->next;
	}
	return (count);
}
