#include "../includes/rt.h"

void		fill_img(char *data, int w, int h)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			i = ((h - y - 1) * w + x) * 4;
			data[i] = 0xff;
			data[++i] = 0xff;
			data[++i] = 0xff;
//			mlx_pixel_put(t->mlx, t->win, x, y, 0x00ffffff);
			x++;
		}
		y++;
	}
}

void		ft_loadbar(t_coef *t, int n)
{
	t->load->img = mlx_new_image(t->mlx, n * 500 / H, 25);
	t->load->data = mlx_get_data_addr(t->load->img, &t->load->bpp, &t->load->sl, &t->load->end);
	fill_img(t->load->data, n * 500 / H, 25);
	mlx_put_image_to_window(t->mlx, t->win, t->load->img, W / 2 - 250, H / 2 + 150);
	mlx_destroy_image(t->mlx, t->load->img);
}
