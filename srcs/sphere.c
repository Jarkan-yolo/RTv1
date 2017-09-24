/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:04:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/09/24 15:21:03 by jribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	get_res_of_quadratic(float a, float b, float c, char *select)
{
	float	t0;
	float	t1;
	float	determinant;

	determinant = b * b - 4 * a * c;
	if (determinant < 0)
		return (DIST_MAX);
	if (determinant == 0)
		return (-b / (2 * a));
	determinant = sqrt(determinant);
	t0 = (-b + determinant) / (2 * a);
	t1 = (-b - determinant) / (2 * a);
	if (ft_strcmp(select, "lowdist") == 0)
		return ((t0 > t1) ? t1 : t0);
	if (ft_strcmp(select, "highdist") == 0)
		return ((t0 > t1) ? t0 : t1);
	return (DIST_MAX);
}

float	intensity_sphere(t_vec3 poi, t_obj sphere, t_light light)
{
	float		dist_to_light;
	t_vec3		vec_to_eyes;
	t_vec3		vec_to_light;
	float		intensity;

	vec_to_eyes = vec_norme3(vec_sub3(poi, sphere.pos));
	vec_to_light = vec_sub3(light.ray.pos, poi);
	dist_to_light = get_length(vec_to_light);
	intensity = (vec_dot3(vec_to_eyes, vec_norme3(vec_to_light)) *
		ft_map(dist_to_light, 1200 * light.intensity, 470, 350));
	return (intensity);
}

/*
** Implementation of :
** http://hugi.scene.org/online/hugi24/index%20coding%20&%20maths.htm
*/

float	intersect_sphere(t_ray ray, t_obj *sphere)
{
	float		plimit_dist;
	float		sphere_lowdist;
	float		sphere_highdist;
	float		a;
	float		b;
	float		c;
	t_vec3		x;

	ray.dir = vec_norme3(ray.dir);
	x = vec_sub3(ray.pos, sphere->pos);
	a = vec_dot3(ray.dir, ray.dir);
	b = 2 * vec_dot3(ray.dir, x);
	c = vec_dot3(x, x) - (sphere->r * sphere->r);
	sphere_lowdist = get_res_of_quadratic(a, b, c, "lowdist");
	sphere_highdist = get_res_of_quadratic(a, b, c, "highdist");
	if (sphere->plimit_active == 0)
		return (sphere_lowdist);
	else
	{
		plimit_dist = intersect_plane(ray, *(sphere->plimit));
		if (sphere_lowdist == DIST_MAX)
			return (DIST_MAX);
		if (sphere->plimit_type == 0) // PLIMIT_BACK
		{
			if (sphere_lowdist < plimit_dist)
				return (sphere_lowdist);
			else
				return (DIST_MAX);
		}
		else                         // PLIMIT_FRONT
		{
			if (sphere_lowdist < plimit_dist)
			{
				sphere->plimit_valid = (sphere_highdist < plimit_dist) ? 0 : 1;
				return ((sphere_highdist < plimit_dist) ? DIST_MAX : plimit_dist);
			}
			else
				return (sphere_lowdist);
		}
	}
}
