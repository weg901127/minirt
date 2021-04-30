/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:17:26 by gilee             #+#    #+#             */
/*   Updated: 2021/04/30 04:53:37 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../obj.h"

t_xyz mul_vec(t_xyz vec1, t_xyz vec2)
{
	t_xyz res;

	res.x = vec1.x * vec2.x;
	res.y = vec1.y * vec2.y;
	res.z = vec1.z * vec2.z;
	return (res);
}

t_xyz div_vec(t_xyz vec1, t_xyz vec2)
{
	t_xyz res;

	res.x = vec1.x / vec2.x;
	res.y = vec1.y / vec2.y;
	res.z = vec1.z / vec2.z;
	return (res);
}

t_xyz sub_vec(t_xyz vec1, t_xyz vec2)
{
	t_xyz res;

	res.x = vec1.x - vec2.x;
	res.y = vec1.y - vec2.y;
	res.z = vec1.z - vec2.z;
	return (res);
}

t_xyz add_vec(t_xyz vec1, t_xyz vec2)
{
	t_xyz res;

	res.x = vec1.x + vec2.x;
	res.y = vec1.y + vec2.y;
	res.z = vec1.z + vec2.z;
	return (res);
}

t_xyz double_mul_vec(double value, t_xyz vec)
{
	t_xyz res;

	res.x = vec.x * value;
	res.y = vec.y * value;
	res.z = vec.z * value;
	return (res);
}

t_xyz double_div_vec(double value, t_xyz vec)
{
	t_xyz res;

	res.x = vec.x / value;
	res.y = vec.y / value;
	res.z = vec.z / value;
	return (res);
}

/*
t_xyz dot_pro_vec(t_xyz vec1, t_xyz vec2, double rad)
{
	t_xyz res;

	res.x = fabs(vec1.x) * fabs(vec2.x) * cos(rad);
	res.y = fabs(vec1.y) * fabs(vec2.y) * cos(rad);
	res.z = fabs(vec1.z) * fabs(vec2.z) * cos(rad);
	return (res);
}
*/

double	dot_pro_vec(t_xyz vec1, t_xyz vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_xyz	cross_vec(t_xyz vec1, t_xyz vec2)
{
	t_xyz	res;

	res.x = vec1.y * vec2.z - vec1.z * vec2.y;
	res.y = vec1.x * vec2.z - vec1.z * vec2.x;
	res.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (res);
}

double vec_len(t_xyz )