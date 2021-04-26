/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:08:36 by gilee             #+#    #+#             */
/*   Updated: 2021/04/27 02:15:06 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	free_split(char ***split)
{
	int k;

	k = 0;
	while (*(*split + k) != 0)
		free(*(*split + k++));
	free(*split);
}

int		count_split(char **split)
{
	int k;

	k = 0;
	while (*split++)
		k++;
	return (k);
}

int		count_char(char **split, char c)
{
	int		k;
	char	*tmp;

	k = 0;
	tmp = *split;
	while (*tmp++)
	{
		if (*tmp == c)
			k++;
	}
	return (k);
}
