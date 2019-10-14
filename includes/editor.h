/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:59:27 by djast             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/10 17:01:34 by djast            ###   ########.fr       */
=======
/*   Updated: 2019/10/10 14:33:33 by eharrag-         ###   ########.fr       */
>>>>>>> 725e4d1643fc5941c3cf78feafca59c5b30be3d0
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
	int					sect_count;

}						t_sdl;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_sector
{
	int					id;
	t_point				point[100];
	int					size;
	struct s_sector		*next;
	int					contact_sector_id;
	int					count_contact;
}						t_sector;

void					init_sdl(t_sdl *sdl);
void					init_grid(t_point *grid_field);
t_sector				*init_sector(int id);
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
void					remove_last_point(t_sdl *sdl, t_sector *head, t_point *grid_field, t_sector **sector);

#endif
