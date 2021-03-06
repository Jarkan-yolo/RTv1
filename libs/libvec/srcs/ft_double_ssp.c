/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_ssp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 09:40:25 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/14 22:14:47 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3d		vec_mul3d(t_vec3d u, t_vec3d v)
{
	t_vec3d		pts;

	pts.x = u.x * v.x;
	pts.y = u.y * v.y;
	pts.z = u.z * v.z;
	return (pts);
}

t_vec3d		vec_div3d(t_vec3d u, t_vec3d v)
{
	t_vec3d		pts;

	pts.x = u.x / v.x;
	pts.y = u.y / v.y;
	pts.z = u.z / v.z;
	return (pts);
}

t_vec3d		vec_add3d(t_vec3d u, t_vec3d v)
{
	t_vec3d		pts;

	pts.x = u.x + v.x;
	pts.y = u.y + v.y;
	pts.z = u.z + v.z;
	return (pts);
}

t_vec3d		vec_sub3d(t_vec3d u, t_vec3d v)
{
	t_vec3d		pts;

	pts.x = u.x - v.x;
	pts.y = u.y - v.y;
	pts.z = u.z - v.z;
	return (pts);
}

t_vec3d		vec_scale3d(t_vec3d u, double r)
{
	return ((t_vec3d){u.x * r, u.y * r, u.z * r, u.m});
}
