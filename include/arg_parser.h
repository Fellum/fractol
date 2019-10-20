#ifndef ARG_PARSER_H
# define ARG_PARSER_H

typedef struct	s_args
{
	char	*fname;
}				t_args;

void	parse_args(t_args *res, int argc, char **argv);
void	fill_data(t_fract *fract_data, t_args *args);

#endif
