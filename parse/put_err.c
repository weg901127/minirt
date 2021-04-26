/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 01:30:07 by gilee             #+#    #+#             */
/*   Updated: 2021/04/27 02:17:23 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	put_err(char **line, int fd, t_list **list, char ***split)
{
	write(1, "Error\n", 6);
	free(*line);
	close(fd);
	free_node(list);
	free_split(split);
	return (ERROR);
}
