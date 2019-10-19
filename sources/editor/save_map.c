/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:37:38 by djast             #+#    #+#             */
/*   Updated: 2019/10/19 14:51:49 by djast            ###   ########.fr       */
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

	fd = create_file(map_name);
	write_world(sdl, fd);
	write_player(sdl, fd);
	write_vertexes(sdl, fd);
	write_polygone(sdl, fd);
}