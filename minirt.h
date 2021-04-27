#ifndef MINIRT_H
# define MINIRT_H
# include <string.h>  //test
# include <stdio.h>   //test
# include <fcntl.h>
//# include <stdlib.h>
//# include <unistd.h>
# include "parse/gnl/get_next_line.h"

#define ERROR 1
#define DONE 0
#define R_FLAG 1
#define A_FLAG 2

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
