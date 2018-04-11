/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:40:56 by mkrakows          #+#    #+#             */
/*   Updated: 2018/04/03 16:09:16 by cballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# if defined(__linux__)
#  include "keys_linux.h"
#  define OS 0
# else
#  include "keys_mac.h"
#  define OS 1
# endif

# define H 500
# define W 500
# define LENGHT_PROCED 10
# define OBJ l->obj[t.id]
# define OBJ_I l->obj[i]

# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <pthread.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef union		s_col
{
	int				color;
	char			c[4];
}					t_col;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sl;
	int				end;
}					t_img;

typedef struct		s_point
{ 
	double		posx;
	double		posy;
	double		posz;
}					t_point;

typedef struct		s_sphere
{
	t_point	p;
	double	ray;
	t_point color;
	t_point normal;
	int type;
}					t_sphere;

typedef struct		s_coef
{
	int			time;
	int			prev_time;
	t_sphere	swap;
	t_img		*load;
	char		*name;
	void		*win_rename;
	void		*win_add;
	int			sl;
	int			posx;
	int			posy;
	int			posz;
	int			rad;
	int			r;
	int			g;
	int			b;
	int			type;
	int			cur;
	int			total;
	int			rot_x;
	int			rot_y;
	int			rot_z;
	int			pos_x;
	int			pos_y;
	int			pos_z;
	int			cartoon;
	int			wtf;
	int			negatif;
	int			bnw;

	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
}					t_coef;

typedef struct		s_ray
{
	t_point	o;
	t_point d;
}					t_ray;

typedef struct		s_luz
{
	t_point	p;
	double	power;
}					t_luz;

typedef struct		s_obj
{
	t_sphere s;
}					t_obj;

typedef struct		s_inter
{
	t_point pos;
	t_point norm;
	int id;
	double t;
}					t_inter;

typedef struct		s_control
{
	int 		aliasing;
	int 		antial;
	int			av;
	t_coef		*coef;
	t_ray		*r;
	t_luz		*l;
	int 		nb_luz;
	t_obj		*obj;
	int 		nb_obj;
	int 		obj_i;
	int			au;
	int			ad;
	int			al;
	int			ar;
	int			ctrl;
	int			shif;
	int			roll;
	int			rolr;
	int			rotl;
	int			rotr;
	int			rotu;
	int			rotd;
	int			kaliadd;
	int			kalisub;
	int			kaa;
}					t_control;

typedef struct		s_thread
{
	t_control		l;
	t_img			i;
	pthread_t		t;
	int				n;
}					t_thread;

typedef struct		s_damier
{
	int				x1;
	int				y1;
	int				z1;
	double			px;
	double			py;
	double			pz;
} 					t_damier;

//main.c
void				init_struct(t_coef *scoef);
void				new_image(t_coef *scoef);
void				put_pixel(t_img s, int x, int y, t_point color, t_coef *c);
int					quit(void);

//keyhook.c
int					ft_keyhook(int key, t_control *e);
int					ft_key_camtrans(t_control *e);
int					ft_key_camrot(t_control *e);
int					ft_key_aa(t_control *e);

//init.c
void				init_w(t_control *l);
t_point				init_point(double x, double y, double z);
t_sphere			init_sphere(t_point p, double ray, t_point color, int type);

//rt.c
void				rt(t_thread *l);
t_point				get_color(t_control *l, int nb_ite, t_ray ray);
t_inter				intersec(t_control *l, int i, t_ray ray);
t_point				ombre(t_ray ray, t_control *l, t_inter t);

//ope_vec.c
double				getnorm2(t_point p);
t_point				normalize(t_point p);
t_point				ope_sus(t_point p, t_point b);
t_point				ope_add(t_point p, t_point b);
t_point				ope_mulv1(t_point b, double a);

//ope_vec2.c
t_point				rotate_cam(t_point d, double angle);
double				dot(t_point p, t_point b);
t_point				moy_point(t_point *moy, int antial);

//aliasing.c
t_point				aliasing(int py, t_control *l, t_ray ray);
t_ray				anti_alias(int px, int py, t_ray ray, int i, t_coef *t);

//multithread.c
void				multithread(t_control *l);

//menu_hook.c
int					add_mouse_hook(int k, int x, int y, t_control *l);

//utils.c
void				ft_putfloat(float d, double eps);
void				ftoa(float n, char *res, int p);

//key_pr.c
int					main_loop(t_control *e);
int					key_p(int k, t_control *e);
int					key_r(int k, t_control *e);

void	trace_info(t_control *e);
void	export_file(t_control *t);
void	hook_mac_rename(t_control *l, int k);
void	hook_mac_rename2(t_control *l, int k);
void	hook_mac_rename3(t_control *l, int k);
int		rt_search(int x, int y, t_control *l);
int		hook_rename(int k, t_control *l);
void	rename_win(t_control *l);
void	fill_menu(t_coef *t, void *win);
void	ft_logo(t_coef *t);
int		mouse_hook(int k, int x, int y, t_control *l);
int		main_mouse_hook(int k, int x, int y, t_control *l);
void	ft_loadbar(t_coef *t, int n);
void	menu_add(t_control *l, char *str, int status);

t_point			damier(t_control *l, t_inter inter);



#endif
