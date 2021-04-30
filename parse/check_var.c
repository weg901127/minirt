/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 01:31:56 by gilee             #+#    #+#             */
/*   Updated: 2021/04/29 16:58:24 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int check_var(char ***split, t_list **list)
{
	int			k;
	static int	capital;

	k = count_split(*split);
	if (***split == 'R' && k == 3 && !(capital & R_FLAG))
		return (set_resolution(*split, list, &capital));
	else if(***split == 'A' && k == 3 && !(capital & A_FLAG))
		return (set_ambient(*split, list, &capital));
	else if(***split == 'c' && k == 4)
		return (set_camera(*split, list));
	else if(***split == 'l' && k == 4)
		return (set_light(*split, list));
	else if(***split == 's' && k == 4)
		return (set_sphere(*split, list));
	else if(***split == 'p' && k == 4)
		return (set_plane(*split, list));
	else if(***split == 's' && k == 5)
		return (set_square(*split, list));
	else if(***split == 'c' && k == 6)
		return (set_cylinder(*split, list));
	else if(***split == 't' && k == 5)
		return (set_triangle(*split, list));
	return (ERROR);
}
