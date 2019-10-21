/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:44:46 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 18:44:48 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "fractol.h"
#include "arg_parser.h"

void			print_usage(void)
{
	ft_printf("Available fractals:\n");
	ft_printf("\"Julia\"\n\"Mandelbrot\"\n");
	ft_printf("\"Mirrored Julia\"\n\"Burning ship\"\n\"Sin Julia\"\n");
}

unsigned char	get_ffract_name(const char *fname)
{
	static const char	*fnames[NUM_OF_FRACTS] = {"Julia",
		"Mandelbrot",
		"Mirrored Julia",
		"Burning ship",
		"Sin Julia"
	};
	unsigned char		cur_name;

	cur_name = 0;
	while (cur_name < NUM_OF_FRACTS)
	{
		if (ft_strcmp(fname, fnames[cur_name]) == 0)
			return (cur_name);
		cur_name++;
	}
	return (NUM_OF_FRACTS);
}

void			parse_args(t_args *res, int argc, char **argv)
{
	res->wname = "FRACTOL";
	if (argc == 2)
	{
		if ((res->fid = get_ffract_name(argv[1])) == NUM_OF_FRACTS)
		{
			print_usage();
			exit(1);
		}
	}
	else
	{
		print_usage();
		exit(1);
	}
}
