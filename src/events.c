#include "mlx_defs.h"
#include "fractol.h"
#include <stdlib.h>

int	key_press(int key, t_inputstate *state)
{
	return (0);
}

int key_release(int key, t_inputstate *state)
{
	return (0);
}

int	close_event(t_fract *data)
{
	exit(0);
	return (0);
}

int	draw_tick(t_fract *data)
{
	return (0);
}