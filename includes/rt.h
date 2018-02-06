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
# define H 1024
# define W 1024
# define PI 3.1415926535897932

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



typedef struct		s_coef
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			sl;
}					t_coef;

typedef struct		s_point
{ 
	double		posx;
	double		posy;
	double		posz;
}					t_point;

typedef struct		s_ray
{
	t_point	o;
	t_point d;
}					t_ray;

typedef struct		s_sphere
{
	t_point	p;
	double	ray;
	t_point color;
}					t_sphere;

typedef struct		s_luz
{
	t_point	p;
	double	power;
}					t_luz;

typedef struct		s_obj
{
	t_sphere s;
}					t_obj;

typedef struct		s_control
{
	t_coef		*coef;
	t_ray		*r;
	t_luz		*l;
	t_obj		*obj;
}					t_control;



 

void				init_struct(t_coef *scoef);
void				new_image(t_coef *scoef);
void				put_pixel(t_coef *scoef, int x, int y, t_point color);
void				init_w(t_control *l);

int					ft_keyhook(int key, t_control *e);
int					quit(void);

void				rt(t_control *l);
t_point				ope_add(t_point p, t_point b);
t_point				ope_sus(t_point p, t_point b);
t_point				ope_mulv2(t_point a, t_point b);
t_point				ope_mulv1(t_point b, double a);
t_point				ope_div(t_point p, double a);
double				dot(t_point p, t_point b);
double				getnorm2(t_point p);
t_point				normalize(t_point p);
int					intersec(t_control *l, t_point *pos, t_point *norm);

t_point				init_point(double x, double y, double z);
t_sphere			init_sphere(t_point p, double ray, t_point color);

#endif
