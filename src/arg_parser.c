#include "fractol.h"
#include "arg_parser.h"

void	parse_args(t_args *res, int argc, char **argv)
{

}

void	fill_data(t_fract *fract, t_args *args)
{
	fract->wstate.height = DEFAULT_HEIGHT;
	fract->wstate.width = DEFAULT_WIDTH;
	fract->fstate.max_x = DEFAULT_MAXX;
	fract->fstate.max_y = DEFAULT_MAXY;
	fract->fstate.min_x = DEFAULT_MINX;
	fract->fstate.min_y = DEFAULT_MINY;

	fract->fstate.scale_x = fract->wstate.width /
			(fract->fstate.max_x - fract->fstate.min_x);
	fract->fstate.scale_y = fract->wstate.height /
							(fract->fstate.max_y - fract->fstate.min_y);
	fract->wstate.name = "Kek";//args->fname;
}