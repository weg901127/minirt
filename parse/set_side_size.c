/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_side_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:34:56 by gilee             #+#    #+#             */
/*   Updated: 2021/04/27 02:18:17 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	set_side_size(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->side_size = atof(*tmp);
}
