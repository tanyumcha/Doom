/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:37:38 by djast             #+#    #+#             */
/*   Updated: 2019/11/24 12:02:54 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static int	create_file(char *map_name)
{
	int		fd;
	char	filename[120];

	ft_strcpy(filename, "resources/");
	ft_strcat(filename, map_name);
	fd = open(filename, O_WRONLY);
	if (fd == -1)
	{
		open(filename, O_CREAT);
		fd = open(filename, O_WRONLY);
	}
	else
		return (-1);
	return (fd);
}

int		save_map(t_sdl *sdl, char *map_name)
{
	int fd;
	int last_id;

	fd = create_file(map_name);
	if (fd == -1)
		return (0);
	write_world(sdl, fd);
	write_player(sdl, fd);
	last_id = write_vertexes_wall(sdl, fd);
	write_vertexes_sprite(sdl, fd, last_id);
	// write_polygone(sdl, fd);
	write_objects(sdl, fd);
	write_sprites(sdl, fd, last_id);
	write_sectors(sdl, fd);
	close(fd); //проверить остаются ли хвосты
	return (1);
	
}

// void		load_click(t_sdl *sdl)
// {
// 	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
// 	if (sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
// 		sdl->window_event.button.button == SDL_BUTTON_LEFT &&
// 		((sdl->mouse_position.x > BUTTON_STATUS_X1 &&
// 		sdl->mouse_position.x < BUTTON_STATUS_X2) &&
// 		(sdl->mouse_position.y > BUTTON_STATUS_Y1 &&
// 		sdl->mouse_position.y < BUTTON_STATUS_Y2)))
// 	{
// 		printf("Me too!\n");
// 	}
// }

void		save_click(t_sdl *sdl)
{
	// sdl->button_pushed = 13;
	if (sdl->map_name->text_size <= 0)
	{
		sdl->status_code = CODE_NO_FILENAME;
		return ;
	}
	if (!(sdl->player->x > 0 && sdl->player->y > 0))
	{
		sdl->status_code = CODE_NO_PLAYER;
		return ;
	}
	ft_strcat(sdl->map_name->text, ".txt");
	if (save_map(sdl, sdl->map_name->text) == 0)
	{
		sdl->status_code = CODE_ALREADY_EXIST;
		return ;
	}
	bzero(sdl->map_name->text, sizeof(char *));
	sdl->map_name->text_size = 0;
	sdl->status_code = CODE_OK;
	printf("I want cookies!\n");
}

int			bigscarycondition(t_sdl *sdl)
{
	SDL_GetMouseState(&sdl->mouse_position.x, &sdl->mouse_position.y);
	if (	((sdl->window_event.type == SDL_KEYDOWN &&
			SDLK_KP_ENTER == sdl->window_event.key.keysym.sym) ||
			(sdl->window_event.type == SDL_KEYDOWN &&
			SDLK_RETURN == sdl->window_event.key.keysym.sym) ||
			(sdl->window_event.type == SDL_MOUSEBUTTONDOWN &&
			sdl->window_event.button.button == SDL_BUTTON_LEFT &&
			((sdl->mouse_position.x > BUTTON_SAVE_X1 &&
			sdl->mouse_position.x < BUTTON_SAVE_X2) &&
			(sdl->mouse_position.y > BUTTON_SAVE_Y1 &&
			sdl->mouse_position.y < BUTTON_SAVE_Y2)))))
		return (1);
	return (0);
}
