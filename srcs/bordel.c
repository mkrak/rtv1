#include "../includes/rt.h"

void				ft_logo(t_coef *t)
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

void				fill_menu(t_coef *t, void *win)
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

void	menu_add(t_control *l, char *str, int status)
{
	void	*img;
	int		w;
	int		h;

	if (status == 0)
	{
		if (l->coef->win_add == NULL)
		{
			l->coef->posx = 0;
			l->coef->posy = 0;
			l->coef->posz = 0;
			l->coef->rad = 0;
			l->coef->r = 0;
			l->coef->g = 0;
			l->coef->b = 0;
			l->coef->type = 0;
			l->coef->win_add = mlx_new_window(l->coef->mlx, 250, 500, str);
		}
	}
	if (status == 1)
	{
		if (l->coef->win_add == NULL)
		{
			l->coef->posx = (int)l->obj[l->coef->cur].s.p.posx;
			l->coef->posy = (int)l->obj[l->coef->cur].s.p.posy;
			l->coef->posz = (int)l->obj[l->coef->cur].s.p.posz;
			l->coef->rad = (int)l->obj[l->coef->cur].s.ray;
			l->coef->r = (int)l->obj[l->coef->cur].s.color.posx * 100;
			l->coef->g = (int)l->obj[l->coef->cur].s.color.posy * 100;
			l->coef->b = (int)l->obj[l->coef->cur].s.color.posz * 100;
			l->coef->type = (int)l->obj[l->coef->cur].s.type;
			l->coef->win_add = mlx_new_window(l->coef->mlx, 250, 500, str);
		}
	}
	img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/ADD_BAR.XPM", &w, &h);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win_add, img, 13, 10);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win_add, img, 13, 50);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win_add, img, 13, 90);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win_add, img, 13, 150);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win_add, img, 13, 210);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win_add, img, 13, 250);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win_add, img, 13, 290);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win_add, img, 13, 350);
	img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/UPDATE.XPM", &w, &h);
	mlx_put_image_to_window(l->coef->mlx, l->coef->win_add, img, 13, 410);

	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 10 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->posx));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 50 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->posy));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 90 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->posz));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 150 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->rad));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 210 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->r));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 250 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->g));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 290 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->b));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 350 + 15 - (OS * 9), 0x00000000, ft_itoa(l->coef->type));

/*	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 10, 0x00000000, ft_itoa(l->coef->posx));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 50, 0x00000000, ft_itoa(l->coef->posy));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 90, 0x00000000, ft_itoa(l->coef->posz));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 150, 0x00000000, ft_itoa(l->coef->rad));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 210, 0x00000000, ft_itoa(l->coef->r));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 250, 0x00000000, ft_itoa(l->coef->g));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 290, 0x00000000, ft_itoa(l->coef->b));
	mlx_string_put(l->coef->mlx, l->coef->win_add, 109, 350, 0x00000000, ft_itoa(l->coef->type));
*/
	mlx_mouse_hook(l->coef->win_add, add_mouse_hook, l);
	mlx_key_hook(l->coef->win_add, ft_keyhook, l);
	mlx_destroy_image(l->coef->mlx, img);
}

void	export_file(t_control *l)
{
	int		fd;
	int		x;
	int		y;

	y = H;
	x = W * H * 4 - W * 4;
	fd = open(l->coef->name, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);

	int		type;
	int		fsize;
	int		reserved1;
	int		reserved2;
	int		offset;
	int		hsize;
	int		width;
	int		height;
	int		plane;
	int		bpp;
	int		compression;
	int		isize;
	int		resX;
	int		resY;
	int		clrUsd;
	int		clrImp;

	type = 19778;
	fsize = H * W * 4 + 40 + 14;
	reserved1 = 0;
	reserved2 = 0;
	offset = 40 + 14;
	hsize = 40;
	width = W;
	height = H;
	plane = 1;
	bpp = 32;
	compression = 0;
	isize = W * H * 4;
	resX = 0;
	resY = 0;
	clrUsd = 0;
	clrImp = 0;

	//HEADER
	write(fd, (char *)&type, 2); //type
	write(fd, (char *)&fsize, 4); //fsize
	write(fd, (char *)&reserved1, 2); //reserved1
	write(fd, (char *)&reserved2, 2); //reserved2
	write(fd, (char *)&offset, 4); //offset
	write(fd, (char *)&hsize, 4); //hsize
	write(fd, (char *)&width, 4); //width
	write(fd, (char *)&height, 4); //height
	write(fd, (char *)&plane, 2); //plane
	write(fd, (char *)&bpp, 2); //bpp
	write(fd, (char *)&compression, 4); //compression
	write(fd, (char *)&isize, 4); //isize
	write(fd, (char *)&resX, 4); //resX
	write(fd, (char *)&resY, 4); //resY
	write(fd, (char *)&clrUsd, 4); //clrUsd
	write(fd, (char *)&clrImp, 4); //clrImp

	//REMPLISSAGE
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

int		mouse_hook(int k, int x, int y, t_control *l)
{
	if (k == 1 && (x >= 25 && x <= 225) && (y >= 15 && y <= 90))
		menu_add(l, "SPHERE", 0);
	if (k == 1 && (x >= 25 && x <= 225) && (y >= 100 && y <= 175))
		menu_add(l, "", 0);
	if (k == 1 && (x >= 25 && x <= 225) && (y >= 185 && y <= 260))
		menu_add(l, "", 0);
	if (k == 1 && (x >= 25 && x <= 225) && (y >= 270 && y <= 345))
		menu_add(l, "", 0);
	return (k);
}

int		rt_search(int x, int y, t_control *l)
{
	double	fov = 60 * M_PI / 180;
	int		i = 0;
	t_inter	t;
	t_inter	inter;
	t_ray	r;

	t.t = 0;
	r.d = normalize(init_point(x - W / 2, -(y - H / 2), -W / (2 * tan(fov / 2))));
	r.d = rotate_cam(r.d, l->coef->rot_y, l->coef->rot_x, l->coef->rot_z);
	r.o = init_point(l->coef->pos_y, l->coef->pos_z, l->coef->rot_x);
	while (i < l->nb_obj)
	{
		inter = intersec(l, i, r);
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

int		main_mouse_hook_not(int x, int y, t_control *l)
{
	void	*img;
	int		w;
	int		h;

	if (((x >= W + 45 && x <= W + 320) && (y >= 360 && y <= 395)) && l)
	{
		img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/add_filter_hover.XPM", &w, &h);
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 360);
		l->coef->is_on_button = 1;
	}
	else if (((x >= W + 45 && x <= W + 320) && (y >= 410 && y <= 445)) && l)
	{
		img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/add_obj_hover.XPM", &w, &h);
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 410);
		l->coef->is_on_button = 1;
	}
	else if (l->coef->is_on_button)
	{
		trace_info(l);
		l->coef->is_on_button = 0;
	}
	return (1);
}

int		main_mouse_hook(int k, int x, int y, t_control *l)
{
	int		id;

	if (k == 1 && ((x >= 0 && x <= W) && y) && l)
	{
		id = rt_search(x, y, l);
		l->coef->swap = l->obj[id].s;
		l->coef->cur = id;
		menu_add(l, "Modifier", 1);
	}
	if (((x >= W + 45 && x <= W + 320) && (y >= 460 && y <= 480)) && l && k == 1)
	{
		l->coef->sat = (x - (W + 45)) * 100  / 275;
		ft_putendl(ft_itoa(l->coef->sat));
		trace_info(l);
		multithread(l);
	}
		if (((x >= W + 45 && x <= W + 320) && (y >= 490 && y <= 510)) && l && k == 1)
	{
		l->coef->lum = fmax(-254, (((x - (W + 45)) * 510 / 275) - 255));
		ft_putendl(ft_itoa(l->coef->sat));
		trace_info(l);
		multithread(l);
	}
	return (k);
}
