/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:55:28 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/16 10:05:13 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int check_intersection(t_sector *head, int x1, int y1, int x2, int y2)
{
	int i;
	int count;
	double common;
	double rH;
	double sH;

	count = 0;
	while (head != NULL)
	{
		i = 0;
		while (i + 1 < head->size)
			{
				//printf("%d: otr1: %d %d - %d %d, otr2: %d %d - %d %d\n", i, x1, y1, x2, y2, head->point[i].x, head->point[i].y, head->point[i + 1].x,  head->point[i + 1].y);
				common = (x2 - x1)*(head->point[i].y - head->point[i + 1].y) - (y2 - y1)*(head->point[i].x - head->point[i + 1].x);
				if (common == 0)
				{
					i++;
					continue ;
				}
				rH = (y1 - head->point[i + 1].y)*(head->point[i].x - head->point[i + 1].x) - (x1 - head->point[i + 1].x)*(head->point[i].y - head->point[i + 1].y);
				sH = (y1 - head->point[i + 1].y)*(x2 - x1) - (x1 - head->point[i + 1].x)*(y2 - y1);
				if (rH / common >= 0 && rH / common <= 1 && sH / common >= 0 && sH / common <= 1)
					count++;
				i++;
			}
		head = head->next;
	}
	return (count);
}
