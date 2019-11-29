/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:52:19 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/29 14:52:45 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	save_wall(t_sector *sector, int i)
{
	if (i > 0)
	{
		sector->walls[i - 1].x1 = sector->point[i - 1].x;
		sector->walls[i - 1].y1 = sector->point[i - 1].y;
		sector->walls[i - 1].x2 = sector->point[i].x;
		sector->walls[i - 1].y2 = sector->point[i].y;
		sector->walls[i - 1].wall_id = i - 1;
		sector->walls[i - 1].portal = -1;
		sector->num_of_walls = sector->walls[i - 1].wall_id + 1;
	}
}
