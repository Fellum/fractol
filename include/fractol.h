/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:09:19 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 20:09:21 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "canvas.h"
# include "mlx_defs.h"

typedef int	(*t_fract_func)(double, double, void *);

typedef struct		s_fractstate
{
	double			max_x;
	double			max_y;
	double			min_x;
	double			min_y;
	double			scale_x;
	double			scale_y;
	char			mouse_seed;
	double			seed_x;
	double			seed_y;
	int				max_iter;
	unsigned char	cur_f_id;
	t_fract_func	cur_func;
	char			cur_color;
}					t_fractstate;

typedef struct		s_wndstate
{
	int				height;
	int				width;
	int				start_line;
	int				end_line;
	void			*mlx;
	void			*wnd;
	t_canvas		*canvas;
	char			*name;
}					t_wndstate;

typedef struct		s_inputstate
{
	char			kstate[200];
	char			mkstate[8];
	int				mpos[2];
	int				old_mpos[2];
}					t_inputstate;

typedef struct		s_fract
{
	t_wndstate		wstate;
	t_inputstate	instate;
	t_fractstate	fstate;
	t_fractstate	def_fstate;

}					t_fract;

# define NUM_OF_FRACTS 5
# define ITER_TRESHOLD 3000
# define THREADS 10
# define ID_MOUSE_SEED K_SPACE
# define ID_ZOOM_IN M_SUP
# define ID_ZOOM_OUT M_SDOWN
# define ID_DRAG M_LB
# define ID_DROP K_RETURN
# define ID_EXIT K_ESC
# define ID_PCOLOR K_DOWN
# define ID_NCOLOR K_UP
# define ID_NFRACT K_RIGHT
# define ID_PFRACT K_LEFT
# define ID_ITERUP K_PLUS
# define ID_ITERDOWN K_MINUS

void				draw_fract(t_fract *fract);
void				apply_instate(t_fract *data);
int					get_color(int cur_iter, t_fractstate *data);

#endif
