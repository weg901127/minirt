/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:30:34 by gilee             #+#    #+#             */
/*   Updated: 2021/04/27 02:18:36 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int set_width_height(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->resolution.width = ft_atoi(*tmp);
	tmp++;
	data->resolution.height = ft_atoi(*tmp);
	if (data->resolution.width <= 0 || data->resolution.height <= 0)
		return (ERROR);
	return (DONE);
}
