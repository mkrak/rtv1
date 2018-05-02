/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:46:17 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 16:46:25 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ft_logo(t_coef *t)
{
	void	*img;
	int		w;
	int		h;

	img = NULL;
	img = mlx_xpm_file_to_image(t->mlx, "ressources/img/logo.xpm", &w, &h);
	if (img == NULL)
		ft_putendl("ERROR");
	mlx_put_image_to_window(t->mlx, t->win, img, W / 2 - w / 2, H / 2 - h / 2);
}

void	fill_menu(t_coef *t, void *win)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(t->mlx, "ressources/img/SPHERE.XPM", &w, &h);
	mlx_put_image_to_window(t->mlx, win, img, 125 - w / 2, 15);
	img = mlx_xpm_file_to_image(t->mlx, "ressources/img/PLAN.XPM", &w, &h);
	mlx_put_image_to_window(t->mlx, win, img, 125 - w / 2, 15 + 85);
	img = mlx_xpm_file_to_image(t->mlx, "ressources/img/CYLINDRE.XPM", &w, &h);
	mlx_put_image_to_window(t->mlx, win, img, 125 - w / 2, 15 + 85 * 2);
	img = mlx_xpm_file_to_image(t->mlx, "ressources/img/CONE.XPM", &w, &h);
	mlx_put_image_to_window(t->mlx, win, img, 125 - w / 2, 15 + 85 * 3);
}

int		rt_search(int x, int y, t_control *l)
{
	double	fov;
	int		i;
	t_inter	t;
	t_inter	inter;
	t_ray	r;

	fov = 60 * M_PI / 180;
	i = 0;
	t.t = 0;
	r.dir = normalize(vec3((x - W / 2 + 0.25), -(y - H / 2 + 0.25), -W / \
		(2 * tan(fov / 2))));
	r.dir = rotate_cam(r.dir, l->coef->rot_y, l->coef->rot_x, l->coef->rot_z);
	r.origin = vec3(l->coef->pos_y, l->coef->pos_z, l->coef->pos_x);
	while (i < l->nb_obj)
	{
		inter = intersec(i, l->obj[i].q, r.origin, r.dir, l);
		if (t.t == 0 && inter.t != 0)
			t = inter;
		else if (inter.t < t.t && inter.t != 0)
			t = inter;
		i++;
	}
	if (t.t != 0)
		return (t.id);
	return (-1);
}

void	obj_realloc(t_control *l)
{
	t_obj	*swap;
	int		i;

	i = 0;
	l->coef->total++;
	swap = (t_obj*)malloc(sizeof(t_obj) * l->nb_obj);
	while (i < l->nb_obj)
	{
		swap[i] = l->obj[i];
		i++;
	}
	i = 0;
	free(l->obj);
	l->nb_obj++;
	l->obj = (t_obj*)malloc(sizeof(t_obj) * l->nb_obj);
	while (i < l->nb_obj - 1)
	{
		l->obj[i] = swap[i];
		i++;
	}
	l->coef->cur = l->nb_obj - 1;
	free(swap);
}
