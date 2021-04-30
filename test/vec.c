#include "test.h"

t_vec           *ft_vec_add(t_vec *new_vec, t_vec *u, t_vec *v)
{
    new_vec->x = u->x + v->x;
    new_vec->y = u->y + v->y;
    new_vec->z = u->z + v->z;
    return (new_vec);
}

t_vec           *ft_vec_sub(t_vec *new_vec, t_vec *u, t_vec *v)
{
    new_vec->x = u->x - v->x;
    new_vec->y = u->y - v->y;
    new_vec->z = u->z - v->z;
    return (new_vec);
}

t_vec           *ft_vec_multi(t_vec *new_vec, t_vec *u, t_vec *v)
{
    new_vec->x = u->x * v->x;
    new_vec->y = u->y * v->y;
    new_vec->z = u->z * v->z;
    return (new_vec);
}

t_vec           *ft_vec_div(t_vec *new_vec, t_vec *u, t_vec *v)
{
    new_vec->x = u->x / v->x;
    new_vec->y = u->y / v->y;
    new_vec->z = u->z / v->z;
    return (new_vec);
}

t_vec           *ft_vec_multi_double(t_vec *new_vec, double t, t_vec *v)
{
    new_vec->x = v->x * t;
    new_vec->y = v->y * t;
    new_vec->z = v->z * t;
    return (new_vec);
}

t_vec           *ft_vec_div_double(t_vec *new_vec, double t, t_vec *v)
{
    new_vec->x = v->x / t;
    new_vec->y = v->y / t;
    new_vec->z = v->z / t;
    return (new_vec);
}

double          ft_vec_dot(t_vec *u, t_vec *v)
{
    return (u->x * v->x + u->y * v->y + u->z * v->z);
}

t_vec           *ft_vec_cross(t_vec *new_vec, t_vec *u, t_vec *v)
{
    new_vec->x = u->y * v->z - u->z * v->y;
    new_vec->y = u->z * v->x - u->x * v->z;
    new_vec->z = u->x * v->y - u->y * v->x;
    return (new_vec);
}

double          ft_vec_len(t_vec *new_vec)
{
    return (sqrt(ft_vec_len_sqrt(new_vec)));
}

double          ft_vec_len_sqrt(t_vec *new_vec)
{
	return (pow(new_vec->x, 2.0) + pow(new_vec->y, 2.0) + pow(new_vec->z, 2.0));
}

t_vec           *ft_vec_unit(t_vec *new_vec, t_vec *v)
{
    return (ft_vec_div_double(new_vec, ft_vec_len(v), v));
}