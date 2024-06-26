/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:18:05 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/09 13:18:08 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <fcntl.h>

# include <sys/types.h>
# include <signal.h>
# include <pulse/simple.h>
# include <pulse/error.h>
# include <sys/types.h>
# include <sys/wait.h>

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "MLX42.h"
# include <stdlib.h>
# include <errno.h>
# define OFFSET 1
# define SIZEMINIMAP 10
# define STEP 0.2
# define ROTSPD 0.04
# define GHEIGHT 850
# define NUMSPRITES 3

typedef struct sprite
{
	double	x;
	double	y;
	int		flag;
}	t_sprite;

typedef struct cub3d
{
	int				res_x;
	int				res_y;

	pid_t			music_pid;
	FILE			*file;
	pa_simple		*pa_stream;
	pa_sample_spec	sample_spec;

	double			posx;
	double			posy;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			side_dist_y;
	double			side_dist_x;
	double			delta_dist_y;
	double			delta_dist_x;
	int				step_x;
	int				step_y;
	char			side;
	int				ray;
	int				hit;
	int				line_height;
	double			perp_wall_dist;
	double			wall_x;

	char			*door;
	int				door_hit;
	int				door_line_height;
	double			door_perp_wall_dist;
	double			door_wall_x;
	int				door_open;
	int				door_open_start;
	int				key_nb;

	mlx_image_t		*viewport;
	mlx_image_t		*intro;
	mlx_image_t		*background;
	mlx_image_t		*minimap;
	mlx_image_t		*sprite_img;
	mlx_t			*mlx;

	int				frame;
	int				key_frame;

	t_sprite		sprite[3];
	double			zbuffer[WIDTH];
	int				spriteorder[3];
	int				nb_sprite;
	int				flag2;

	double			sprite_x;
	double			sprite_y;
	double			invdet;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				sprite_width;

	char			**map;
	char			**map_check;
	int				map_line;
	int				m_size_x;
	int				m_size_y;
	int				wall_height;
	int				minimap_on;

	mlx_image_t		*t_n;
	mlx_image_t		*t_s;
	mlx_image_t		*t_e;
	mlx_image_t		*t_w;

	mlx_image_t		*key1;
	mlx_image_t		*key2;
	mlx_image_t		*key3;
	mlx_image_t		*key4;
	mlx_image_t		*key5;
	mlx_image_t		*key6;
	mlx_image_t		*key7;

	mlx_image_t		*text1;
	int				mini_text;
	mlx_image_t		*text2;
	mlx_image_t		*text3;
	int				end;

	int				color_c;
	int				color_f;

	int				move_up;
	int				move_down;
	int				move_left;
	int				move_right;
	int				rotate_left;
	int				rotate_right;
}	t_cub3d;

// close.c
void		ft_free_tab(char **tab);
void		delete_img_cub3d(t_cub3d *cub3d);
void		terminate(char *str, t_cub3d *cub3d, int mlx, int map);

// color.c
void		calc_grad_steps(int i, int cl_a, int cl_b, float rgba[4]);
int			calc_pix_color(int steps, mlx_image_t *text, int x, int l_height);
int			calc_grad_color(int steps, int cl_a, float rgba[4]);
int			get_color_info(char *str);
void		draw_pixel(mlx_image_t *img, uint32_t x,
				uint32_t y, uint32_t color);

// draw_background.c
int			draw_sky(t_cub3d *cub3d);
int			draw_ceiling(t_cub3d *cub3d);
int			draw_floor(t_cub3d *cub3d);

// draw_character.c
void		draw_character(t_cub3d *cub3d, unsigned int color);

// draw_minimap.c
void		draw_tile(t_cub3d *cub3d, int x, int y, unsigned int color1);
void		init_minimap(t_cub3d *cub3d);
void		draw_minimap(t_cub3d *cub3d);

// draw_sprite.c
void		draw_sprite_motor(t_cub3d *cub3d, int stripe, int a, int b);
void		draw_sprite(t_cub3d *cub3d, int a, int b);
void		sprite_init(t_cub3d *cub3d, int i);
void		sprite_casting(t_cub3d *cub3d);

// draw_sprite_sort.c
int			max_double(double *spritedistance);
int			min_double(double *spritedistance);
void		sprite_find_order(t_cub3d *cub3d, int i,
				double *spritedistance, int j);
void		sort_sprite(t_cub3d *cub3d);
mlx_image_t	*key_frame_selector(t_cub3d *cub3d);

// draw_viewport.c
void		draw_line_textu(double line_height, int text_x_pos,
				mlx_image_t *text, t_cub3d *cub3d);
int			door_animation(t_cub3d *cub3d);
void		draw_door_line_textu(double line_height, int text_x_pos,
				mlx_image_t *text, t_cub3d *cub3d);
void		draw_game(t_cub3d *cub3d);

// keyhook_main.c
void		win_close(void *param);
void		my_keyhook_move(mlx_key_data_t keydata, t_cub3d	*cub3d);
void		my_keyhook_rotate(mlx_key_data_t keydata, t_cub3d *cub3d);
void		my_keyhook_other(mlx_key_data_t keydata, t_cub3d *cub3d);
void		my_keyhook(mlx_key_data_t keydata, void *param);

// keyhook_rotate.c
void		rotating_right(t_cub3d *cub3d);
void		rotating_left(t_cub3d *cub3d);
void		move_around(t_cub3d *cub3d);

// keyhook_moving.c
void		text_end(t_cub3d *cub3d);
void		moving_right(t_cub3d *cub3d);
void		moving_left(t_cub3d *cub3d);
void		moving_down(t_cub3d *cub3d);
void		moving_up(t_cub3d *cub3d);

// mousehook.c
void		my_mousehook(mouse_key_t button, action_t action,
				modifier_key_t mods, void *param);

// music.c
int			read_music(pa_simple *pa_stream, FILE *file, int error);
int			music_process(pa_simple *pa_stream, pa_sample_spec sample_spec);

// parse_info.c
int			line_to_map(int y, char *line, t_cub3d *cub3d);
int			info_to_struct(char *line, t_cub3d *cub3d);
int			all_info_read(t_cub3d *cub3d);
int			map_line(char *line);
int			read_info(char *file, t_cub3d *cub3d, char *line, char *trim);

// parse_main.c
void		parse_sprite(t_cub3d *cub3d, int i, int y);
int			copy_map(char *file, t_cub3d *cub3d);
void		floodfill(t_cub3d *cub3d, int y, int x, char new_val);
int			check_wall(char **map, t_cub3d *cub3d);
int			parse_map(char *file, t_cub3d *cub3d);

// parse_textures.c
void		load_textures_2(mlx_texture_t *texture,
				mlx_image_t **text, t_cub3d *cub3d, char **info);
void		load_textures(mlx_texture_t	*texture, t_cub3d *cub3d, char **info);
void		set_player_position(char map_char, int x, int y, t_cub3d *cub3d);

// parse_textures_sprite.c
void		load_key_text_1(t_cub3d *cub3d);
void		load_key_text_2(t_cub3d *cub3d);
void		load_key_text_3(t_cub3d *cub3d);

// parse_utlis.c
int			right_map_char(char c);
int			open_file_to_line(char *file, t_cub3d *cub3d);
int			read_map_size(char *file, t_cub3d *cub3d, int fd);
char		**allocate_map(int y, int x);
int			duplicate_map(t_cub3d *cub3d);

// raycaster_calculus.c
double		absol(double nombre);
void		raycaster_init(t_cub3d *cub3d);
void		raycaster_calculus(t_cub3d *cub3d);

// raycaster_main.c
void		finding_door(t_cub3d *cub3d);
void		finding_wall(t_cub3d *cub3d);
void		wall_distance(t_cub3d *cub3d);
void		doorcaster(t_cub3d *cub3d);
void		raycaster(t_cub3d *cub3d);

// render.c
void		render_background(t_cub3d *cub3d);
void		set_opacity(mlx_image_t *img, int alpha);
void		render_intro(t_cub3d *cub3d);
void		render_viewport(t_cub3d *cub3d);
void		render(void *param);

#endif
