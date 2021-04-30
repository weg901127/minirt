/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:21:32 by gilee             #+#    #+#             */
/*   Updated: 2021/04/29 16:58:24 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

int set_color(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;
	char		**tmp2;

	tmp = *split;
	tmp += seq;
	if (count_char(tmp, ',') != 2)
		return (ERROR);
	tmp2 = ft_split(*tmp, ',');
	if (!tmp2)
		return (ERROR);
	data->color.red = atof(*tmp2);
	data->color.green = atof(*(tmp2 + 1));
	data->color.blue = atof(*(tmp2 + 2));
	free_split(&tmp2);
	if (data->color.red < 0 \
	|| data->color.red > 255\
	|| data->color.green < 0\
	|| data->color.green > 255\
	|| data->color.blue < 0\
	|| data->color.blue > 255)
		return (ERROR);
	return (DONE);
}