#include "../includes/rt.h"

void	multithread(t_control l)
{
	t_thread	*thread;
	int			i;
	int			j;

	i = 0;
	thread = malloc(sizeof(t_thread) * 8);
	while (i < 8)
	{
		thread[i].l = l;
		thread[i].n = i;
		thread[i].i.img = mlx_new_image(l.coef->mlx, W, H / 8);
		thread[i].i.data = mlx_get_data_addr(thread[i].i.img, &thread[i].i.bpp, &thread[i].i.sl, &thread[i].i.end);
		pthread_create(&thread[i].t, NULL, (void *)rt, (void *)&thread[i]);
		i++;
	}
	i = 0;
	while (i < 8)
		pthread_join(thread[i++].t, NULL);
	i = 7;
	j = 0;
	while (i > -1)
	{
		mlx_put_image_to_window(l.coef->mlx, l.coef->win, thread[i].i.img, 0, j * (H / 8));
		mlx_destroy_image(l.coef->mlx, thread[i].i.img);
		i--;
		j++;
	}
	free(thread);
}
