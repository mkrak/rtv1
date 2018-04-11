#include "../includes/rt.h"

void	put_pixel_circle(t_img i, t_circle c, int x, int y)
{
	int		n;

	if (x >= (c.r * 2) || x < 0 || y >= (c.r * 2) || y < 0)
		return ;
	n = ((c.r * 2 - x - 1) * (c.r * 2) + y) * 4;
	i.data[n] = c.c.c[0];
	i.data[++n] = c.c.c[1];
	i.data[++n] = c.c.c[2];
	i.data[++n] = c.c.c[3];
}

void	mlx_image_to_alpha(t_img img, int n)
{
	int		i;

	i = 3;
	while (i <= n)
	{
		img.data[i] = 0xff;
		i += 4;
	}
}

void	mlx_circle(int x, int y, int r, t_img *img, t_coef *coef)
{
	t_circle	c;
	int			i;
	int			j;
	int			d;

	c.x = x;
	c.y = y;
	c.r = r;
	c.c.color = 0x00ff00ff;
	img->img = mlx_new_image(coef->mlx, (r * 2), (r * 2));
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->sl, &img->end);
	mlx_image_to_alpha(*img, ((r * 2) *(r * 2) * 4));
	while (c.r > 0)
	{
		i = 0;
		j = c.r;
		d = c.r - 1;
		while (j >= i)
		{
			put_pixel_circle(*img, c, y + i, x + j);
			put_pixel_circle(*img, c, y + j, x + i);
			put_pixel_circle(*img, c, y - i, x + j);
			put_pixel_circle(*img, c, y - j, x + i);
			put_pixel_circle(*img, c, y + i, x - j);
			put_pixel_circle(*img, c, y + j, x - i);
			put_pixel_circle(*img, c, y - i, x - j);
			put_pixel_circle(*img, c, y - j, x - i);
			if (d >= 2 * i)
			{
				d = d - 2 * i - 1;
				i++;
			}
			else if (d < 2 * (r - j))
			{
				d = d + 2 * j - 1;
				j--;
			}
			else
			{
				d = d + 2 * (j - i - 1);
				j--;
				i++;
			}
		}
		ft_putendl("bob");
		c.r--;
	}
}
void	put_pixel_rect(t_img i, t_rect r, int x, int y)
{
	int		n;

	if (x >= r.h || x < 0 || y >= r.w || y < 0)
		return ;
	n = ((r.h - x - 1) * r.w + y) * 4;
	i.data[n] = r.c.c[0];
	i.data[++n] = r.c.c[1];
	i.data[++n] = r.c.c[2];
}

void	mlx_rect(t_rect rect, t_coef *coef)
{
	t_img	img;
	int		x;
	int		y;

	img.img = mlx_new_image(coef->mlx, rect.w, rect.h);
	img.data = mlx_get_data_addr(img.img, &img.bpp, &img.sl, &img.end);
	y = 0;
	while (y <= rect.h)
	{
		x = 0;
		while (x <= rect.w)
		{
			if ((x >= 0 && x <= rect.border) || (x <= rect.w && x >= rect.w - rect.border))
				put_pixel_rect(img, rect, y, x);
			if ((y >= 0 && y <= rect.border) || (y <= rect.h && y >= rect.h - rect.border))
				put_pixel_rect(img, rect, y, x);
			if (rect.type == 1)
				put_pixel_rect(img, rect, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(coef->mlx, coef->win, img.img, rect.x, rect.y);
}

