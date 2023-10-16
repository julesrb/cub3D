#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "MLX42.h"
# include <stdlib.h>
# include <errno.h>
# define OFFSET 10
# define UNIT 27
# define UNIT_3D 100
# define PI 3.1415926535
# define HEIGHT 700
# define WIDTH 700

// read map
// allocate map
// isolate line function

typedef struct point
{
	int		x;
	int		y;
	int		color;
}	t_point;

typedef struct cub3d
{
	int 			res_x;
	int				res_y;

	double			pos_x;
	double			pos_y;
	double			pos_angle;
	double			pos_dx;
	double			pos_dy;
	t_point			pos_char;
	t_point			pos_wall;

	mlx_image_t		*minimap;
	mlx_image_t		*background;
	mlx_image_t		*viewport;
	mlx_t			*mlx;

	char			**map;
	int				m_size_x;
	int				m_size_y;
	
	mlx_texture_t		*text_N;
	mlx_texture_t		*text_S;
	mlx_texture_t		*text_W;
	mlx_texture_t		*text_E;
	float				w_d_offset;

	mlx_image_t 		*N;
	mlx_image_t 		*S;
	mlx_image_t 		*E;
	mlx_image_t 		*W;

	int				color_C;
	int				color_F;

}	t_cub3d;

void	terminate(char *str);

// draw.c
void	draw_tile(t_cub3d *cub3d, int x, int y, unsigned int color);
void	draw_character(t_cub3d *cub3d, unsigned int color);
void	draw_minimap_background(t_cub3d *cub3d);
int		parse_map(char *file, t_cub3d *cub3d);
void	ft_free_tab(char **tab);
void	calc_grad_steps(int i, int cl_a, int cl_b, float rgba[4]);
int		calc_grad_color(int steps, int cl_a, float rgba[4]);
void	draw_line(t_point point_a, t_point point_b, mlx_image_t *fdf);
void	draw_line_down(t_point a, t_point b, mlx_image_t *fdf);
void	draw_line_up(t_point a, t_point b, mlx_image_t *fdf);
void	draw_viewport(t_cub3d *cub3d);
void	draw_background(t_cub3d *cub3d);


int	calc_pix_color(int steps, mlx_image_t *text, int x, int l_height);
void my_keyhook(mlx_key_data_t keydata, void *param);

#endif