/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:48:45 by djast             #+#    #+#             */
/*   Updated: 2019/11/27 10:39:01 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		write_world(t_sdl *sdl, int fd)
{
	char	*sectors;
	int		i;

	write(fd, "world:	1	", 9);
	sectors = ft_itoa(sdl->count);
	write(fd, sectors, ft_strlen(sectors));
	write(fd, "	", 1);
	free(sectors);
	i = 0;
	sectors = ft_itoa(i++);
	write(fd, sectors, ft_strlen(sectors));
	free(sectors);
	while (i != sdl->count)
	{
		write(fd, " ", 1);
		sectors = ft_itoa(i++);
		write(fd, sectors, ft_strlen(sectors));
		free(sectors);
	}
	write(fd, "\n", 1);
}

void		write_player(t_sdl *sdl, int fd)
{
	char	*char_id;

	char_id = NULL;
	write(fd, "player:	0	2000\n\n", 16);
	write(fd, "vertex:	2000	", 13);
	write_to_file(fd, char_id, sdl->player->x * 4);
	write(fd, "	", 1);
	write_to_file(fd, char_id, sdl->player->y * 4);
	write(fd, "	", 1);
	write_to_file(fd, char_id, sdl->sectors->z);
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
	char_id = NULL;
	while (cur_sprite != NULL)
	{
		write(fd, "sobjct:	", 8);
		write_to_file(fd, char_id, i++);
		write(fd, "	0	", 3);
		write_to_file(fd, char_id, cur_sprite->type);
		write(fd, "	", 1);
		write_to_file(fd, char_id, id++);
		write(fd, "\n", 1);
		cur_sprite = cur_sprite->next;
	}
	write(fd, "\n\n", 2);
}

void		write_objects(t_sdl *sdl, int fd)
{
	t_sector	*cur_sector;
	int			i;
	int			id;
	int			count;
	char		*char_id;

	cur_sector = sdl->sectors;
	id = 0;
	count = 0;
	char_id = NULL;
	while (cur_sector != NULL)
	{
		i = 0;
		cur_sector->total_num_of_obj = 0;
		while (i < cur_sector->size - 1)
		{
			write(fd, "object:	", 8);
			write_to_file(fd, char_id, count);
			write(fd, "	", 1);
			write_to_file(fd, char_id, cur_sector->walls[i].portal);
			write(fd, "	", 1);
			if (cur_sector->walls[i].portal > -1)
				write(fd, "	1	1	null		flooring	ceiling	", 28);
			else
				write(fd, "	0	1	q_bricks_2	flooring	ceiling	", 33);
			write_to_file(fd, char_id, id);
			write(fd, " ", 1);
			write_to_file(fd, char_id, id + 1);
			write(fd, "\n", 1);
			id++;
			cur_sector->total_num_of_obj++;
			i++;
			count++;
		}
		write(fd, "\n", 1);
		id++;
		cur_sector = cur_sector->next;
	}
}

void		write_sectors(t_sdl *sdl, int fd)
{
	t_sector	*cur_sector;
	int			i;
	char		*char_id;

	cur_sector = sdl->sectors;
	char_id = NULL;
	while (cur_sector->next != NULL)
	{
		i = 0;
		write(fd, "sector: ", 8);
		write_to_file(fd, char_id, cur_sector->num_of_sector);
		write(fd, "	0	675	q_floor_5	q_floor_3	0xFF0000	", 36);
		write_to_file(fd, char_id, cur_sector->total_num_of_obj);
		write(fd, "\t", 1);
		while (i < cur_sector->total_num_of_obj)
		{
			write_to_file(fd, char_id, sdl->num);
			write(fd, " ", 1);
			i++;
			sdl->num++;
		}
		write(fd, "\n", 1);
		cur_sector = cur_sector->next;
	}
}
