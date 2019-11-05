/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_on_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:49:10 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/05 11:49:32 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "editor.h"

int	points_on_line(int x1, int y1, int x2, int y2, int x3, int y3)
{
	if (x3 * (y2 - y1) - y3 * (x2 - x1) == x1 * y2 - x2 * y1)
		return (1);
	return (0);
}

int main()
{
	int x1 = 1;
	int y1 = 1;
	int x2 = 2;
	int y2 = 2;
	int x3 = 3;
	int y3 = 3;
	int x4 = 4;
	int y4 = 4;

	if (points_on_line(x2, y2, x3, y3, x4, y4) == 1 &&
			points_on_line(x1, y1, x3, y3, x4, y4) == 1 &&
			points_on_line(x1, y1, x2, y2, x4, y4) == 1 &&
			points_on_line(x1, y1, x2, y2, x3, y3) == 1)
		printf("OK!");
	else
		printf("Nope!");
	return (0);
}
