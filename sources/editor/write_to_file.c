/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:48:45 by djast             #+#    #+#             */
/*   Updated: 2019/11/14 14:03:46 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		write_world(t_sdl *sdl, int fd)
{
	int		sector_count;
	char	*sectors;
	int		i;

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

// void			write_polygone(t_sdl *sdl, int fd)
// {
// 	t_sector	*cur_sector;
// 	int			i;
// 	int			id;
// 	char		*char_id;

// 	cur_sector = sdl->sectors;
// 	id = 1;
// 	while (cur_sector != NULL)
// 	{
// 		i = 0;
// 		while (i < cur_sector->size - 1)
// 		{
// 			write(fd, "polygone:	", 10);
// 			char_id = ft_itoa(id);
// 			write(fd, char_id, ft_strlen(char_id));
// 			free(char_id);
// 			write(fd, "	1	0xFF0000	bricks	2	", 21);
// 			char_id = ft_itoa(id);
// 			write(fd, char_id, ft_strlen(char_id));
// 			free(char_id);
// 			write(fd, ",", 1);
// 			char_id = ft_itoa(id - 1);
// 			write(fd, char_id, ft_strlen(char_id));
// 			free(char_id);
// 			write(fd, "\n", 1);
// 			id++;
// 			i++;
// 		}
// 		id++;
// 		write(fd, "\n", 1);
// 		cur_sector = cur_sector->next;
// 	}
// }

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

void		write_sprites(t_sdl *sdl, int fd, int last_id)
{
	t_sprite	*cur_sprite;
	int			id;
	int			i;
	char		*char_id;

	cur_sprite = sdl->sprites;
	id = last_id;
	i = 0;
	while (cur_sprite != NULL)
	{
		write(fd, "sobjct:	", 8);
		char_id = ft_itoa(i++);
		write(fd, char_id, ft_strlen(char_id));
		free(char_id);
		write(fd, "	0	", 3);
		char_id = ft_itoa(cur_sprite->type);
		write(fd, char_id, ft_strlen(char_id));
		free(char_id);
		write(fd, "	", 1);
		char_id = ft_itoa(id++);
		write(fd, char_id, ft_strlen(char_id));
		free(char_id);
		write(fd, "\n", 1);
		cur_sprite = cur_sprite->next;
	}
	write(fd, "\n", 1);
}

void		write_objects(t_sdl *sdl, int fd)
{
	t_sector	*cur_sector;
	int			i;
	int			id;
	char		*char_id;

	cur_sector = sdl->sectors;
	id = 1;
	while (cur_sector != NULL)
	{
		i = 0;
		while (i < cur_sector->size - 1)
		{
			write(fd, "object:	", 8);
			char_id = ft_itoa(id);
			write(fd, char_id, ft_strlen(char_id));
			free(char_id);
			write(fd, "	-1	0	1	floor_wall	ceil_wall	1	", 31);
			char_id = ft_itoa(id);
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

void		write_sectors(t_sdl *sdl, int fd)
{
	// (void)sdl;
	// (void)fd;
	t_sector	*cur_sector;
	int			i;
	int			id;
	char		*char_id;

	cur_sector = sdl->sectors;
	id = 1;
	while (cur_sector != NULL)
	{
		i = 0;
		while (i < cur_sector->size - 1)
		{
			write(fd, "sector: ", 10);
			char_id = ft_itoa(id);
			write(fd, char_id, ft_strlen(char_id));
			free(char_id);
			write(fd, "0	675	q_floor_5	q_floor_3	0xFF0000	", 36);

			// добавить колонку с количеством объектов и номерами объектов: 5	0 1 2 3 4

			// char_id = ft_itoa(id);
			// write(fd, char_id, ft_strlen(char_id));
			// free(char_id);
			// write(fd, ",", 1);
			// char_id = ft_itoa(id - 1);
			// write(fd, char_id, ft_strlen(char_id));
			// free(char_id);
			write(fd, "\n", 1);
			id++;
			i++;
		}
		id++;
		write(fd, "\n", 1);
		cur_sector = cur_sector->next;
	}
}
