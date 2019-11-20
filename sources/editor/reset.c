/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:48:39 by eharrag-          #+#    #+#             */
/*   Updated: 2019/11/20 15:12:03 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

// void	delete_sprites(t_sprite *sprites)
// {
// 	while (sprites != NULL)// доделать ПРИ РЕСЕТЕ ПОЯВЛЯЕТСЯ В 0.0 ТОЧКА
// 	{
// 		sprites->type = 0;
// 		sprites->x = 0;
// 		sprites->y = 0;
// 		sprites = sprites->next;
// 	}
// }

void	reset(t_sdl *sdl)//, t_sector **head, t_point *player, t_sprite *sprites)
{

	// (void)head;
	// (void)player;
	// (void)sprites;

	// t_sector **prev;
	// t_sector **cur;
	// prev = head;
	// cur = &((*head)->next);
	// if ((*head)->next)
	// {
	// 	while (*cur != NULL)
	// 	{
	// 		free(*prev);
	// 		*prev = *cur;
	// 		*cur = (*cur)->next;
	// 	}
	// }
	// ft_bzero((*prev)->point, 100);
	// (*prev)->size = 0;
	// delete_player(player);
	// delete_sprites(sprites);
	while (sdl->command_count > 0)
	{
		delete_last_command(sdl);
		sdl->command_count--;
	}
}
