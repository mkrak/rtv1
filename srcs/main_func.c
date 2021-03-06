/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:10:15 by cballest          #+#    #+#             */
/*   Updated: 2018/05/03 22:28:23 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	exit_error(const char *err)
{
	printf("\033[31;1m[RT] \033[0m%s\n", err);
	exit(-1);
}

void	hooks(t_control lll)
{
	mlx_hook(lll.coef->win, 6, (1L << 6), main_mouse_hook_not, &lll);
	mlx_mouse_hook(lll.coef->win, main_mouse_hook, &lll);
	mlx_hook(lll.coef->win, 2, (1L << 0), &key_p, &lll);
	mlx_hook(lll.coef->win, 3, (1L << 1), &key_r, &lll);
	mlx_hook(lll.coef->win, 17, 0L, &quit, lll.coef);
	mlx_loop_hook(lll.coef->mlx, main_loop, &lll);
	mlx_loop(lll.coef->mlx);
}

int		main_mallocs(t_control *lll, int ac, char *file, char **av)
{
	if (ac != 2)
		exit_error(ERR_USAGE);
	if (!(file = get_file(av[1])))
		exit_error(ERR_FILE);
	if (!(lll->coef = (t_coef*)malloc(sizeof(t_coef))))
		return (-1);
	if (!(lll->l = (t_luz*)malloc(sizeof(t_luz) * lll->nb_luz)))
	{
		free(lll->coef);
		return (-1);
	}
	if (!(lll->obj = handle_scene(file)))
	{
		free(file);
		free(lll->l);
		free(lll->coef);
		return (-1);
	}
	free(file);
	return (0);
}
