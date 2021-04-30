#include "test.h"
typedef t_vec t_point;
typedef struct s_camera
{
    double  viewport_h;
    double  viewport_w;
    double  focal_length;
    t_point origin;
    t_vec   horizontal;
    t_vec   vertical;
    t_vec   lower_left_corner;
}              t_camera;

t_vec    *ft_vec_create(t_vec *vec, double x, double y, double z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
    return (vec);
}

void        ft_camera_create(t_camera *cam, double aspect_ratio)
{
    cam->viewport_h = 4.0;
    cam->viewport_w = aspect_ratio * cam->viewport_h;
    cam->focal_length = 2.0;
    ft_vec_create(&cam->origin , 0.0, 0.0, 0.0);
    ft_vec_create(&cam->horizontal, cam->viewport_w, 0.0, 0.0);
    ft_vec_create(&cam->vertical, 0.0, cam->viewport_h, 0.0);
    cam->lower_left_corner.x = cam->origin.x - (cam->horizontal.x / 2) 
    - (cam->vertical.x / 2) - 0;
    cam->lower_left_corner.y = cam->origin.y - (cam->horizontal.y / 2) 
    - (cam->vertical.y / 2) - 0;
    cam->lower_left_corner.z = cam->origin.z - (cam->horizontal.z / 2) 
    - (cam->vertical.z / 2) - cam->focal_length;
}

t_ray       *ft_camera_ray_cal(t_ray *new_ray, t_camera *cam, double u, double v)
{
    t_vec cal;

    cal.x = cam->lower_left_corner.x + u*cam->horizontal.x + v*cam->vertical.x
            - cam->origin.x;
    cal.y = cam->lower_left_corner.y + u*cam->horizontal.y + v*cam->vertical.y
            - cam->origin.y;
    cal.z = cam->lower_left_corner.z + u*cam->horizontal.z + v*cam->vertical.z
            - cam->origin.z;
    return (ft_ray_create(new_ray, &(cam->origin), &cal));
}

t_color     *ft_ray_color(t_color *new_ray, t_ray *r)
{
    double  t;
    t_vec   unit_dir;
    t_color cal1;
    t_color cal2;

    ft_vec_unit(&unit_dir, &(r->dir));
    t = 0.5 * (unit_dir.y + 1.0);
    ft_vec_multi_double(&cal1, (1.0 - t), ft_vec_create(&cal1, 1.0, 1.0, 1.0));
    ft_vec_multi_double(&cal2, t, ft_vec_create(&cal2, 0.5, 0.7, 1.0));
    return (ft_vec_add(new_ray, &cal1, &cal2));
}