/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overlays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 09:51:37 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/29 13:11:29 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		check_overlays(t_sdl *sdl)
{
	int			i;
	t_sector	*cur_sector;

	sdl->is_overlay = 0;
	cur_sector = sdl->sectors;
	while (cur_sector != NULL)
	{
		i = 0;
		cur_sector->check = 1;
		while (i < cur_sector->size)
		{
			//printf("Points %d\n", check_point(sdl->sectors, cur_sector->num_of_sector, cur_sector->point[i].x, cur_sector->point[i].y));
			if (check_intersection(sdl, sdl->sectors, cur_sector->point[i].x, cur_sector->point[i].y) % 2 == 1 &&
					check_point(sdl->sectors, cur_sector->num_of_sector, cur_sector->point[i].x, cur_sector->point[i].y) == 0)
				{
					// printf("THIS DOT!!! (%d %d)\n", cur_sector->point[i].x, cur_sector->point[i].y);
					return (1);
				}
			i++;
		}
		cur_sector->check = 0;
		cur_sector = cur_sector->next;
	}
	return (0);
}
