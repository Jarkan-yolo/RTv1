/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:18:21 by bbeldame          #+#    #+#             */
/*   Updated: 2017/08/15 11:46:31 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	mv_left(t_rt *e)
{
	e->scene.cam.ray.pos.x -= 200;
	frame(e);
	mlx_put_image_to_window(e->mlx.init, e->mlx.window, e->mlx.image, 0, 0);
}

void	mv_right(t_rt *e)
{
	e->scene.cam.ray.pos.x += 200;
	frame(e);
	mlx_put_image_to_window(e->mlx.init, e->mlx.window, e->mlx.image, 0, 0);
}

void	mv_up(t_rt *e)
{
	e->scene.cam.ray.pos.y -= 200;
	frame(e);
	mlx_put_image_to_window(e->mlx.init, e->mlx.window, e->mlx.image, 0, 0);
}

void	mv_down(t_rt *e)
{
	e->scene.cam.ray.pos.y += 200;
	frame(e);
	mlx_put_image_to_window(e->mlx.init, e->mlx.window, e->mlx.image, 0, 0);
}

int		key_hook(int keycode, t_rt *e)
{
	if (keycode == ESC)
		exit(1);
	if (keycode == 123)
		mv_left(e);
	if (keycode == 124)
		mv_right(e);
	if (keycode == 126)
		mv_up(e);
	if (keycode == 125)
		mv_down(e);
	ft_putnbr(keycode);
	return (1);
}
