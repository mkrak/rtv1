/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:40:56 by mkrakows          #+#    #+#             */
/*   Updated: 2017/04/13 22:00:46 by mkrakows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# define H 800
# define W 800
# define LENGHT_PROCED 10
# define OBJ l->obj[t.id]
# define OBJ_I l->obj[i]

# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

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
	int type;
}					t_sphere;

typedef struct		s_coef
{
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
	int			av;
	t_coef		*coef;
	t_ray		*r;
	t_luz		*l;
	int 		nb_luz;
	t_obj		*obj;
	int 		nb_obj;
	int 		obj_i;
}					t_control;


typedef struct		s_damier
{
	int				x1;
	int				y1;
	int				z1;
	double			px;
	double			py;
	double			pz;
} 					t_damier;

//main
void				init_struct(t_coef *scoef);
void				new_image(t_coef *scoef);
void				put_pixel(t_coef *scoef, int x, int y, t_point color);
int					quit(void);

//keyhook
int					ft_keyhook(int key, t_control *e);

//init
void				init_w(t_control *l);
t_point				init_point(double x, double y, double z);
t_sphere			init_sphere(t_point p, double ray, t_point color, int type);

//rt
void				rt(t_control *l);
t_point				get_color(t_control *l, int nb_ite, t_ray ray);
t_inter				intersec(t_control *l, int i, t_ray ray);
t_point				ombre(t_ray ray, t_control *l, t_inter t);

//ope_vec
double				getnorm2(t_point p);
t_point				normalize(t_point p);
t_point				ope_sus(t_point p, t_point b);
t_point				ope_add(t_point p, t_point b);
t_point				ope_mulv1(t_point b, double a);

//ope_vec2
t_point				rotate_cam(t_point d, double angle);
double				dot(t_point p, t_point b);
t_point				moy_point(t_point *moy);


void	export_file(t_control *t);
int		rt_search(int x, int y, t_control *l);
int		hook_rename(int k, t_control *l);
void	rename_win(t_control *l);
void	fill_menu(t_coef *t, void *win);
void	ft_logo(t_coef *t);
int		mouse_hook(int k, int x, int y, t_control *l);
int		main_mouse_hook(int k, int x, int y, t_control *l);
void	ft_loadbar(t_coef *t, int n);

t_point			damier(t_control *l, t_inter inter);



#endif
