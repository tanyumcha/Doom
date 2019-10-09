/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:59:27 by djast             #+#    #+#             */
/*   Updated: 2019/10/08 13:01:53 by eharrag-         ###   ########.fr       */
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

typedef struct			s_sdl
{
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Event			window_event;
	SDL_Point			mouse_position;
}						t_sdl;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_sector
{
	t_point				point[100];
	int					size;
	struct s_sector		*next;
}						t_sector;

void					init_sdl(t_sdl *sdl);
void					init_grid(t_point *grid_field);
t_sector				*init_sector();
void					big_loop(t_sdl *sdl, t_point *grid_field, t_sector *head, t_sector *sector);
void					save_the_grid(t_point *grid_field, int start_x, int start_y, int width, int height);
void					take_a_lap(t_sdl *sdl, t_point *grid_field, t_sector *head, t_sector **sector);
int						check_the_grid(t_point *grid_field, int x, int y);
void					redraw(t_sdl *sdl, t_point *grid_field);
void					draw_sidebar(t_sdl *sdl);
void					draw_grid(t_sdl *sdl, t_point *grid_field);
void					draw_verts(t_sdl *sdl, t_point *grid_field);
void					draw_hors(t_sdl *sdl, t_point *grid_field);
void					draw(t_sdl *sdl, t_sector *head, t_point *grid_field);
void					draw_a_sector(t_sdl *sdl, t_sector *sector, int i);
void					draw_a_point(t_sdl *sdl, t_point *point, int i);

#endif
