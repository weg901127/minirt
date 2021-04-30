/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:50:59 by gilee             #+#    #+#             */
/*   Updated: 2021/04/29 16:51:02 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct  s_resolution
{
  int width;
  int height;
}               t_resolution;

typedef struct  s_xyz
{
  float x;
  float y;
  float z;
}               t_xyz;

typedef struct  s_color
{
  float red;
  float green;
  float blue;
}               t_color;

typedef struct  s_rt_info
{
  char          *id;
  t_resolution  resolution;
  t_xyz         coor1;
  t_xyz         coor2;
  t_xyz         coor3;
  t_xyz         normalized_vector;
  t_color       color;
  unsigned int  view_degree;
  float         brightness;
  float         diameter;
  float         side_size;
}               t_rt_info;

typedef struct  s_node
{
  t_rt_info     data;
  struct s_node *next;
}               t_node;

typedef struct  s_list
{
  t_node  *cur;
  t_node  *head;
  t_node  *tail;
}               t_list;

#endif