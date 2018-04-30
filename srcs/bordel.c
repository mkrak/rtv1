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

int		rt_search(int x, int y, t_control *l)
{
	double	fov = 60 * M_PI / 180;
	int		i = 0;
	t_inter	t;
	t_inter	inter;
	t_ray	r;

	t.t = 0;
	r.dir = normalize(vec3(x - W / 2, -(y - H / 2), -W / (2 * tan(fov / 2))));
	r.dir = rotate_cam(r.dir, l->coef->rot_y, l->coef->rot_x, l->coef->rot_z);
	r.origin = vec3(l->coef->pos_y, l->coef->pos_z, l->coef->rot_x);
	while (i < l->nb_obj)
	{
		inter = intersec(i, l->obj[i].q, r.origin, r.dir);
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

void	obj_realloc(t_control *l)
{
	t_obj	*swap;
	int		i;

	i = 0;
	l->nb_obj++;
	l->coef->total++;
	swap = (t_obj*)malloc(sizeof(t_obj) * l->nb_obj - 1);
	while (i < l->nb_obj)
	{
		swap[i] = l->obj[i];
		i++;
	}
	i = 0;
	free(l->obj);
	l->obj = (t_obj*)malloc(sizeof(t_obj) * l->nb_obj);
	while (i <= l->nb_obj)
	{

		l->obj[i] = swap[i];
		i++;
	}
	ft_putendl("test");
}

int		main_mouse_hook_not(int x, int y, t_control *l)
{
	t_img	bl;
	void	*img;
	int		w;
	int		h;

	bl.img = mlx_new_image(l->coef->mlx, 350, 35);
	if (((x >= W + 45 && x <= W + 320) && (y >= 360 && y <= 395)) && l && l->coef->menu_state == 0)
	{
		img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/menu_0/add_filter_hover.XPM", &w, &h);
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 360);
		l->coef->is_on_button = 1;
	}

	else if (((x >= W + 45 && x <= W + 320) && (y > 60 && y <= 93)) && l && l->coef->menu_state == 1)
	{
		if (l->coef->negatif == 0)
			img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/menu_1/neg/hover_0.XPM", &w, &h);
		else
		{
			mlx_put_image_to_window(l->coef->mlx, l->coef->win, bl.img, W, 60);
			img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/menu_1/neg/hover_1.XPM", &w, &h);
		}
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 60);
		l->coef->is_on_button = 1;
	}
	else if (((x >= W + 45 && x <= W + 320) && (y > 95 && y <= 128)) && l && l->coef->menu_state == 1)
	{
		if (l->coef->sepia == 0)
			img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/menu_1/sepia/hover_0.XPM", &w, &h);
		else
		{
			mlx_put_image_to_window(l->coef->mlx, l->coef->win, bl.img, W, 95);
			img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/menu_1/sepia/hover_1.XPM", &w, &h);
		}
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 95);
		l->coef->is_on_button = 1;
	}
	else if (((x >= W + 45 && x <= W + 320) && (y > 130 && y <= 163)) && l && l->coef->menu_state == 1)
	{
		if (l->coef->cartoon == 0)
			img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/menu_1/cartoon/hover_0.XPM", &w, &h);
		else
		{
			mlx_put_image_to_window(l->coef->mlx, l->coef->win, bl.img, W, 130);
			img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/menu_1/cartoon/hover_1.XPM", &w, &h);
		}
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 130);
		l->coef->is_on_button = 1;
	}
	else if (((x >= W + 45 && x <= W + 320) && (y > 165 && y <= 198)) && l && l->coef->menu_state == 1)
	{
		if (l->coef->wtf == 0)
			img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/menu_1/wtf/hover_0.XPM", &w, &h);
		else
		{
			mlx_put_image_to_window(l->coef->mlx, l->coef->win, bl.img, W, 165);
			img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/menu_1/wtf/hover_1.XPM", &w, &h);
		}
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 165);
		l->coef->is_on_button = 1;
	}

	else if (((x >= W + 45 && x <= W + 320) && (y >= 400 && y <= 435)) && l && l->coef->menu_state == 0)
	{
		img = mlx_xpm_file_to_image(l->coef->mlx, "ressources/img/menu_0/add_obj_hover.XPM", &w, &h);
		mlx_put_image_to_window(l->coef->mlx, l->coef->win, img, W + 45, 400);
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

	if ((k == 1 && (x >= W + 45 && x <= W + 75) && (y >= 25 && y <= 50)) && l && l->coef->menu_state == 1)
	{
		l->coef->menu_state = 0;
		trace_info(l);
	}
	if ((k == 1 && (x >= W + 45 && x <= W + 320) && (y >= 360 && y <= 395)) && l && l->coef->menu_state == 0)
	{
		l->coef->menu_state = 1;
		trace_info(l);
	}
	if ((k == 1 && (x >= W + 45 && x <= W + 320) && (y >= 400 && y <= 435)) && l && l->coef->menu_state == 0)
	{
		l->coef->menu_state = 2;
		trace_info(l);
	}

	if ((k == 1 && (x >= W + 45 && x <= W + 320) && (y >= 60 && y <= 95)) && l && l->coef->menu_state == 1)
	{
		if (l->coef->negatif == 0)
			l->coef->negatif = 1;
		else
			l->coef->negatif = 0;
		trace_info(l);
		multithread(l);
	}
	if ((k == 1 && (x >= W + 45 && x <= W + 320) && (y >= 95 && y <= 130)) && l && l->coef->menu_state == 1)
	{
		if (l->coef->sepia == 0)
			l->coef->sepia = 1;
		else
			l->coef->sepia = 0;
		trace_info(l);
		multithread(l);
	}
	if ((k == 1 && (x >= W + 45 && x <= W + 320) && (y >= 130 && y <= 165)) && l && l->coef->menu_state == 1)
	{
		if (l->coef->cartoon == 0)
			l->coef->cartoon = 1;
		else
			l->coef->cartoon = 0;
		trace_info(l);
		multithread(l);
	}
	if ((k == 1 && (x >= W + 45 && x <= W + 320) && (y >= 165 && y <= 200)) && l && l->coef->menu_state == 1)
	{
		if (l->coef->wtf == 0)
			l->coef->wtf = 1;
		else
			l->coef->wtf = 0;
		trace_info(l);
		multithread(l);
	}

	if (k == 1 && ((x >= 0 && x <= W) && (y >= 0 && y <= H)) && l)
	{
		l->coef->status = 1;
		l->coef->menu_state = 3;
		id = rt_search(x, y, l);
		l->coef->swap = l->obj[id];
		l->coef->id_swap = l->coef->cur;
		l->coef->cur = id;
		trace_info_3(l, 2);
	}
	if (((x >= W + 45 && x <= W + 350) && (y >= 235 && y <= 255)) && l && k == 1 && l->coef->menu_state == 1)
	{
		l->coef->sat = (x - (W + 45)) * 100  / 275;
		ft_putendl(ft_itoa(l->coef->sat));
		trace_info(l);
		multithread(l);
	}
	if (((x >= W + 45 && x <= W + 350) && (y >= 305 && y <= 325)) && l && k == 1 && l->coef->menu_state == 1)
	{
		l->coef->lum = fmax(-254, (((x - (W + 45)) * 510 / 275) - 255));
		ft_putendl(ft_itoa(l->coef->sat));
		trace_info(l);
		multithread(l);
	}

	if (k == 1 && (x >= W + 45 && x <= W + 350) && (y >= 15 && y <= 90 && l->coef->menu_state == 2))
	{
		l->coef->shape = 0;
		l->coef->status = 0;
		l->coef->menu_state = 3;
		trace_info_3(l, 0);
	}
	if (k == 1 && (x >= W + 45 && x <= W + 350) && (y >= 100 && y <= 175 && l->coef->menu_state == 2))
	{
		l->coef->shape = 1;
		l->coef->status = 0;
		l->coef->menu_state = 3;
		trace_info_3(l, 0);
	}
	if (k == 1 && (x >= W + 45 && x <= W + 350) && (y >= 185 && y <= 260 && l->coef->menu_state == 2))
	{
		l->coef->shape = 2;
		l->coef->status = 0;
		l->coef->menu_state = 3;
		trace_info_3(l, 0);
	}
	if (k == 1 && (x >= W + 45 && x <= W + 350) && (y >= 270 && y <= 345 && l->coef->menu_state == 2))
	{
		l->coef->shape = 3;
		l->coef->status = 0;
		l->coef->menu_state = 3;
		trace_info_3(l, 0);
	}

	if ((x >= W + 45 && x <= W + 350) && (y >= 150 && y <= 175) && l->coef->menu_state == 3)
	{
		menu_hook_rad(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 350 && y <= 375) && l->coef->menu_state == 3)
	{
		menu_hook_type(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 210 && y <= 235) && l->coef->menu_state == 3)
	{
		menu_hook_r(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 250 && y <= 275) && l->coef->menu_state == 3)
	{
		menu_hook_g(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 290 && y <= 315) && l->coef->menu_state == 3)
	{
		menu_hook_b(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 15 && y <= 40) && l->coef->menu_state == 3)
	{
		menu_hook_posx(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 50 && y <= 75) && l->coef->menu_state == 3)
	{
		menu_hook_posy(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 90 && y <= 115) && l->coef->menu_state == 3)
	{
		menu_hook_posz(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((x >= W + 45 && x <= W + 350) && (y >= 390 && y <= 415) && l->coef->menu_state == 3)
	{
		menu_hook_axe(k, x, y, l);
		trace_info_3(l, 1);
	}
	if ((k == 1 && (x >= (W + 45) + 0 && x <= (W + 45) + 75) && (y >= 450 && y <= 750)) && l->coef->menu_state == 3)
		menu_hook_update(k, l);
	if ((k == 1 && (x >= (W + 45) + 75 && x <= (W + 45) + 150) && (y >= 450 && y <= 750)) && l->coef->menu_state == 3)
	{
		if (!l->coef->status)
		{
			obj_realloc(l);
			l->nb_obj++;
			l->coef->cur += 1;
		}
		ft_putendl("TEST");
		menu_hook_add(k, l);
		ft_putendl("TEST");
		if (l->coef->status)
			l->coef->cur = l->coef->id_swap;
		l->coef->menu_state = 0;
		trace_info(l);
	}
	if ((k == 1 && (x >= (W + 45) + 150 && x <= (W + 45) + 250) && (y >= 410 && y <= 750)) && l->coef->menu_state == 3)
	{
		menu_hook_cancel(k, l);
		l->coef->menu_state = 0;
		if (l->coef->status)
			l->coef->cur = l->coef->id_swap;
		else
			l->coef->cur += 1;
		trace_info(l);
	}
//		trace_info_3(l, 0);
	return (k);
}
