/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ocl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 02:51:19 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/15 11:45:11 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_color			c_color(float r, float g, float b)
{
	t_color		color;

	color.r = ft_map(r, 255, 0, 0.5);
	color.g = ft_map(g, 255, 0, 0.5);
	color.b = ft_map(b, 255, 0, 0.5);
	return (color);
}

t_matiere	create_matiere(void)
{
	t_matiere	mat;

	mat.amb = 0;
	mat.reflex = 0;
	mat.specular = 0;
	mat.opacite = 1;
	return (mat);
}

int			camera_create(t_rt *env)
{
	env->scene.cam.ray.pos = vec_new3(0, 0, -2000);
	env->scene.cam.ray.dir = vec_new3(0, 0, 1);
	env->scene.cam.focale = 1;
	env->scene.cam.reso = 300;
	return (1);
}

int			create_obj(int type, t_rt *env)
{
	int		i;

	i = env->scene.nbr_obj;
	env->COBJ.is_init = 1;
	env->COBJ.type = type;
	env->COBJ.color = c_color(255, 255, 255);
	env->COBJ.pos = vec_new3(0, 0, 0);
	env->COBJ.dir = vec_new3(0, 0, 0);
	env->COBJ.size = 0;
	env->COBJ.maxp = vec_new3(0, 0, 0);
	env->COBJ.minp = vec_new3(0, 0, 0);
	env->COBJ.r = 0;
	env->COBJ.t = -1;
	env->COBJ.mat = create_matiere();
	env->scene.nbr_obj++;
	return (1);
}

int			create_light(t_rt *env)
{
	int		i;

	i = env->scene.nbr_light;
	env->CLIGHT.is_init = 1;
	env->CLIGHT.ray.pos = vec_new3(0, 0, 0);
	env->CLIGHT.ray.dir = vec_new3(0, 0, 0);
	env->CLIGHT.color = c_color(255, 255, 255);
	env->CLIGHT.intensity = 0;
	env->scene.nbr_light++;
	return (1);
}
