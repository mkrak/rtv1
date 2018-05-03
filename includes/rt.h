/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrakows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:40:56 by mkrakows          #+#    #+#             */
/*   Updated: 2018/05/02 21:13:15 by lgautier         ###   ########.fr       */
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

# define H 1000
# define W 1000
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
# include <sys/stat.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define ERR_USAGE	"Invalid usage"
# define ERR_FILE	"Invalid filename"
# define ERR_UNKNOW	"An error has occurred"

# define CST_DEFINE	"define"

# define CHARS_SPACE		"\n\t "
# define CHARS_QUOTE		"\"\'"
# define CHARS_BLOCK		"{}"
# define CHARS_ATTR			"abcdefghijklmnopqrstuvwxyz-"
# define CHARS_NAME			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define CHARS_AXE			"xyz"
# define CHARS_COLOR		"0123456789abcdef"

# define COLOR_LEN	0x6

# define CHAR_DEFINE			'@'
# define CHAR_CLASS				'.'
# define CHAR_COLOR				'#'
# define CHAR_OBJECT			'#'
# define CHAR_ATTR_END			':'
# define CHAR_ATTR_VALUE_END	';'
# define CHAR_EOL				'\n'

# define N_ATTR		0xa
# define N_CLASS	0x5
# define N_TT		0x8
# define N_ST		0x3

# define TT_DEF			CHAR_DEFINE
# define TT_CLASS		CHAR_CLASS
# define TT_NAME		CHARS_QUOTE[0]
# define TT_OBJECT		CHAR_OBJECT
# define TT_START_BLOCK	CHARS_BLOCK[0]
# define TT_END_BLOCK	CHARS_BLOCK[1]
# define TT_ATTR		CHAR_ATTR_END
# define TT_ATTR_VALUE	CHAR_ATTR_VALUE_END

# define TTE_DEF			1
# define TTE_CLASS			(1 << 1)
# define TTE_NAME			(1 << 2)
# define TTE_OBJECT			(1 << 3)
# define TTE_START_BLOCK	(1 << 4)
# define TTE_END_BLOCK		(1 << 5)
# define TTE_ATTR			(1 << 6)
# define TTE_ATTR_VALUE		(1 << 7)

# define OBJ_SPHERE		0
# define OBJ_PLANE		1
# define OBJ_CYLINDER	2
# define OBJ_CONE		3
# define OBJ_LIGHT		4

# define ST_NORMAL			0
# define ST_MIRROR			1
# define ST_CHECKER_BOARD	2

typedef struct		s_token
{
	void			*data;
	struct s_token	*next;
	uint8_t			type;
}					t_token;

typedef struct		s_vec3
{
	double		x;
	double		y;
	double		z;
}					t_vec3;

typedef struct		s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}					t_ray;

typedef struct 		s_pxl
{
	int		x;
	int		y;
}					t_pxl;

typedef	struct		s_quadric
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		e;
	double		f;
	double		g;
	double		h;
	double		i;
	double		j;

}					t_quadric;

typedef	struct		s_attr
{
	char			axe;
	uint8_t			type;
	uint8_t			id;
	uint32_t 		color;
	double			kd;
	double			ks;
	double			radius;
	t_vec3			pos;
	t_vec3			rot;
	t_vec3			scale;
	t_vec3			albedo;
}					t_attr;

typedef	struct		s_obj
{
	t_attr			attr;
	t_quadric		q;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_class
{
	void			(*init_quadric)(t_quadric *q, t_attr attr);
	char			*name;
}					t_class;

typedef struct		s_set_attr
{
	void			(*set_attr)(char *attr_value, void *attr_dst);
	uint16_t		struct_offset;
	char			*attr;
}					t_set_attr;

typedef union		u_col
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
	int				w;
	int				h;
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
	t_vec3	color;
	t_vec3	normal;
	int		type;
}					t_sphere;

typedef struct		s_coef
{
	int			time;
	int			prev_time;
	t_obj		*swap;
	t_img		*load;
	t_col		color;
	char		*name;
	void		*win_rename;
	void		*win_add;
	int			sl;
	int			posx;
	int			posy;
	int			posz;
	int			rotx;
	int			roty;
	int			rotz;
	int			strx;
	int			stry;
	int			strz;
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
	double		reflec;
	int			negatif;
	int			sepia;
	int			bnw;
	int			sat;
	int			lum;
	int			pn;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			menu_state;
	int			id_swap;
	int			status;
	int			is_on_button;
	int			shape;
	char		axe;
}					t_coef;

typedef struct		s_luz
{
	t_vec3	p;
	double	power;
}					t_luz;

typedef struct		s_inter
{
	t_vec3	pos;
	t_vec3	norm;
	int		id;
	double	t;
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
}					t_damier;

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
	int			aliasing;
	int			antial;
	int			av;
	t_coef		*coef;
	t_ray		*r;
	t_luz		*l;
	int			nb_luz;
	t_obj		*obj;
	t_obj		*current;
	int			nb_obj;
	int			obj_i;
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

typedef struct		s_export
{
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
	int		resx;
	int		resy;
	int		clrusd;
	int		clrimp;
}					t_export;

typedef struct		s_thread
{
	t_control		l;
	t_img			i;
	pthread_t		t;
	int				n;
}					t_thread;

void				init_sphere(t_quadric *q, t_attr attr);
void				init_cylinder(t_quadric *q, t_attr attr);
void				init_plane(t_quadric *q, t_attr attr);
void				init_cone(t_quadric *q, t_attr attr);

void				set_vec_attr(char *attr_value, void *attr_dst);
void				set_double_attr(char *attr_value, void *attr_dst);
void				set_color_attr(char *attr_value, void *attr_dst);
void				set_surface_attr(char *attr_value, void *attr_dst);
void				set_char_attr(char *attr_value, void *attr_dst);

static const t_class	g_class[N_CLASS] = {
	{
		.init_quadric = init_sphere,
		.name = "sphere"
	}, {
		.init_quadric = init_plane,
		.name = "plane"
	}, {
		.init_quadric = init_cylinder,
		.name = "cylinder"
	}, {
		.init_quadric = init_cone,
		.name = "cone"
	}, {
		.init_quadric = NULL,
		.name = "light"
	}
};

static const t_set_attr	g_set_attr[N_ATTR] = {
	{
		.set_attr = set_double_attr,
		.attr = "x",
		.struct_offset = 32
	}, {
		.set_attr = set_double_attr,
		.attr = "y",
		.struct_offset = 40
	}, {
		.set_attr = set_double_attr,
		.attr = "z",
		.struct_offset = 48
	}, {
		.set_attr = set_double_attr,
		.attr = "radius",
		.struct_offset = 24
	}, {
		.set_attr = set_color_attr,
		.attr = "color",
		.struct_offset = 4
	}, {
		.set_attr = set_surface_attr,
		.attr = "surface",
		.struct_offset = 1
	}, {
		.set_attr = set_char_attr,
		.attr = "axe",
		.struct_offset = 0
	}, {
		.set_attr = set_vec_attr,
		.attr = "rot",
		.struct_offset = 56
	}, {
		.set_attr = set_vec_attr,
		.attr = "scale",
		.struct_offset = 80
	}, {
		.set_attr = set_vec_attr,
		.attr = "pos",
		.struct_offset = 32
	}
};

static const char		*g_surface[N_ST] = {
	"normal",
	"mirror",
	"checkerboard"
};

static const int		g_tt[N_TT][2] = {
	{TT_DEF, TTE_DEF},
	{TT_CLASS, TTE_CLASS},
	{TT_NAME, TTE_NAME},
	{TT_OBJECT, TTE_OBJECT},
	{TT_START_BLOCK, TTE_START_BLOCK},
	{TT_END_BLOCK, TTE_END_BLOCK},
	{TT_ATTR, TTE_ATTR},
	{TT_ATTR_VALUE, TTE_ATTR_VALUE}
};

//typedef	void	(*gen_obj)(t_quadric*, t_attr);
/*
** main.c
*/
void				init_struct(t_coef *scoef);
void				new_image(t_coef *scoef);
void				put_pixel(t_img s, t_pxl p, t_vec3 color, t_coef *c);
int					quit(void);
/*
** init.c
*/
void				init_coef(t_control *l);
void				init_w(t_control *l);
t_vec3				vec3(double x, double y, double z);
/*
** rt.c
*/
void				increment(t_pxl *p);
void				rt(t_thread *l);
t_vec3				get_color(t_control *l, int nb_ite, t_ray ray, t_obj *light);
t_inter				intersec(int i, t_quadric q, t_vec3 eye, t_vec3 dir, \
					t_control *l);
t_vec3				ombre(t_ray ray, t_control *l, t_inter t, t_obj *light);
t_pxl				init_pxl(int x, int y);
/*
** ope_vec.c
*/
t_vec3				normalize(t_vec3 v);
t_vec3				sub_vec3(t_vec3 a, t_vec3 b);
t_vec3				add_vec3(t_vec3 a, t_vec3 b);
t_vec3				k_vec3(double k, t_vec3 b);
t_vec3				ope_divv1(t_vec3 b, double a);
/*
** ope_vec2.c
*/
t_vec3				rotate_cam(t_vec3 d, double x, double y, double z);
t_vec3				rot_cam_x(t_vec3 d, double x);
t_vec3				rot_cam_y(t_vec3 d, double y);
t_vec3				rot_cam_z(t_vec3 d, double z);
/*
** aliasing.c
*/
t_ray				anti_alias(t_pxl p, t_ray ray, int i, t_coef *t);
void				init_x_y(double *x, double *y, int i);
t_vec3				aliasing(t_control *l, t_ray ray);
/*
** quadric.c
*/
void				init_quadric(t_quadric *q);
void				print_q(t_quadric q);
t_vec3				get_normal(t_quadric q, t_vec3 p);
void				gen_attr(t_obj *obj);
void				translate(t_quadric *q, t_vec3 v);
void				scale(t_quadric *q, t_vec3 v);
void				rotate(t_quadric *q, t_vec3 rot);
/*
** surface.c
*/
void        		init_sphere(t_quadric *q, t_attr attr);
void        		init_cylinder(t_quadric *q, t_attr attr);
void        		init_plane(t_quadric *q, t_attr attr);
void        		init_cone(t_quadric *q, t_attr attr);
void				init_object(t_obj *obj, uint32_t id);
/*
** rotation.c
*/
void				rot_z(t_quadric *q, double n);
void				rot_x(t_quadric *q, double n);
void				rot_y(t_quadric *q, double n);
/*
** filtre.c
*/
void				cartoon(t_vec3 *color);
void				carton(t_vec3 *color);
void				sepia(t_vec3 *color);
void				negatif(t_vec3 *color);
void				black_n_white(t_vec3 *color);
/*
** multithread.c
*/
void				thread_sub_1(t_thread *thread, t_control *l, int i);
void				thread_sub_2(t_thread *thread, t_control *l);
void				multithread(t_control *l);
/*
** utils.c
*/
void				ft_putfloat(float d, double eps);
void				reverse(char *str, int len);
int					inttostr(int x, char *str, int d);
void				ftoa(float n, char *res, int p);
/*
** key_pr.c
*/
int					main_loop(t_control *e);
int					key_r_2(int k, t_control *e);
int					key_r(int k, t_control *e);
/*
** keyhook.c
*/
void				trace_info(t_control *c);
int					ft_key_aa(t_control *e);
int					ft_key_camrot(t_control *e);
int					ft_key_camtrans(t_control *e);
/*
** mlx.c
*/
void				put_pixel_circle(t_img i, t_circle c, int x, int y);
void				mlx_image_to_alpha(t_img img, int n);
void				put_pixel_rect(t_img i, t_rect r, int x, int y);
void				mlx_rect(t_rect rect, t_coef *coef);
void				mlx_scroll_bar(t_scrol s, t_coef *coef);
/*
** autres.c
*/
void				borne(t_vec3 *color);
void				init_mouv(t_control *l);
double				getnorm2(t_vec3 p);
double				dot(t_vec3 p, t_vec3 b);
t_vec3				moy_point(t_vec3 *moy, int antial);
void				gen_quadric(t_quadric *q);
int					check_arg(int ac, char **av);
void				filtre(t_coef *c, t_vec3 *color);
void				increment(t_pxl *p);
/*
** menu_hook.c
*/
int					menu_hook_update(int k, t_control *l);
int					menu_hook_add(int k, t_control *l);
int					menu_hook_cancel(int k, t_control *l);
int					menu_hook_delete(int k, t_control *l);
int					add_mouse_hook(int k, int x, int y, t_control *l);
/*
** menu_hook_1.c
*/
void				menu_hook_type(int k, int x, int y, t_control *l);
void				menu_hook_axe(int k, int x, int y, t_control *l);
void				menu_hook_rad(int k, int x, int y, t_control *l);
void				menu_hook_r(int k, int x, int y, t_control *l);
void				menu_hook_g(int k, int x, int y, t_control *l);
/*
** menu_hook_2.c
*/
void				menu_hook_b(int k, int x, int y, t_control *l);
void				menu_hook_posx(int k, int x, int y, t_control *l);
void				menu_hook_posy(int k, int x, int y, t_control *l);
void				menu_hook_posz(int k, int x, int y, t_control *l);
void				menu_hook_rotx(int k, int x, int y, t_control *l);
/*
** menu_hook_3.c
*/
void				menu_hook_roty(int k, int x, int y, t_control *l);
void				menu_hook_rotz(int k, int x, int y, t_control *l);
void				menu_hook_strx(int k, int x, int y, t_control *l);
void				menu_hook_stry(int k, int x, int y, t_control *l);
void				menu_hook_strz(int k, int x, int y, t_control *l);
/*
** export.c
*/
void				expand_name(t_control *l, char c);
void				trunc_name(t_control *l);
void				refresh_name(t_control *l);
int					hook_rename(int k, t_control *l);
void				rename_win(t_control *l);
/*
** export_2.c
*/
void				hook_mac_rename(t_control *l, int k);
void				hook_mac_rename2(t_control *l, int k);
void				hook_mac_rename3(t_control *l, int k);
/*
** export_3.c
*/
void				export_header_init(t_export *e);
void				export_header_write(t_export *e, int fd);
void				export_file(t_control *l);
/*
** menu.c
*/
void				hook_not_0(t_control *l, void *img, int *w, int *h);
int					main_mouse_hook_not_2(int x, int y, t_control *l);
int					main_mouse_hook_not(int x, int y, t_control *l);
int					main_mouse_hook(int k, int x, int y, t_control *l);
/*
** menu_2.c
*/
void				hook_not_5(t_control *l, void *img, int *w, int *h);
void				hook_not_4(t_control *l, void *img, int *w, int *h);
void				hook_not_3(t_control *l, void *img, int *w, int *h);
void				hook_not_2(t_control *l, void *img, int *w, int *h);
void				hook_not_1(t_control *l, void *img, int *w, int *h);
/*
** trace_info_0.c
*/
void				trace_info_0_3(t_control *c, int *h, int col);
void				trace_info_0_2(t_control *c, int *h, int col);
void				trace_info_0_1(t_control *c);
void				trace_info_0_0(t_control *c);
void				trace_info_0(t_control *c);
/*
** trace_info_1.c
*/
void				trace_info_1_2(t_img *bouton, t_control *c, int *n);
void				trace_info_1_1(t_img *bouton, t_control *c, int *n);
void				trace_info_1_0(t_scrol *lum, t_scrol *scroll);
void				trace_info_1(t_control *c);
/*
** trace_info_2.c
*/
void				trace_info_2(t_control *c);
/*
** trace_info_3.c
*/
void				trace_info_3_3(t_control *l);
void				trace_info_3_2(t_control *l, void *img);
void				trace_info_3_1(t_control *l);
void				trace_info_3_0(t_control *l);
void				trace_info_3(t_control *l, int status);
/*
** loadbar.c
*/
void				fill_img(char *data, int w, int h, t_col color);
void				ft_loadbar(t_coef *t, int n);
/*
** mlx_2.c
*/
void				mlx_circle_1(t_circle c, t_img img, int i, int j);
void				mlx_circle_2(t_circle c, t_img img, int d);
void				mlx_circle(t_circle c, t_coef *coef);
/*
** utils_2.c
*/
void				ft_logo(t_coef *t);
void				fill_menu(t_coef *t, void *win);
t_obj				*get_obj(t_obj **start, size_t n);
t_obj				*get_light_by_id(t_obj *obj, size_t n);
void				get_n_obj(t_obj **start, int *nb_obj, int *nb_luz);
void   				free_object_by_id(t_obj **obj, int id);
/*
** main_mouse_hook_0.c 
*/
void				main_mouse_hook_5(int k, int x, int y, t_control *l);
void				main_mouse_hook_4(int k, int x, int y, t_control *l);
void				main_mouse_hook_3(int k, int x, int y, t_control *l);
void				main_mouse_hook_2(int k, int x, int y, t_control *l);
void				main_mouse_hook_1(int k, int x, int y, t_control *l);
/*
** main_mouse_hook_1.c 
*/
void				main_mouse_hook_10(int k, int x, int y, t_control *l);
void				main_mouse_hook_9(int k, int x, int y, t_control *l);
void				main_mouse_hook_8(int k, int x, int y, t_control *l);
void				main_mouse_hook_7(int k, int x, int y, t_control *l);
void				main_mouse_hook_6(int k, int x, int y, t_control *l);
/*
** damier.c
*/
void				init_dam(t_control *l, t_inter inter, t_damier *a);
t_vec3				damier(t_control *l, t_inter inter);
/*
** key_pr_2.c
*/
void				key_p_1(int k, t_control *e);
void				key_p_2(int k, t_control *e);
void				key_p_3(int k, t_control *e);
void				key_p_4(int k, t_control *e);
int					key_p(int k, t_control *e);
/*
** parser.c
*/
void				exit_error(const char *err);
void				*strjou1(void *dst, const void *src, uint64_t n);
void				*get_file(const char *filename);
void				free_token(t_token *token);
t_token				*new_token(void *data, char type);
void				add_token(t_token **token, void *data, char type);
void				*get_token(char *file, char *end, uint8_t len, t_token **token);
void				*get_basic_token(char *file, t_token **token);
void				*get_quote_token(char *file, t_token **token);
void				*get_attr_token(char *file, t_token **token);
void				*get_block_token(char *file, t_token **token);
void				tokenize_scene(char *file, t_token **token);
void				dump_token(t_token *token);
int					check_foreach_class(char *data);
int					check_valid_chars(char *data, const char *valid);
int					check_data_from_type(t_token *token);
int					check_token_loop(t_token *token, uint8_t *expt);
int					check_token(t_token *token);
void				edit_token_types(t_token *token);
void				set_double_attr(char *attr_value, void *attr_dst);
void				set_vec_attr(char *attr_value, void *attr_dst);
void				set_color_attr(char *attr_value, void *attr_dst);
void				set_surface_attr(char *attr_value, void *attr_dst);
void				set_char_attr(char *attr_value, void *attr_dst);
void				set_attr(t_obj *obj, char *attr, char *attr_value);
t_obj				*new_object(char *obj_class);
t_obj				*add_object(t_obj **obj, char *obj_class);
int					create_scene(t_obj **obj, t_token *token, char *obj_class, char *obj_name);
int					handle_token(t_obj **obj, t_token *token);
void				free_object(t_obj *obj);
void				dump_obj(t_obj *obj);
t_obj				*handle_scene(char *file);

#endif
