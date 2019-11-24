/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_touch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:49:10 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/22 13:54:10 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		point_on_segment(t_walls *cur_wall)
{
	if ((cur_wall->neighbour_x1 - cur_wall->x1) * (cur_wall->y2 - cur_wall->y1) - (cur_wall->neighbour_y1 - cur_wall->y1) * (cur_wall->x2 - cur_wall->x1) == 0 &&
		(cur_wall->neighbour_x2 - cur_wall->x1) * (cur_wall->y2 - cur_wall->y1) - (cur_wall->neighbour_y2 - cur_wall->y1) * (cur_wall->x2 - cur_wall->x1) == 0 &&
		(cur_wall->x1 - cur_wall->neighbour_x1) * (cur_wall->neighbour_y2 - cur_wall->neighbour_y1) - (cur_wall->y1 - cur_wall->neighbour_y1) * (cur_wall->neighbour_x2 - cur_wall->neighbour_x1) == 0 &&
		(cur_wall->x2 - cur_wall->neighbour_x1) * (cur_wall->neighbour_y2 - cur_wall->neighbour_y1) - (cur_wall->y2 - cur_wall->neighbour_y1) * (cur_wall->neighbour_x2 - cur_wall->neighbour_x1) == 0)
	{
		if (((cur_wall->neighbour_x1 > cur_wall->x1 && cur_wall->neighbour_x1 < cur_wall->x2) || (cur_wall->neighbour_x1 < cur_wall->x1 && cur_wall->neighbour_x1 > cur_wall->x2)) ||
				((cur_wall->neighbour_x2 > cur_wall->x1 && cur_wall->neighbour_x2 < cur_wall->x2) || (cur_wall->neighbour_x2 < cur_wall->x1 && cur_wall->neighbour_x2 > cur_wall->x2)) ||
				((cur_wall->x1 > cur_wall->neighbour_x1 && cur_wall->x1 < cur_wall->neighbour_x2) || (cur_wall->x1 < cur_wall->neighbour_x1 && cur_wall->x1 > cur_wall->neighbour_x2)) ||
				((cur_wall->x2 > cur_wall->neighbour_x1 && cur_wall->x2 < cur_wall->neighbour_x2) || (cur_wall->x2 < cur_wall->neighbour_x1 && cur_wall->x2 > cur_wall->neighbour_x2)))
			return (1);
	}
	return (0);
}

int		points_on_line(t_walls *cur_wall)
{
	if (cur_wall->neighbour_x1 * (cur_wall->y2 - cur_wall->y1) - cur_wall->neighbour_y1 * (cur_wall->x2 - cur_wall->x1) == cur_wall->x1 * cur_wall->y2 - cur_wall->x2 * cur_wall->y1 &&
			cur_wall->neighbour_x2 * (cur_wall->y2 - cur_wall->y1) - cur_wall->neighbour_y2 * (cur_wall->x2 - cur_wall->x1) == cur_wall->x1 * cur_wall->y2 - cur_wall->x2 * cur_wall->y1 &&
			cur_wall->x1 * (cur_wall->neighbour_y2 - cur_wall->neighbour_y1) - cur_wall->y1 * (cur_wall->neighbour_x2 - cur_wall->neighbour_x1) == cur_wall->neighbour_x1 * cur_wall->neighbour_y2 - cur_wall->neighbour_x2 * cur_wall->neighbour_y1 &&
			cur_wall->x2 * (cur_wall->neighbour_y2 - cur_wall->neighbour_y1) - cur_wall->y2 * (cur_wall->neighbour_x2 - cur_wall->neighbour_x1) == cur_wall->neighbour_x1 * cur_wall->neighbour_y2 - cur_wall->neighbour_x2 * cur_wall->neighbour_y1)
		return (1);
	return (0);
}

void	check_the_touch(t_walls *cur_wall, t_sector *head)
{
	int	j;

	while (head != NULL)
	{
		j = 1;
		while (j < head->size)
		{
			cur_wall->neighbour_x1 = head->point[j - 1].x;
			cur_wall->neighbour_y1 = head->point[j - 1].y;
			cur_wall->neighbour_x2 = head->point[j].x;
			cur_wall->neighbour_y2 = head->point[j].y;
			if (points_on_line(cur_wall) == 1)
			{
				printf("OK! On line\n");
				if (point_on_segment(cur_wall) == 1)
				{
					printf("OK! On segment\n");
					cur_wall->portal = head->num_of_sector;
					printf("Portal is: %d\n", cur_wall->portal);
				}
			}
			j++;
		}
		head = head->next;
	}
}

	// (x1, y1, x2, y2, x3, y3)
	// (x1, y1, x2, y2, x4, y4)
	// (x3, y3, x4, y4, x1, y1)
	// (x3, y3, x4, y4, x2, y2)

	// int x1 = cur_wall->x1;
	// int y1 = cur_wall->y1;
	// int x2 = cur_wall->x2;
	// int y2 = cur_wall->y2;
	// int x3 = cur_wall->neighbour_x1;
	// int y3 = cur_wall->neighbour_y1;
	// int x4 = cur_wall->neighbour_x2;
	// int y4 = cur_wall->neighbour_y2;


// int		point_on_segment(int x1, int y1, int x2, int y2, int x, int y)
// {
// 	if ((x - x1) * (y2 - y1) - (y - y1) * (x2 - x1) == 0)
// 	{
// 		if ((x > x1 && x < x2) || (x < x1 && x > x2))
// 			return (1);
// 	}
// 	return (0);
// }

// int		points_on_line(int x1, int y1, int x2, int y2, int x3, int y3)
// {
// 	if (x3 * (y2 - y1) - y3 * (x2 - x1) == x1 * y2 - x2 * y1)
// 		return (1);
// 	return (0);
// }

// int main()
// {
// 	int x1 = 2;
// 	int y1 = 1;
// 	int x2 = 2;
// 	int y2 = 4;
// 	int x3 = 2;
// 	int y3 = 2;
// 	int x4 = 2;
// 	int y4 = 3;

// 	// int x1 = 1;
// 	// int y1 = 1;
// 	// int x2 = 4;
// 	// int y2 = 4;
// 	// int x3 = 2;
// 	// int y3 = 2;
// 	// int x4 = 3;
// 	// int y4 = 3;

// 	if (points_on_line(x2, y2, x3, y3, x4, y4) == 1 &&
// 			points_on_line(x1, y1, x3, y3, x4, y4) == 1 &&
// 			points_on_line(x1, y1, x2, y2, x4, y4) == 1 &&
// 			points_on_line(x1, y1, x2, y2, x3, y3) == 1)
// 		printf("OK! On line\n");
// 	else
// 		printf("Nope 1!\n");
// 	if (point_on_segment(x1, y1, x2, y2, x3, y3) == 1 ||
// 			point_on_segment(x1, y1, x2, y2, x4, y4) == 1 ||
// 			(point_on_segment(x1, y1, x2, y2, x3, y3) == 1 &&
// 			point_on_segment(x1, y1, x2, y2, x4, y4) == 1) ||
// 			point_on_segment(x3, y3, x4, y4, x1, y1) == 1 ||
// 			point_on_segment(x3, y3, x4, y4, x2, y2) == 1 ||
// 			(point_on_segment(x3, y3, x4, y4, x1, y1) == 1 &&
// 			point_on_segment(x3, y3, x4, y4, x2, y2) == 1))
// 		printf("OK! On segment\n");
// 	else
// 		printf("Nope 2!\n");
// 	return (0);
// }
