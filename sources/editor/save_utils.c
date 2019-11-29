/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:51:43 by djast             #+#    #+#             */
/*   Updated: 2019/11/29 10:33:49 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	choose_the_status(t_sdl *sdl, SDL_Rect *button)
{
	SDL_Color *color_text;

	color_text = NULL;
	if (sdl->status_code == CODE_ALREADY_EXIST)
	{
		color_text = create_sdl_color(255, 0, 0, 255);
		draw_text(sdl, "File already exist", *button, *color_text);
	}
	else if (sdl->status_code == CODE_OK)
	{
		color_text = create_sdl_color(0, 255, 0, 255);
		draw_text(sdl, "Save complete", *button, *color_text);
	}
	else if (sdl->status_code == CODE_NO_FILENAME)
	{
		color_text = create_sdl_color(255, 0, 0, 255);
		draw_text(sdl, "Empty filename", *button, *color_text);
	}
	else if (sdl->status_code == CODE_NO_PLAYER)
	{
		color_text = create_sdl_color(255, 0, 0, 255);
		draw_text(sdl, "No player on the map", *button, *color_text);
	}
	else if (sdl->status_code == CODE_OVERLAY)
	{
		color_text = create_sdl_color(255, 0, 0, 255);
		draw_text(sdl, "Got a match of sectors", *button, *color_text);
	}
	free(color_text);
}

void	status_text(t_sdl *sdl, SDL_Rect *button)
{
	button = create_rect(BUTTON_STATUS_X1, BUTTON_STATUS_Y1,
			BUTTON_STATUS_X2 - BUTTON_STATUS_X1,
			BUTTON_STATUS_Y2 - BUTTON_STATUS_Y1);
	choose_the_status(sdl, button);
	free(button);
}

char	*cut_the_end(char *text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (text[i] == '.')
			text[i] = '\0';
		i++;
	}
	return (text);
}

void	delete_one_symbol(t_sdl *sdl)
{
	if (sdl->map_name->text_size > 0)
	{
		sdl->map_name->text_size--;
		sdl->map_name->text[sdl->map_name->text_size] = '\0';
	}
}

void	write_to_file(int fd, char *data, int numdata)
{
	data = ft_itoa(numdata);
	write(fd, data, ft_strlen(data));
	free(data);
}
