#ifndef MINIRT_H
# define MINIRT_H
# include <string.h>  //test
# include <stdio.h>   //test
# include <fcntl.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"

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
  unsigned int red;
  unsigned int green;
  unsigned int blue;
}               t_color;

typedef struct  s_rt_info
{
  char          *id;
  t_resolution  resolution;//> 0
  t_xyz         coor1;
  t_xyz         coor2;
  t_xyz         coor3;
  t_xyz         normalized_vector;//-1~1
  t_color       color;//0~255
  unsigned int  view_degree;//0~180
  float         brightness;//0~1
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


//add ft_atof
int	ft_atoi(const char *str);

//utils
int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int count_split(char **split);

//add element
int add_color(char **split, t_color *color);
int add_coordinate(char **split, t_xyz *coor);
int add_normalized_vector(char **split, t_xyz *normalized_vector);
int add_r(char **split, t_rt_info data, t_list *list);
int add_a(char **split, t_rt_info data, t_list *list);
int add_c(char **split, t_rt_info data, t_list *list);
int add_l(char **split, t_rt_info data, t_list *list);
int add_sp(char **split, t_rt_info data, t_list *list);
int add_pl(char **split, t_rt_info data, t_list *list);
int add_sq(char **split, t_rt_info data, t_list *list);
int add_cy(char **split, t_rt_info data, t_list *list);
int add_tr(char **split, t_rt_info data, t_list *list);

//list function
void  init_list(t_list **list);
void  add_node(t_list *list, t_rt_info data);
void search_node(t_list *list, char *s);
void del_node(t_list **list);

//split
static int	cnt_word(char const *s, char c);
static int	cnt_letter(char const *s, char c);
char	**allo_free(char **rst);
static char	**fill_rst(char **rst, char const *s, char c);
char		**ft_split(char const *s, char c);
#endif
