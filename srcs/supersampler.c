/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersampler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 09:45:23 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/08/14 21:59:08 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	anti_supersampler(t_rt *env)
{
	int		x;
	int		x1;

	x = 0;
	x1 = LARGEUR * HAUTEUR;
	while (x < x1)
	{
		((unsigned int *)env->mlx.data)[x] = env->img_temp[x];
		x++;
	}
}

void	super_sampler(t_rt *env)
{
	int		x;
	int		y;
	int		x1;
	int		y1;

	y = 0;
	y1 = 0;
	while (y < HAUTEUR / 2)
	{
		x = 0;
		x1 = 0;
		while (x < LARGEUR / 2)
		{
			((unsigned int *)env->mlx.data)[x + y * LARGEUR / 2] = AVERAGE(
				AVERAGE(env->img_temp[x1 + y1 * LARGEUR],
					env->img_temp[(x1 + 1) + (y1 * LARGEUR)]),
				AVERAGE(env->img_temp[x1 + (y1 + 1) * LARGEUR],
					env->img_temp[(x1 + 1) + (y1 + 1) * LARGEUR]));
			x1 += 2;
			x++;
		}
		y++;
		y1 += 2;
	}
}
