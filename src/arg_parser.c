#include "fractol.h"
#include "arg_parser.h"

void	parse_args(t_args *res, int argc, char **argv)
{

}

void	fill_data(t_fract *fract_data, t_args *args)
{
	fract_data->wstate.height = 1000;
	fract_data->wstate.width = 1000;
	fract_data->wstate.name = "Kek";//args->fname;
}