/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:59:27 by djast             #+#    #+#             */
/*   Updated: 2019/10/19 12:16:30 by eharrag-         ###   ########.fr       */
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

# define COLOR_UNPUSHED 0
# define COLOR_PUSHED 1

# define WALL_TYPE 1
# define PLAYER_TYPE 2
# define SPRITE_TYPE 3

# define PLAYER_PUSH 0
# define MEDKIT_PUSH 1
# define SPRITE_PUSH 2
# define ARMOR_PUSH 3
# define POWER_UP_PUSH 4
# define RIFLE_AMMO_PUSH 5
# define PLASMA_GUN_PUSH 6
# define PLASMA_AMMO_PUSH 7
# define BARREL_PUSH 8
# define AFRIT_PUSH 9
# define CACODEMON_PUSH 10
# define IMP_PUSH 11
# define WALL_PUSH 12

# define BUTTON_PLAYER_X1 SIZE_WIN_X * 0.8 + SIZE_WIN_X * 0.2 * 0.1
# define BUTTON_PLAYER_Y1 SIZE_WIN_Y * 0.1 * 0.6
# define BUTTON_PLAYER_X2 BUTTON_PLAYER_X1 + SIZE_WIN_X * 0.2 * 0.6
# define BUTTON_PLAYER_Y2 BUTTON_PLAYER_Y1 + SIZE_WIN_Y * 0.05

# define BUTTON_MEDKIT_X1 BUTTON_PLAYER_X1
# define BUTTON_MEDKIT_Y1 BUTTON_PLAYER_Y1 * 2
# define BUTTON_MEDKIT_X2 BUTTON_PLAYER_X2
# define BUTTON_MEDKIT_Y2 BUTTON_MEDKIT_Y1 + SIZE_WIN_Y * 0.05

# define BUTTON_ARMOR_X1 BUTTON_PLAYER_X1
# define BUTTON_ARMOR_Y1 BUTTON_PLAYER_Y1 * 3
# define BUTTON_ARMOR_X2 BUTTON_PLAYER_X2
# define BUTTON_ARMOR_Y2 BUTTON_ARMOR_Y1 + SIZE_WIN_Y * 0.05

# define BUTTON_POWER_UP_X1 BUTTON_PLAYER_X1
# define BUTTON_POWER_UP_Y1 BUTTON_PLAYER_Y1 * 4
# define BUTTON_POWER_UP_X2 BUTTON_PLAYER_X2
# define BUTTON_POWER_UP_Y2 BUTTON_POWER_UP_Y1 + SIZE_WIN_Y * 0.05

# define BUTTON_RIFLE_AMMO_X1 BUTTON_PLAYER_X1
# define BUTTON_RIFLE_AMMO_Y1 BUTTON_PLAYER_Y1 * 5
# define BUTTON_RIFLE_AMMO_X2 BUTTON_PLAYER_X2
# define BUTTON_RIFLE_AMMO_Y2 BUTTON_RIFLE_AMMO_Y1 + SIZE_WIN_Y * 0.05

# define BUTTON_PLASMA_GUN_X1 BUTTON_PLAYER_X1
# define BUTTON_PLASMA_GUN_Y1 BUTTON_PLAYER_Y1 * 6
# define BUTTON_PLASMA_GUN_X2 BUTTON_PLAYER_X2
# define BUTTON_PLASMA_GUN_Y2 BUTTON_PLASMA_GUN_Y1 + SIZE_WIN_Y * 0.05

# define BUTTON_PLASMA_AMMO_X1 BUTTON_PLAYER_X1
# define BUTTON_PLASMA_AMMO_Y1 BUTTON_PLAYER_Y1 * 7
# define BUTTON_PLASMA_AMMO_X2 BUTTON_PLAYER_X2
# define BUTTON_PLASMA_AMMO_Y2 BUTTON_PLASMA_AMMO_Y1 + SIZE_WIN_Y * 0.05

# define BUTTON_BARREL_X1 BUTTON_PLAYER_X1
# define BUTTON_BARREL_Y1 BUTTON_PLAYER_Y1 * 8
# define BUTTON_BARREL_X2 BUTTON_PLAYER_X2
# define BUTTON_BARREL_Y2 BUTTON_BARREL_Y1 + SIZE_WIN_Y * 0.05

# define BUTTON_AFRIT_X1 BUTTON_PLAYER_X1
# define BUTTON_AFRIT_Y1 BUTTON_PLAYER_Y1 * 9
# define BUTTON_AFRIT_X2 BUTTON_PLAYER_X2
# define BUTTON_AFRIT_Y2 BUTTON_AFRIT_Y1 + SIZE_WIN_Y * 0.05

# define BUTTON_CACODEMON_X1 BUTTON_PLAYER_X1
# define BUTTON_CACODEMON_Y1 BUTTON_PLAYER_Y1 * 10
# define BUTTON_CACODEMON_X2 BUTTON_PLAYER_X2
# define BUTTON_CACODEMON_Y2 BUTTON_CACODEMON_Y1 + SIZE_WIN_Y * 0.05

# define BUTTON_IMP_X1 BUTTON_PLAYER_X1
# define BUTTON_IMP_Y1 BUTTON_PLAYER_Y1 * 11
# define BUTTON_IMP_X2 BUTTON_PLAYER_X2
# define BUTTON_IMP_Y2 BUTTON_IMP_Y1 + SIZE_WIN_Y * 0.05

# define BUTTON_WALL_X1 BUTTON_PLAYER_X1
# define BUTTON_WALL_Y1 BUTTON_PLAYER_Y1 * 12
# define BUTTON_WALL_X2 BUTTON_PLAYER_X2
# define BUTTON_WALL_Y2 BUTTON_WALL_Y1 + SIZE_WIN_Y * 0.05

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
	SDL_Surface			*surface;
	SDL_Event			window_event;
	SDL_Point			mouse_position;
	TTF_Font			*font;
	SDL_Texture			*text;
	int					sect_count;
	int					button_pushed;
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
t_sprite				*init_sprite();
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
void					delete_player(t_point *player);
void					remove_last_point(t_sector **head);
void					reset(t_sector **head, t_point	*player, t_sprite *sprites);
void					delete_last_command(t_sdl *sdl);
void					add_command(t_commands **commands, int type);
t_sector				*get_last_sector(t_sector *head);
t_sprite				*find_last_sprite(t_sprite *sprites);
SDL_Color				*create_sdl_color(int r, int g, int b, int a);
void					choose_type_of_point(t_sector **stuffbox, int type);
void					make_player_or_sprite(t_sdl *sdl);
int						check_intersection(t_sector *head, int x1, int y1, int x2, int y2);
void					set_sprite(t_sdl *sdl, int x, int y);

#endif
