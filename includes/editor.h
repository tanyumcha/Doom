/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:59:27 by djast             #+#    #+#             */
/*   Updated: 2019/10/14 17:51:46 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H
# include <SDL.h>
# include <SDL_ttf.h>
# include <limits.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

# define SIZE_WIN_X 2048
# define SIZE_WIN_Y 1152
# define POINT_SIZE 10
# define STEP 50
# define GRID_SIZE 600
# define GRID_SIZE_X 30
# define GRID_SIZE_Y 20

# define WALL_TYPE 1
# define PLAYER_TYPE 2
# define SPRITE_TYPE 3




typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_sector
{
	t_point				point[100];
	int					size;
	int					num_of_sector;
	int					type_of_point;
	struct s_sector		*next;
}						t_sector;

typedef struct 			s_commands
{ 
	int					type;
	struct s_commands	*next;
}						t_commands;

typedef struct			s_sprite
{
	int					type;
	int					x;
	int					y;
	struct s_sprite		*next;
}						t_sprite;

typedef struct			s_sdl
{
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Event			window_event;
	SDL_Point			mouse_position;
	int					sect_count;
	int					type_pressed;
	struct s_point		grid_field[GRID_SIZE];
	struct s_sector		*sectors;
	struct s_commands	*commands;
	struct s_point		*player;
	struct s_sprite		*sprites;
}						t_sdl;

void					init_sdl(t_sdl *sdl);
void					init_grid(t_point *grid_field);
t_sector				*init_sector();
void					init_player(t_sdl *sdl);
void					big_loop(t_sdl *sdl);
void					save_the_grid(t_point *grid_field, int start_x, int start_y, int width, int height);
void					make_wall(t_sdl *sdl);
int						check_the_grid(t_point *grid_field, int x, int y);
void					redraw(t_sdl *sdl);
void					draw_sidebar(t_sdl *sdl);
void					draw_grid(t_sdl *sdl);
void					draw(t_sdl *sdl);
void					draw_a_sector(t_sdl *sdl, t_sector *sector, int i);
void					draw_a_point(t_sdl *sdl, t_point *point, int i);
void					remove_last_point(t_sector **head);
void					reset(t_sector **head);
void					delete_last_command(t_sdl *sdl);
void					add_command(t_commands **commands, int type);
t_sector				*get_last_sector(t_sector *head);
//void					choose_type_of_point(t_sector **stuffbox, sdl->window_event.key.keysym.sym); // узнать типа данных ки эвента
void					choose_type_of_point(t_sector **stuffbox, int type);
void					make_player_or_sprite(t_sdl *sdl);
void					set_sprite(t_sdl *sdl);

#endif
