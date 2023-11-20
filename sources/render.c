/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:55:32 by jubernar          #+#    #+#             */
/*   Updated: 2023/01/06 15:55:35 by jubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_viewport(t_cub3d *cub3d)
{
	draw_ceiling(cub3d);
	draw_floor(cub3d);
	draw_game(cub3d);
	mlx_image_to_window(cub3d->mlx, cub3d->viewport, 0, 0);
}

void	render(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	draw_minimap(cub3d);
	render_viewport(cub3d);
}
