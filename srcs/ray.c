/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:55:55 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/15 11:49:44 by mhalit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

float	get_length(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_ray		c_ray(t_vec3 i, t_vec3 j)
{
	t_ray	ray;

	ray.pos = vec_new3(i.x, i.y, i.z);
	ray.dir = vec_new3(j.x, j.y, j.z);
	return (ray);
}
