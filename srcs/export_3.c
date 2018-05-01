/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:44:07 by cballest          #+#    #+#             */
/*   Updated: 2018/05/01 16:44:17 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	export_header_init(t_export *e)
{
	e->type = 19778;
	e->fsize = H * W * 4 + 40 + 14;
	e->reserved1 = 0;
	e->reserved2 = 0;
	e->offset = 40 + 14;
	e->hsize = 40;
	e->width = W;
	e->height = H;
	e->plane = 1;
	e->bpp = 32;
	e->compression = 0;
	e->isize = W * H * 4;
	e->resx = 0;
	e->resy = 0;
	e->clrusd = 0;
	e->clrimp = 0;
}

void	export_header_write(t_export *e, int fd)
{
	write(fd, (char *)&e->type, 2);
	write(fd, (char *)&e->fsize, 4);
	write(fd, (char *)&e->reserved1, 2);
	write(fd, (char *)&e->reserved2, 2);
	write(fd, (char *)&e->offset, 4);
	write(fd, (char *)&e->hsize, 4);
	write(fd, (char *)&e->width, 4);
	write(fd, (char *)&e->height, 4);
	write(fd, (char *)&e->plane, 2);
	write(fd, (char *)&e->bpp, 2);
	write(fd, (char *)&e->compression, 4);
	write(fd, (char *)&e->isize, 4);
	write(fd, (char *)&e->resx, 4);
	write(fd, (char *)&e->resy, 4);
	write(fd, (char *)&e->clrusd, 4);
	write(fd, (char *)&e->clrimp, 4);
}

void	export_file(t_control *l)
{
	int			fd;
	int			x;
	int			y;
	t_export	e;

	y = H;
	x = W * H * 4 - W * 4;
	fd = open(l->coef->name, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
	export_header_init(&e);
	export_header_write(&e, fd);
	while (y >= 0)
	{
		while (x < W * y * 4)
		{
			write(fd, (char *)&l->coef->data[x], 1);
			x++;
		}
		x -= W * 8;
		y--;
	}
	close(fd);
}
