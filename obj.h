/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:51:07 by gilee             #+#    #+#             */
/*   Updated: 2021/04/30 04:50:40 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H
#include "type.h"
#include <math.h>

t_xyz mul_vec(t_xyz vec1, t_xyz vec2);
t_xyz sub_vec(t_xyz vec1, t_xyz vec2);
t_xyz add_vec(t_xyz vec1, t_xyz vec2);
t_xyz dot_pro_vec(t_xyz vec1, t_xyz vec2, double rad);

#endif