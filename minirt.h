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

int	ft_atoi(const char *str);

void  init_list(t_list **list);
void  add_node(t_list *list, t_rt_info data);
int	ft_strcmp(const char *s1, const char *s2);
void search_node(t_list *list, char *s);
void del_node(t_list *list);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
static int	cnt_word(char const *s, char c);
static int	cnt_letter(char const *s, char c);
char	**allo_free(char **rst);
static char	**fill_rst(char **rst, char const *s, char c);
char		**ft_split(char const *s, char c);
#endif