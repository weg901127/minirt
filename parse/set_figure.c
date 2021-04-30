/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:28:06 by gilee             #+#    #+#             */
/*   Updated: 2021/04/29 16:58:24 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

int	set_sphere(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "sp";
	res |= set_coor1(&split, &data, 1);
	set_diameter(&split, &data, 2);
	res |= set_color(&split, &data, 3);
	add_node(*list, &data);
	return (res);
}

int set_plane(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "pl";
	res |= set_coor1(&split, &data, 1);
	res |= set_vector(&split, &data, 2);
	res |= set_color(&split, &data, 3);
	add_node(*list, &data);
	return (res);
}

int set_square(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "sq";
	res |= set_coor1(&split, &data, 1);
	res |= set_vector(&split, &data, 2);
	set_side_size(&split, &data, 3);
	res |= set_color(&split, &data, 4);
	add_node(*list, &data);
	return (res);
}

int set_cylinder(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "cy";
	res |= set_coor1(&split, &data, 1);
	res |= set_vector(&split, &data, 2);
	set_diameter(&split, &data, 3);
	set_side_size(&split, &data, 4);
	res |= set_color(&split, &data, 5);
	add_node(*list, &data);
	return (res);
}

int set_triangle(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "tr";
	res |= set_coor1(&split, &data, 1);
	res |= set_coor2(&split, &data, 2);
	res |= set_coor3(&split, &data, 3);
	res |= set_color(&split, &data, 4);
	add_node(*list, &data);
	return (res);
}
