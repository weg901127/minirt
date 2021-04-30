#ifndef TEST_H
# define TEST_H

typedef struct s_vec
{
    double x;
    double y;
    double z;
}              t_vec;

typedef t_vec t_point;
typedef t_vec t_color;

typedef struct  s_ray
{
    t_point     orig;
    t_vec       dir;
}               t_ray;

#endif