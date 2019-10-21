/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:09:13 by jleann            #+#    #+#             */
/*   Updated: 2019/10/21 20:09:14 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_DATA_H
# define FILL_DATA_H

# include "arg_parser.h"

void			recalc_scale(t_fract *fract);
void			recalc_seed(t_fract *data);
t_fract_func	get_ffract_by_id(unsigned char id);

#endif
