/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:48:45 by djast             #+#    #+#             */
/*   Updated: 2019/11/23 11:03:24 by djast            ###   ########.fr       */
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
	char		*char_id = NULL;

	write(fd, "player:	65534\n\n", 15);
	write(fd, "vertex:	65534	", 14);
	write_to_file(fd, char_id, sdl->player->x * 4);
	// char_id = ft_itoa(sdl->player->x * 4);
	// write(fd, char_id, ft_strlen(char_id));
	// free(char_id);
	write(fd, "	", 1);
	write_to_file(fd, char_id, sdl->player->y * 4);
	// char_id = ft_itoa(sdl->player->y * 4);
	// write(fd, char_id, ft_strlen(char_id));
	// free(char_id);
	write(fd, "	", 1);
	write_to_file(fd, char_id, sdl->sectors->z);
	// char_id = ft_itoa(sdl->sectors->z);
	// write(fd, char_id, ft_strlen(char_id));
	// free(char_id);
	write(fd, "\n\n", 2);
}

void		write_sprites(t_sdl *sdl, int fd, int last_id)
{
	t_sprite	*cur_sprite;
	int			id;
	int			i;
	char		*char_id = NULL;

	cur_sprite = sdl->sprites;
	id = last_id;
	i = 0;
	while (cur_sprite != NULL)
	{
		write(fd, "sobjct:	", 8);
		write_to_file(fd, char_id, i++);
		// char_id = ft_itoa(i++);
		// write(fd, char_id, ft_strlen(char_id));
		// free(char_id);
		write(fd, "	0	", 3);
		write_to_file(fd, char_id, cur_sprite->type);
		// char_id = ft_itoa(cur_sprite->type);
		// write(fd, char_id, ft_strlen(char_id));
		// free(char_id);
		write(fd, "	", 1);
		write_to_file(fd, char_id, id++);
		// char_id = ft_itoa(id++);
		// write(fd, char_id, ft_strlen(char_id));
		// free(char_id);
		write(fd, "\n", 1);
		cur_sprite = cur_sprite->next;
	}
	write(fd, "\n\n", 3);
}

void		write_objects(t_sdl *sdl, int fd)
{
	t_sector	*cur_sector;
	t_walls		*cur_wall;
	int			i;
	int			id;
	char		*char_id = NULL;

	cur_sector = sdl->sectors;
	cur_wall = sdl->walls;
	id = 0;
	while (cur_sector != NULL)
	{
		i = 0;
		cur_sector->total_num_of_obj = 0;
		while (i < cur_sector->size - 1)
		{
			write(fd, "object:	", 8);
			write_to_file(fd, char_id, id);
			// char_id = ft_itoa(id);
			// write(fd, char_id, ft_strlen(char_id));
			// free(char_id);

			// с каким сектором касание
			//СЕГА ГА ГА ГА
			write(fd, "	-1", 4);
			// if(i > 0)
			// {
			// 	printf("Portal-la-la-la %D\n", sdl->walls->portal);
			// 	write_to_file(fd, char_id, sdl->walls->portal);
			// }
			// cur_wall = cur_wall->next;

			write(fd, "	0	1	floor_wall	ceil_wall	1	", 29);
			write_to_file(fd, char_id, id);
			// char_id = ft_itoa(id);
			// write(fd, char_id, ft_strlen(char_id));
			// free(char_id);
			write(fd, "\n", 1);
			id++;
			cur_sector->total_num_of_obj++;
			i++;
		}
		id++;
		write(fd, "\n", 1);
		cur_sector = cur_sector->next;
	}
}

void		write_sectors(t_sdl *sdl, int fd)
{
	t_sector	*cur_sector;
	int			i;
	int			num;
	char		*char_id = NULL;

	cur_sector = sdl->sectors;
	num = 0;
	while (cur_sector->next != NULL)
	{
		i = 0;
		write(fd, "sector: ", 9);
		write_to_file(fd, char_id, cur_sector->num_of_sector);
		// char_id = ft_itoa(cur_sector->num_of_sector);
		// write(fd, char_id, ft_strlen(char_id));
		// free(char_id);
		write(fd, "	0	675	q_floor_5	q_floor_3	0xFF0000	", 37);

		// обход стен по часовой стрелке!!!

		write_to_file(fd, char_id, cur_sector->total_num_of_obj);
		// char_id = ft_itoa(cur_sector->total_num_of_obj);
		// write(fd, char_id, ft_strlen(char_id));
		// free(char_id);
		write(fd, "\t", 2);
		while (i < cur_sector->total_num_of_obj)
		{
			write_to_file(fd, char_id, num);
			// char_id = ft_itoa(num);
			// write(fd, char_id, ft_strlen(char_id));
			// free(char_id);
			write(fd, " ", 1);
			i++;
			num++;
		}
		write(fd, "\n", 2);
		cur_sector = cur_sector->next;
	}
}
