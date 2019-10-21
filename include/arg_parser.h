/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:09:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 20:09:05 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PARSER_H
# define ARG_PARSER_H

typedef struct			s_args
{
	char			*wname;
	unsigned char	fid;
}						t_args;

# define DEFAULT_HEIGHT 1000
# define DEFAULT_WIDTH 1000
# define DEFAULT_MINX -2.0
# define DEFAULT_MINY -2.0
# define DEFAULT_MAXX 2.0
# define DEFAULT_MAXY 2.0
# define DEFAULT_MAXITER 50

void					parse_args(t_args *res, int argc, char **argv);
void					fill_data(t_fract *fract, t_args *args);

#endif
