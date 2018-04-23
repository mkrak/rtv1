/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:40:56 by mkrakows          #+#    #+#             */
/*   Updated: 2018/04/12 14:39:30 by cballest         ###   ########.fr       */
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

# define H 600
# define W 600
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

typedef struct		s_vec3
{ 
	double		x;
	double		y;
	double		z;
}					t_vec3;

typedef struct		s_ray
{
	t_vec3	origin;
	t_vec3 dir;
}					t_ray;

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

typedef struct		s_circle
{
	int				x;
	int				y;
	int				r;
	t_col			c;
}					t_circle;

typedef struct		s_sphere
{
	t_vec3	p;
	double	ray;
	t_vec3 color;
	t_vec3 normal;
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
	double 		reflec;
	int			negatif;
	int 		sepia;
	int			bnw;
	int			sat;
	int			lum;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			is_on_button;
}					t_coef;

typedef struct		s_luz
{
	t_vec3	p;
	double	power;
}					t_luz;

typedef struct		s_obj
{
	t_sphere s;
}					t_obj;

typedef struct		s_inter
{
	t_vec3 pos;
	t_vec3 norm;
	int id;
	double t;
}					t_inter;

typedef struct		s_rect
{
	int				x;
	int				y;
	int				w;
	int				h;
	int				type;
	int				border;
	t_col			c;
}					t_rect;

typedef struct		s_damier
{
	int				x1;
	int				y1;
	int				z1;
	double			px;
	double			py;
	double			pz;
} 					t_damier;

typedef struct		s_buton
{
	t_img			img_norm;
	t_img			img_hover;
	t_rect			rect;
	int				is_hover;
	int				is_active;
}					t_buton;

typedef struct		s_scrol
{
	t_rect			bar;
	t_circle		cir;
	t_col			c1;
	t_col			c2;
	int				value;
	int				id;
}					t_scrol;

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

//main.c
void				init_struct(t_coef *scoef);
void				new_image(t_coef *scoef);
void				put_pixel(t_img s, int x, int y, t_vec3 color, t_coef *c);
int					quit(void);

//keyhook.c
int					ft_keyhook(int key, t_control *e);
int					ft_key_camtrans(t_control *e);
int					ft_key_camrot(t_control *e);
int					ft_key_aa(t_control *e);

//init.c
void				init_w(t_control *l);
t_vec3				vec3(double x, double y, double z);
t_sphere			init_sphere(t_vec3 p, double ray, t_vec3 color, int type);

//rt.c
void				rt(t_thread *l);
t_vec3				get_color(t_control *l, int nb_ite, t_ray ray);
t_inter				intersec(t_control *l, int i, t_ray ray);
t_vec3				ombre(t_ray ray, t_control *l, t_inter t);

//ope_vec.c
double				getnorm2(t_vec3 p);
t_vec3				normalize(t_vec3 v);
t_vec3				sub_vec3(t_vec3 a, t_vec3 b);
t_vec3				add_vec3(t_vec3 a, t_vec3 b);
t_vec3				k_vec3(double k, t_vec3 b);
t_vec3				ope_divv1(t_vec3 b, double a);

//ope_vec2.c
t_vec3				rotate_cam(t_vec3 d, double x, double y, double z);
double				dot(t_vec3 p, t_vec3 b);
t_vec3				moy_point(t_vec3 *moy, int antial);
t_vec3				rot_cam_x(t_vec3 d, double x);
t_vec3				rot_cam_y(t_vec3 d, double y);
t_vec3				rot_cam_z(t_vec3 d, double z);
//aliasing.c
t_vec3				aliasing(t_control *l, t_ray ray);
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

//mlx.c
void				put_pixel_circle(t_img i, t_circle c, int x, int y);
void				mlx_circle(t_circle c, t_coef *coef);
void				mlx_rect(t_rect rect, t_coef *coef);
void				mlx_scroll_bar(t_scrol s, t_coef *coef);

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
int		main_mouse_hook_not(int x, int y, t_control *l);
void	ft_loadbar(t_coef *t, int n);
void	menu_add(t_control *l, char *str, int status);

t_vec3			damier(t_control *l, t_inter inter);



#endif
