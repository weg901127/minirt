#include "test.h"

t_point *ft_ray_hat(t_point *new_ray, t_ray *ray, double t)
{
    new_ray->x = ray->orig.x + t * ray->dir.x;
    new_ray->y = ray->orig.y + t * ray->dir.y;
    new_ray->z = ray->orig.z + t * ray->dir.z;
    return (new_ray);
}