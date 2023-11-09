/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbussier <gbussier@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:51 by gbussier          #+#    #+#             */
/*   Updated: 2023/11/08 18:24:53 by gbussier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	win_close(void *param)
{
	mlx_delete_image(((t_cub3d *)param)->mlx, ((t_cub3d *)param)->viewport);
	mlx_terminate(((t_cub3d *)param)->mlx);
	exit(EXIT_SUCCESS);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		moving_up(cub3d);
	else if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		moving_down(cub3d);
	else if ((keydata.key == MLX_KEY_A) && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		moving_left(cub3d);
	else if ((keydata.key == MLX_KEY_D) && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		moving_right(cub3d);
	else if ((keydata.key == MLX_KEY_LEFT) && (keydata.action == MLX_REPEAT
			|| keydata.action == MLX_PRESS))
		rotating_left(cub3d);
	else if ((keydata.key == MLX_KEY_RIGHT || keydata.key == 68)
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		rotating_right(cub3d);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		win_close(param);
}