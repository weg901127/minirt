/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_diameter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:35:44 by gilee             #+#    #+#             */
/*   Updated: 2021/04/27 02:18:06 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	set_diameter(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->diameter = atof(*tmp);
}