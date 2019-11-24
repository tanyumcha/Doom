/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clockwise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:02:54 by djast             #+#    #+#             */
/*   Updated: 2019/11/24 15:04:34 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		is_clockwise(t_walls *walls)
{
	int result;
	
	// printf("(%d; %d)/(%d; %d), new dot: (%d; %d)\n", walls->x1, walls->y1,
	// 												walls->x2, walls->y2,
	// 								walls->neighbour_x1, walls->neighbour_y1);
	result = (walls->neighbour_x1 - walls->x1) * (walls->y2 - walls->y1) -
			(walls->neighbour_y1 - walls->y1) * (walls->x2 - walls->x1);
	if (result < 0)
		return (1);
	return (0);
}
