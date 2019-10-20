#ifndef FRACTOL_H
# define FRACTOL_H

# include "canvas.h"

typedef int	(*t_fract_func)(double, double);

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
	t_fract_func	*cur_func;
}					t_fractstate;

typedef struct	s_wndstate
{
	int 		height;
	int 		width;
	void		*mlx;
	void		*wnd;
	t_canvas	*canvas;
	char		*name;
}				t_wndstate;

typedef struct	s_inputstate
{
	char		kstate[200];
	char		mkstate[5];
	int			mpos[2];
}				t_inputstate;

typedef struct		s_fract
{
	t_wndstate		wstate;
	t_inputstate	instate;
	t_fractstate	fstate;
}					t_fract;

#endif
