/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:24:12 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/22 12:51:44 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

typedef struct		s_col
{
	int				r;
	int				g;
	int				b;
}					t_col;

typedef struct		s_pix
{
	int				x;
	int				y;
	int				z;
	t_col			color;
}					t_pix;

typedef struct		s_lst
{
	t_pix			pix;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_pic
{
	void			*mlx_p;
	void			*win_p;
	float			zoom;
	int				fd;
	int				show;
	float			scale[3];
	int				wind[2];
	int				pic[2];
	int				xyz[3];
	float			an[3];
	int				bst;
	t_lst			*dots;
	t_pix			**dotp;
	char			*name;
}					t_pic;

t_col				get_color(char *str);
t_col				convert_to_color(char *str);
t_col				convert_to_rgb(int rgb);
int					convert_to_dec(t_col color);
int					what_n(char c);

int					check_arg(int argc, char **argv, int *fd);
int					find_length(char *line);

int					readfile(int fd, t_pic *pic);
int					readline(char *line, t_pic *pic);
int					add_line(t_pic *pic, char *line);
int					make_points(t_pic *pic, char **arr);
t_pix				**conv_to_matr(t_pic *pic);
void				fill_line(t_pix *arr, t_lst **curr, int height);

t_lst				*ft_newpix(t_pix pix);
void				ft_lstaddend_x(t_lst **lst, t_lst *dot);

void				draw_pic(t_pic *pic);
void				init_ptrs(t_pic *pic);
void				brez(t_pic *pic, t_pix p0, t_pix p1);
void				do_x(int *e, int d, int *x, int s);
t_pix				conv_p(t_pic *pic, int i, int j);
t_pix				conv_3d(t_pix pix, float axyz[3]);

void				init_binds(t_pic *pic);
int					choice(int key, void *par);
int					exit_press(void);
int					zoom_pic(int key, void *par);
int					move_pic(int k, void *par);
int					rotate_pic(int k, void *par);
int					scale_pic(int k, void *par);
int					back_to_normal(void *par);
void				refresh_pic(t_pic *pic);
void				set_tutorial(t_pic *pic);
int					tut(void *pic);
void				set_hint(t_pic *pic);
void				check(t_pic *pic);

#endif
