/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:46:17 by cballest          #+#    #+#             */
/*   Updated: 2018/05/02 20:48:29 by lgautier         ###   ########.fr       */
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
	l->current = l->obj;
	while (l->current)
	{
		inter = intersec(i, l->obj[i].q, r.origin, r.dir, l);
		if (t.t == 0 && inter.t != 0)
			t = inter;
		else if (inter.t < t.t && inter.t != 0)
			t = inter;
		l->current = l->current->next;
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

t_obj		*get_obj(t_obj **start, size_t n)
{
	int		i;
	t_obj	*obj;

	i = 0;
	obj = *start;
	while (i < n)
	{
		obj = obj->next;
		n--;
	}
	return (obj);
}

size_t		get_n_obj(t_obj **start)
{
	size_t	i;
	t_obj	*obj;

	i = 0;
	obj = *start;
	while (obj->next)
	{
		obj = obj->next;
		i++;
	}
	return (i);
}

void    free_object_by_id(t_obj **obj, int id)
{
    t_obj    *tmp;
    t_obj    *tmp2;

    if (!(tmp = *obj))
        return ;
    if (!id)
    {
        *obj = tmp->next;
        free(tmp);
        return ;
    }
    while (--id && tmp)
        tmp = tmp->next;
    if (!tmp || !tmp->next)
        return ;
    tmp2 = tmp->next;
    tmp->next = tmp2->next;
    free(tmp2);
}
