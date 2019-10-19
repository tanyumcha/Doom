/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:37:38 by djast             #+#    #+#             */
/*   Updated: 2019/10/19 17:01:47 by djast            ###   ########.fr       */
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
	return (fd);
}

void		save_map(t_sdl *sdl, char *map_name)
{
	int fd;
	int last_id;

	fd = create_file(map_name);
	write_world(sdl, fd);
	write_player(sdl, fd);
	last_id = write_vertexes_wall(sdl, fd);
	write_vertexes_sprite(sdl, fd, last_id);
	write_polygone(sdl, fd);
	write_objects(sdl, fd);
	write_sprites(sdl, fd, last_id);
	write_sectors(sdl, fd);
}