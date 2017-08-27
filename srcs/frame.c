/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 05:21:15 by mhalit            #+#    #+#             */
/*   Updated: 2017/08/27 23:37:23 by jribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	mlx_pixel(int x, int y, t_rt *env, int color)
{
	int		pos;

	if (x && y && x < LARGEUR && y < HAUTEUR)
	{
		pos = x * 4 + y * env->mlx.size_l;
		env->mlx.data[pos] = color;
		env->mlx.data[pos + 1] = color >> 8;
		env->mlx.data[pos + 2] = color >> 16;
	}
}

void	*drawline(void *arg)
{
	t_rt		*env;
	int			x;
	int			i;

	env = (t_rt *)arg;
	env->colors =
		malloc(HAUTEUR * LARGEUR * sizeof(t_color) + 20);
	i = 0;
	while (env->y < HAUTEUR)
	{
		x = 0;
		while (x < LARGEUR)
		{
			env->colors[i] = raytrace(x, env->y, env);
			++x;
			++i;
		}
		env->y += NB_THREADS;
	}
	return (NULL);
}

void	frame(t_rt *env)
{
	t_rt		**th_env;
	int			i;
	int			x;
	int			y;
	pthread_t	th[NB_THREADS];

	IMG = mlx_new_image(INIT, LARGEUR, HAUTEUR);
	env->mlx.data = mlx_get_data_addr(IMG, &env->mlx.bpp, &env->mlx.size_l,
		&env->mlx.endian);
	th_env = (t_rt **)malloc(NB_THREADS * sizeof(t_rt *));
	i = 0;
	while (i < NB_THREADS)
	{
		th_env[i] = copy_rt(env);
		th_env[i]->y = i;
		pthread_create(&th[i], NULL, drawline, (void *)th_env[i]);
		++i;
	}
	i = 0;
	while (i < NB_THREADS)
	{
		pthread_join(th[i], NULL);
		++i;
	}
	i = 0;
	while (i < NB_THREADS)
	{
		y = i;
		while (y < HAUTEUR)
		{
			x = 0;
			while (x < LARGEUR)
			{
				mlx_pixel(x, y, env,
				ret_colors(th_env[i]->colors[x + ((y / NB_THREADS) * LARGEUR)]));
				++x;
			}
			y += NB_THREADS;
		}
		++i;
	}
	mlx_put_image_to_window(INIT, WIN, IMG, 0, 0);
/*	int		x;
	int		y;

	y = 0;
	IMG = mlx_new_image(INIT, LARGEUR, HAUTEUR);
	env->mlx.data = mlx_get_data_addr(IMG, &env->mlx.bpp, &env->mlx.size_l,
		&env->mlx.endian);
	while (y < HAUTEUR)
	{
		x = 0;
		while (x < LARGEUR)
		{
			raytrace(x, y, env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(INIT, WIN, IMG, 0, 0);*/
}
