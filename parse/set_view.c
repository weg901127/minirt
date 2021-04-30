/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 01:25:41 by gilee             #+#    #+#             */
/*   Updated: 2021/04/29 16:58:24 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

int	set_resolution(char **split, t_list **list, int *capital)
{
	t_rt_info	data;

	*capital += R_FLAG;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "R";
	set_width_height(&split, &data, 1);
	add_node(*list, &data);
	return (DONE);
}

int	set_ambient(char **split, t_list **list, int *capital)
{
	t_rt_info	data;
	int			res;

	*capital += A_FLAG;
	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "A";
	set_brightness(&split, &data, 1);
	res |= set_color(&split, &data, 2);
	add_node(*list, &data);
	return (res);
}

int	set_camera(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "c";
	res |= set_coor1(&split, &data, 1);
	res |= set_vector(&split, &data, 2);
	set_view_degree(&split, &data, 3);
	add_node(*list, &data);
	return (res);
}

int	set_light(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "l";
	res |= set_coor1(&split, &data, 1);
	set_brightness(&split, &data, 2);
	res |= set_color(&split, &data, 3);
	add_node(*list, &data);
	return (res);
}
