/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:48:45 by djast             #+#    #+#             */
/*   Updated: 2019/10/19 15:42:32 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		write_world(t_sdl *sdl, int fd)
{
	int sector_count;
	char *sectors;
	int i;

	write(fd, "world:	1	", 9);
	sector_count = get_sector_count(sdl->sectors);
	sectors = ft_itoa(sector_count);
	write(fd, sectors, ft_strlen(sectors));
	write(fd, "	", 1);
	free(sectors);
	i = 0;
	sectors = ft_itoa(i++);
	write(fd, sectors, ft_strlen(sectors));
	free(sectors);
	while (i != sector_count)
	{
		write(fd, ",", 1);
		sectors = ft_itoa(i++);
		write(fd, sectors, ft_strlen(sectors));
		free(sectors);
	}
	write(fd, "\n", 1);
}

void			write_vertexes(t_sdl *sdl, int fd)
{
	t_sector	*cur_sector;
	int			i;
	int			id;
	char		*char_id;

	cur_sector = sdl->sectors;
	id = 0;
	
	while (cur_sector != NULL && cur_sector->size != 0)
	{
		i = 0;
		printf("%d\n", cur_sector->size);
		while (i != cur_sector->size)
		{
			write(fd, "vertex:	", 8);
			char_id = ft_itoa(id++);
			write(fd, char_id, ft_strlen(char_id));
			free(char_id);
			write(fd, "	", 1);
			char_id = ft_itoa(cur_sector->point[i].x * 4);
			write(fd, char_id, ft_strlen(char_id));
			free(char_id);
			write(fd, "	", 1);
			char_id = ft_itoa(cur_sector->point[i].y * 4);
			write(fd, char_id, ft_strlen(char_id));
			free(char_id);
			write(fd, "	", 1);
			char_id = ft_itoa(cur_sector->z);
			write(fd, char_id, ft_strlen(char_id));
			free(char_id);
			write(fd, "\n", 1);
			i++;
		}
		write(fd, "\n", 1);
		cur_sector = cur_sector->next;
	}
}

void			write_polygone(t_sdl *sdl, int fd)
{
	t_sector	*cur_sector;
	int			i;
	int			id;
	char		*char_id;

	cur_sector = sdl->sectors;
	id = 1;
	
	while (cur_sector != NULL && cur_sector->size != 0)
	{
		i = 0;
		while (i != cur_sector->size - 1)
		{
			write(fd, "polygone:	", 10);
			char_id = ft_itoa(id);
			write(fd, char_id, ft_strlen(char_id));
			free(char_id);
			write(fd, "	1	0xFF0000	bricks	2	", 21);
			char_id = ft_itoa(id);
			write(fd, char_id, ft_strlen(char_id));
			free(char_id);
			write(fd, ",", 1);
			char_id = ft_itoa(id - 1);
			write(fd, char_id, ft_strlen(char_id));
			free(char_id);
			write(fd, "\n", 1);
			id++;
			i++;
		}
		id++;
		write(fd, "\n", 1);
		cur_sector = cur_sector->next;
	}
}

void			write_player(t_sdl *sdl, int fd)
{
	char		*char_id;

	write(fd, "player:	98123\n\n", 15);
	write(fd, "vertex:	98123	", 14);
	char_id = ft_itoa(sdl->player->x * 4);
	write(fd, char_id, ft_strlen(char_id));
	free(char_id);
	write(fd, "	", 1);
	char_id = ft_itoa(sdl->player->y * 4);
	write(fd, char_id, ft_strlen(char_id));
	free(char_id);
	write(fd, "	", 1);
	char_id = ft_itoa(sdl->sectors->z);
	write(fd, char_id, ft_strlen(char_id));
	free(char_id);
	write(fd, "\n\n", 2);
}
