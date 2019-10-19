/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:34:40 by djast             #+#    #+#             */
/*   Updated: 2019/10/19 11:18:52 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_sector		*get_last_sector(t_sector *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}

SDL_Color		*create_sdl_color(int r, int g, int b, int a)
{
	SDL_Color *color;

	color = (SDL_Color *)malloc(sizeof(SDL_Color));
	color->r = r;
	color->g = g;
	color->b = b;
	color->a = a;
	return (color);
}
