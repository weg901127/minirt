/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_view_degree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:32:46 by gilee             #+#    #+#             */
/*   Updated: 2021/04/27 02:18:26 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	set_view_degree(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->view_degree = ft_atoi(*tmp);
	if (data->view_degree < 0 || data->view_degree > 180)
		return (ERROR);
	return (DONE);
}
