#ifndef ARG_PARSER_H
# define ARG_PARSER_H

typedef struct	s_args
{
	char	*fname;
}				t_args;

# define DEFAULT_HEIGHT 1000
# define DEFAULT_WIDTH 1000
# define DEFAULT_MINX -2
# define DEFAULT_MINY -2
# define DEFAULT_MAXX 2
# define DEFAULT_MAXY 2


# define WSTATE(tfract) (tfract->wstate)
# define FSTATE(tfract) (tfract->fstate)
# define INSTATE(tfract) (tfract->instate)

void	parse_args(t_args *res, int argc, char **argv);
void	fill_data(t_fract *fract, t_args *args);

#endif
