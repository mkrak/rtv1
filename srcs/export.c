/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:37:55 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 15:37:57 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	expand_name(t_control *l, char c)
{
	char	*swap;

	if (!(l->coef->name))
	{
		l->coef->name = malloc(sizeof(char) * 2);
		l->coef->name[0] = c;
		l->coef->name[1] = '\0';
	}
	else
	{
		swap = malloc(sizeof(char) * (ft_strlen(l->coef->name) + 1));
		swap = ft_strdup(l->coef->name);
		swap[ft_strlen(l->coef->name)] = '\0';
		l->coef->name = malloc(sizeof(char) * (ft_strlen(l->coef->name) + 2));
		l->coef->name = ft_strdup(swap);
		l->coef->name[ft_strlen(swap)] = c;
		l->coef->name[ft_strlen(swap) + 1] = '\0';
		free(swap);
	}
	mlx_string_put(l->coef->mlx, l->coef->win_rename, 10, 10, 0x00ffffff, \
		l->coef->name);
}

void	trunc_name(t_control *l)
{
	char	*swap;
	int		i;

	i = 0;
	if (l->coef->name && ft_strlen(l->coef->name) > 0)
	{
		swap = malloc(sizeof(char) * ft_strlen(l->coef->name));
		while (i < (int)ft_strlen(l->coef->name) - 1)
		{
			swap[i] = l->coef->name[i];
			i++;
		}
		swap[i] = '\0';
		l->coef->name = malloc(sizeof(swap));
		l->coef->name = ft_strdup(swap);
		l->coef->name[i] = '\0';
		free(swap);
		mlx_string_put(l->coef->mlx, l->coef->win_rename, 10, 10, 0x00ffffff, \
			l->coef->name);
	}
}

void	refresh_name(t_control *l)
{
	t_img	img;

	img.img = mlx_new_image(l->coef->mlx, 500, 100);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win_rename, img.img, 0, 0);
	mlx_destroy_image(l->coef->mlx, img.img);
}

int		hook_rename(int k, t_control *l)
{
	refresh_name(l);
	if ((!OS && (k >= 'a' && k <= 'z')))
		expand_name(l, k);
	if (OS)
		hook_mac_rename(l, k);
	if (k == K_ESC)
	{
		ft_strdel(&l->coef->name);
		mlx_destroy_window(l->coef->mlx, l->coef->win_rename);
	}
	if (k == K_ENTER)
	{
		l->coef->name = ft_strjoin(l->coef->name, ".bmp");
		l->coef->name = ft_strjoin("export/", l->coef->name);
		export_file(l);
		ft_strdel(&l->coef->name);
		mlx_destroy_window(l->coef->mlx, l->coef->win_rename);
	}
	return (k);
}

void	rename_win(t_control *l)
{
	l->coef->win_rename = mlx_new_window(l->coef->mlx, 500, 100, "Name");
	mlx_key_hook(l->coef->win_rename, hook_rename, l);
}
