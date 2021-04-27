/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:08:36 by gilee             #+#    #+#             */
/*   Updated: 2021/04/27 23:41:32 by gilee            ###   ########.fr       */
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

int check_split(char ***split)
{
	char **tmp;
	int		k;
	tmp = *split;
	k = 0;
	tmp++;
	while (*tmp)
	{
		while ((*tmp)[k])
		{
			if (((*tmp)[k] > '/' && (*tmp)[k] < ':') || (*tmp)[k] == '.' || (*tmp)[k] == ',' || ((*tmp)[k] == '-' && k == 0))
			{
				k++;
				continue;
			}
			return (ERROR);
		}
		k = 0;
		tmp++;
	}
	return (DONE);
}