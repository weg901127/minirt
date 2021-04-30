/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@42seoul.student.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:56:35 by gilee             #+#    #+#             */
/*   Updated: 2021/04/29 16:59:01 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <string.h>  //test
# include <stdio.h>   //test
# include <fcntl.h>
# include <math.h>
# include "type.h"
# include "parse/gnl/get_next_line.h"

#define ERROR 1
#define DONE 0
#define R_FLAG 1
#define A_FLAG 2

int   ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void  *ft_memset(void *b, int c, size_t len);
char  **ft_split(char const *s, char c);
int   ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);

void  init_list(t_list **list);
void  add_node(t_list *list, t_rt_info *data);

void  search_node(t_list *list, char *s);
void  free_node(t_list **list);



/* validation_utils.c */
void  free_split(char ***split);
int   count_split(char **split);
int   count_char(char **split, char c);
int check_split(char ***split);

/* set_coordinate.c */
int   set_coor1(char ***split, t_rt_info *data, int seq);
int   set_coor2(char ***split, t_rt_info *data, int seq);
int   set_coor3(char ***split, t_rt_info *data, int seq);

/* set_vector.c */
int   set_vector(char ***split, t_rt_info *data, int seq);

/* set_color.c */
int   set_color(char ***split, t_rt_info *data, int seq);

/* set_width_height.c */
int   set_width_height(char ***split, t_rt_info *data, int seq);

/* set_brightness.c */
int   set_brightness(char ***split, t_rt_info *data, int seq);

/* set_diameter.c */
void	set_diameter(char ***split, t_rt_info *data, int seq);

/* set_side_size.c */
void	set_side_size(char ***split, t_rt_info *data, int seq);

/* set_view_degree.c */
int   set_view_degree(char ***split, t_rt_info *data, int seq);

/* set_figure.c */
int   set_sphere(char **split, t_list **list);
int   set_plane(char **split, t_list **list);
int   set_square(char **split, t_list **list);
int   set_cylinder(char **split, t_list **list);
int   set_triangle(char **split, t_list **list);

/* set_view.c */
int   set_resolution(char **split, t_list **list, int *capital);
int   set_ambient(char **split, t_list **list, int *capital);
int   set_camera(char **split, t_list **list);
int   set_light(char **split, t_list **list);

/* put_err.c */
int	put_err(char **line, int fd, t_list **list, char ***split);

/* check_var.c */
int check_var(char ***split, t_list **list);

/* parse.c */
int parse(int argc, char **argv, t_list **list);
#endif
