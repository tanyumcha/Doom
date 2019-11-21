/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_touch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:49:10 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/21 15:39:01 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		point_on_segment(int x1, int y1, int x2, int y2, int x, int y)
{
	if ((x - x1) * (y2 - y1) - (y - y1) * (x2 - x1) == 0)
	{
		if ((x > x1 && x < x2) || (x < x1 && x > x2))
			return (1);
	}
	return (0);
}

int		points_on_line(int x1, int y1, int x2, int y2, int x3, int y3)
{
	if (x3 * (y2 - y1) - y3 * (x2 - x1) == x1 * y2 - x2 * y1)
		return (1);
	return (0);
}

				// x1 = sector->point[i].x
				// y1 = sector->point[i].y
				// x2 = sector->point[i - 1].x
				// y2 = sector->point[i - 1].y
				// x3 = head->point[j].x
				// y3 = head->point[j].y
				// x4 = head->point[j - 1].x
				// y4 = head->point[j - 1].y

				// if (points_on_line(x2, y2, x3, y3, x4, y4) == 1 &&
				// 		points_on_line(x1, y1, x3, y3, x4, y4) == 1 &&
				// 		points_on_line(x1, y1, x2, y2, x4, y4) == 1 &&
				// 		points_on_line(x1, y1, x2, y2, x3, y3) == 1)
				// {
				// 	if (point_on_segment(x1, y1, x2, y2, x3, y3) == 1 ||
				// 			point_on_segment(x1, y1, x2, y2, x4, y4) == 1 ||
				// 			point_on_segment(x3, y3, x4, y4, x1, y1) == 1 ||
				// 			point_on_segment(x3, y3, x4, y4, x2, y2) == 1)
				// 		sector->neighbour = head->num_of_sector;
				// }

void	check_the_touch(t_sector *head, t_sector *sector, int i)
{
	int	j;

	while (head != NULL)
	{
		j = 1;
		while (j < head->size)
		{
				int x1 = sector->point[i - 1].x; // какие то кривые результаты
				int y1 = sector->point[i - 1].y;
				int x2 = sector->point[i].x;
				int y2 = sector->point[i].y;
				int x3 = head->point[j - 1].x;
				int y3 = head->point[j - 1].y;
				int x4 = head->point[j].x;
				int y4 = head->point[j].y;
	printf("x1 = %d\n", x1);
				if (points_on_line(x2, y2, x3, y3, x4, y4) == 1 &&
						points_on_line(x1, y1, x3, y3, x4, y4) == 1 &&
						points_on_line(x1, y1, x2, y2, x4, y4) == 1 &&
						points_on_line(x1, y1, x2, y2, x3, y3) == 1)
				{
					printf("OK! On line\n");
					if (point_on_segment(x1, y1, x2, y2, x3, y3) == 1 ||
							point_on_segment(x1, y1, x2, y2, x4, y4) == 1 ||
							point_on_segment(x3, y3, x4, y4, x1, y1) == 1 ||
							point_on_segment(x3, y3, x4, y4, x2, y2) == 1)
					{
						printf("OK! On segment\n");
						sector->neighbour = head->num_of_sector;
						printf("Portal is: %d", sector->neighbour);
					}
				}

			// if (points_on_line(sector->point[i - 1].x, sector->point[i - 1].y, head->point[j].x, head->point[j].y, head->point[j - 1].x, head->point[j - 1].y) == 1 &&
			// 		points_on_line(sector->point[i].x, sector->point[i].y, head->point[j].x, head->point[j].y, head->point[j - 1].x, head->point[j - 1].y) == 1 &&
			// 		points_on_line(sector->point[i].x, sector->point[i].y, sector->point[i - 1].x, sector->point[i - 1].y, head->point[j - 1].x, head->point[j - 1].y) == 1 &&
			// 		points_on_line(sector->point[i].x, sector->point[i].y, sector->point[i - 1].x, sector->point[i - 1].y, head->point[j].x, head->point[j].y) == 1)
			// {
			// 	printf("OK! On line\n");
			// 	if (point_on_segment(sector->point[i].x, sector->point[i].y, sector->point[i - 1].x, sector->point[i - 1].y, head->point[j].x, head->point[j].y) == 1 ||
			// 			point_on_segment(sector->point[i].x, sector->point[i].y, sector->point[i - 1].x, sector->point[i - 1].y, head->point[j - 1].x, head->point[j - 1].y) == 1 ||
			// 			point_on_segment(head->point[j].x, head->point[j].y, head->point[j - 1].x, head->point[j - 1].y, sector->point[i].x, sector->point[i].y) == 1 ||
			// 			point_on_segment(head->point[j].x, head->point[j].y, head->point[j - 1].x, head->point[j - 1].y, sector->point[i - 1].x, sector->point[i - 1].y) == 1)
			// 	{
			// 		printf("OK! On segment\n");
			// 		sector->neighbour = head->num_of_sector;
			// 		printf("Portal is: %d", sector->neighbour);
			// 	}
			// }

			j++;
		}
		head = head->next;
	}
}

// int main()
// {
// 	int x1 = 1;
// 	int y1 = 1;
// 	int x2 = 2;
// 	int y2 = 2;
// 	int x3 = 2;
// 	int y3 = 2;
// 	int x4 = 4;
// 	int y4 = 4;

// 	if (points_on_line(x2, y2, x3, y3, x4, y4) == 1 &&
// 			points_on_line(x1, y1, x3, y3, x4, y4) == 1 &&
// 			points_on_line(x1, y1, x2, y2, x4, y4) == 1 &&
// 			points_on_line(x1, y1, x2, y2, x3, y3) == 1)
// 		printf("OK! On line\n");
// 	else
// 		printf("Nope 1!\n");
// 	if (point_on_segment(x1, y1, x2, y2, x3, y3) == 1 ||
// 			point_on_segment(x1, y1, x2, y2, x4, y4) == 1 ||
// 			point_on_segment(x3, y3, x4, y4, x1, y1) == 1 ||
// 			point_on_segment(x3, y3, x4, y4, x2, y2) == 1)
// 		printf("OK! On segment\n");
// 	else
// 		printf("Nope 2!\n");
// 	return (0);
// }
