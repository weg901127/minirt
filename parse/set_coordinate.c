/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:15:21 by gilee             #+#    #+#             */
/*   Updated: 2021/04/27 02:17:56 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int set_coor1(char ***split, t_rt_info *data, int seq)
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
	data->coor1.x = atof(*tmp2);
	data->coor1.y = atof(*(tmp2 + 1));
	data->coor1.z = atof(*(tmp2 + 2));
	free_split(&tmp2);
	return (DONE);
}

int set_coor2(char ***split, t_rt_info *data, int seq)
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
	data->coor2.x = atof(*tmp2);
	data->coor2.y = atof(*(tmp2 + 1));
	data->coor2.z = atof(*(tmp2 + 2));
	free_split(&tmp2);
	return (DONE);
}

int set_coor3(char ***split, t_rt_info *data, int seq)
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
	data->coor3.x = atof(*tmp2);
	data->coor3.y = atof(*(tmp2 + 1));
	data->coor3.z = atof(*(tmp2 + 2));
	free_split(&tmp2);
	return (DONE);
}
