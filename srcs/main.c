/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhalit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 00:09:53 by mhalit            #+#    #+#             */
/*   Updated: 2017/09/24 15:47:22 by jribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	display_args(void)
{
	ft_putstr("\nusage: rtv1 [-s source] [-w width] [-h height]\n");
	ft_putstr("-s : Set the specified source file\n");
	ft_putstr("-w : Width of the window, default 500px\n");
	ft_putstr("-h : Height of the window, default 500px\n");
	ft_putstr("--help : Show help\n");
	ft_putstr("-a : Set the antialiasing technique to the image\n");
	exit(42);
}

void		init_rt(t_rt *e)
{
	e->mlx.init = mlx_init();
	e->file.larg = 1024;
	e->file.haut = 768;
	e->file.reso = 2;
	e->scene.nbr_obj = 0;
	e->scene.nbr_light = 0;
	e->scene.nbr_tot = 0;
	e->scene.ambient = 0;
	e->scene.obj = (t_obj *)malloc(sizeof(t_obj) * MAXOBJ);
	e->scene.lights = (t_light *)malloc(sizeof(t_light) * MAXLIGHT);
	e->scene.supersampling = 1;
	e->scene.filters = 0;
	e->scene.cam.aspect = (float)LARGEUR / (float)HAUTEUR;
}

void ft_start_rt(t_rt *e)
{
	if (!HAUTEUR || !LARGEUR)
		exit(0);
	e->mlx.window = mlx_new_window(e->mlx.init, e->file.larg, e->file.haut, "RT Again");
	IMG = mlx_new_image(INIT, LARGEUR, HAUTEUR);
	e->mlx.data = mlx_get_data_addr(IMG, &e->mlx.bpp, &e->mlx.size_l,
	&e->mlx.endian);
	frame(e);
	mlx_key_hook(e->mlx.window, key_hook, e);
	//mlx_mouse_hook(WIN, mouse_hook, e);
	
	mlx_loop(INIT);
}

void			create_limits(t_rt *e)
{
	int			i;
	int			chk;

	i = 0;
	chk = 0;
	while (i < e->scene.nbr_obj)
	{
		e->COBJ.plimit_active = 0;
		e->COBJ.plimit_valid = 0;
		e->COBJ.plimit = NULL;
		if (e->COBJ.type == SPHERE && chk == 0)
		{
			e->COBJ.plimit_type = 0;
			e->COBJ.plimit_active = 1;
			e->COBJ.plimit = (t_obj *)malloc(sizeof(t_obj) + 1);
			e->COBJ.plimit->is_init = 1;
			e->COBJ.plimit->type = PLANE;
			e->COBJ.plimit->color = e->COBJ.color;
			e->COBJ.plimit->pos = vec_new3(750, 400, 300);
			e->COBJ.plimit->dir = vec_new3(0, 0, 0);
			e->COBJ.plimit->angle = 0;
			e->COBJ.plimit->vector = vec_new3(0, 0, 0);
			e->COBJ.plimit->maxp = vec_new3(0, 0, 0);
			e->COBJ.plimit->minp = vec_new3(0, 0, 0);
			e->COBJ.plimit->r = 0;
			e->COBJ.plimit->t = -1;
			e->COBJ.plimit->normal = vec_new3(0, 1, 1);
			e->COBJ.plimit->mat = create_matiere();
			e->COBJ.plimit->plimit_active = 0;
			chk = 1;
		}
		++i;
	}
}

int			main(int argc, char **argv)
{
	t_rt	*e;

	e = (t_rt *)malloc(sizeof(t_rt));
	init_rt(e);
	if (argc > 2)
	{
		if (!parse_args(argv, argc, e))
			return (0);
		create_limits(e);
		ft_start_rt(e);
	}
	else
		display_args();
	 	//ft_gtk_start(e, argc, argv);

	return (0);
}
