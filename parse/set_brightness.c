/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_brightness.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:33:33 by gilee             #+#    #+#             */
/*   Updated: 2021/04/29 16:58:24 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse.h"

int	set_brightness(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->brightness = atof(*tmp);
	if (data->brightness < 0 || data->brightness > 1)
		return (ERROR);
	return (DONE);
}
