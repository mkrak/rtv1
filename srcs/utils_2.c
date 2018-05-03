/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:46:17 by cballest          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/05/03 20:25:57 by clanier          ###   ########.fr       */
=======
/*   Updated: 2018/05/03 19:37:52 by cballest         ###   ########.fr       */
>>>>>>> e03ddac2f6dc25897b5fc3676b58d1f89fc65327
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

t_obj	*get_obj(t_obj **start, size_t n)
{
	t_obj	*obj;

	obj = *start;
	while (n-- > 0)
		obj = obj->next;
	return (obj);
}

t_obj	*get_light_by_id(t_obj *obj, size_t n)
{
	while (obj)
	{
		if (obj->attr.id == OBJ_LIGHT && n-- <= 0)
			return (obj);
		obj = obj->next;
	}
	return (NULL);
}

void	get_n_obj(t_obj **start, int *nb_obj, int *nb_luz)
{
	t_obj	*obj;

	if (nb_obj)
		*nb_obj = 0;
	if (nb_luz)
		*nb_luz = 0;
	obj = *start;
	while (obj)
	{
		if (nb_luz && obj->attr.id == OBJ_LIGHT)
			(*nb_luz)++;
		else if (nb_obj)
			(*nb_obj)++;
		obj = obj->next;
	}
}
