#include <mlx.h>
#include "fractol.h"
#include "canvas.h"
#include "mlx_defs.h"
#include "events.h"
#include "arg_parser.h"

void	run_app(t_args *args)
{
	t_fract	data;

	fill_data(&data, args);
	data.wstate.mlx = mlx_init();
	data.wstate.wnd = mlx_new_window(data.wstate.mlx, data.wstate.width,
									 data.wstate.height, data.wstate.name);
	data.wstate.canvas = init_canvas(data.wstate.mlx, data.wstate.wnd,
									 data.wstate.width, data.wstate.height);
	mlx_hook(data.wstate.wnd, KEY_PRESS_HOOK, 0, key_press,
			&(data.instate));
	mlx_hook(data.wstate.wnd, KEY_RELEASE_HOOK, 0, key_release,
			&(data.instate));
	mlx_hook(data.wstate.wnd, MOUSE_MOVE_HOOK, 0, mouse_move,
			 &(data.instate));
	mlx_hook(data.wstate.wnd, MOUSE_PRESS_HOOK, 0, mouse_press,
			 &(data.instate));
	mlx_hook(data.wstate.wnd, MOUSE_RELEASE_HOOK, 0, mouse_release,
			 &(data.instate));
	mlx_hook(data.wstate.wnd, EXIT_HOOK, 0, close_event, &data);
	mlx_loop_hook(data.wstate.mlx, draw_tick, &data);
	mlx_loop(data.wstate.mlx);
}

int		main(int argc, char **argv)
{
	t_args	args;

	parse_args(&args, argc, argv);
	run_app(&args);
	return (0);
}