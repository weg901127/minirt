/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:22:22 by gilee             #+#    #+#             */
/*   Updated: 2021/04/29 16:58:24 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

int set_vector(char ***split, t_rt_info *data, int seq)
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
	data->normalized_vector.x = atof(*tmp2);
	data->normalized_vector.y = atof(*(tmp2 + 1));
	data->normalized_vector.z = atof(*(tmp2 + 2));
	free_split(&tmp2);
	if (data->normalized_vector.x < -1\
	|| data->normalized_vector.x > 1\
	|| data->normalized_vector.y < -1\
	|| data->normalized_vector.y > 1\
	|| data->normalized_vector.z < -1\
	|| data->normalized_vector.z > 1)
		return (ERROR);
	return (DONE);
}
