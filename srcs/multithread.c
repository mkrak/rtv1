#include "../includes/rt.h"

void	multithread(t_control *l)
{
	struct timeval	tv;
	t_thread	*thread;
	int			i;
	int			j;
	int			k;
	int			m;

	i = 0;
	k = 0;
	m = 0;
	gettimeofday(&tv, NULL);
	l->coef->prev_time = tv.tv_sec * 1000000 + tv.tv_usec;
	thread = malloc(sizeof(t_thread) * 8);
	while (i < 8)
	{
		thread[i].l = *l;
		thread[i].n = i;
		thread[i].i.img = mlx_new_image(l->coef->mlx, W, H / 8);
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
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, thread[i].i.img, 0, j * (H / 8) + 5);
		m = 0;
		while (m < ((H / 8) * W * 4))
		{
			l->coef->data[k] = thread[i].i.data[m];
			m++;
			k++;
		}
		mlx_destroy_image(l->coef->mlx, thread[i].i.img);
		i--;
		j++;
	}
	free(thread);
	gettimeofday(&tv, NULL);
	l->coef->time = tv.tv_sec * 1000000 + tv.tv_usec;
}
