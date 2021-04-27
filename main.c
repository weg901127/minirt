#include "mlx.h"
#include "minirt.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
  char  *dst;
  int   offset;

  offset = y * data->line_length + x * (data->bits_per_pixel / 8); 
  dst = data->addr + offset;
  *(unsigned int*)dst = color; 
}
int	key_hook(int keycode, t_vars *vars)
{
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
int             main(int argc, char *argv[])
{
  t_list *list;
  int res;
  int img_width = 1920;
  int img_height = 1680;
  int centerX, centerY;
  //int color;
  int rad;
  rad = 200;
  centerX = img_width/2;
  centerY = img_height/2;
  t_data  img;
    t_vars  vars;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, img_width, img_height, "Hello world!");
    img.img = mlx_new_image(vars.mlx, img_width, img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
    res = parse(argc, argv, &list);
    if (!res)
  	{
    list->cur = list->head;
	while (list->cur)
	{
		printf("id : %s",list->cur->data.id);
		if (list->cur->data.resolution.width + list->cur->data.resolution.height)
			printf("\nresolution.width : %d, %d",list->cur->data.resolution.width,list->cur->data.resolution.height);
		if (list->cur->data.coor1.x + list->cur->data.coor1.y + list->cur->data.coor1.z)
			printf("\ncoor1.xyz : %f, %f, %f",list->cur->data.coor1.x,list->cur->data.coor1.y,list->cur->data.coor1.z);
		if (list->cur->data.coor2.x + list->cur->data.coor2.y + list->cur->data.coor2.z)
			printf("\ncoor2.xyz : %f, %f, %f",list->cur->data.coor2.x,list->cur->data.coor2.y,list->cur->data.coor2.z);
		if (list->cur->data.coor3.x + list->cur->data.coor3.y + list->cur->data.coor3.z)
			printf("\ncoor3.xyz : %f, %f, %f",list->cur->data.coor3.x,list->cur->data.coor3.y,list->cur->data.coor3.z);
		if (list->cur->data.normalized_vector.x + list->cur->data.normalized_vector.y + list->cur->data.normalized_vector.z)
			printf("\nvec.xyz : %f, %f, %f",list->cur->data.normalized_vector.x,list->cur->data.normalized_vector.y,list->cur->data.normalized_vector.z);
		if (list->cur->data.color.red + list->cur->data.color.green + list->cur->data.color.blue)
			printf("\ncolor.rgb : %f, %f, %f",list->cur->data.color.red,list->cur->data.color.green,list->cur->data.color.blue);
		if (list->cur->data.view_degree)
			printf("\nview_degree : %d",list->cur->data.view_degree);
		if (list->cur->data.brightness)
			printf("\nbrightness : %f",list->cur->data.brightness);
		if (list->cur->data.diameter)
			printf("\ndiameter : %f",list->cur->data.diameter);
		if (list->cur->data.side_size)
			printf("\nside_size : %f",list->cur->data.side_size);
		printf("\n--------------------------\n");
		list->cur = list->cur->next;
	}
    free_node(&list);
  }
/*
  for(int x = 0 ; x <= rad ; x++)
  {
    for(int y = 0; y <= rad ; y++)
    {
      if (x*x + y*y < rad * rad)
       my_mlx_pixel_put(&img, centerX + x, centerY + y, 0X00FF0000);
    }
  }
  for(int x = 0 ; x <= rad ; x++)
  {
    for(int y = 0; y <= rad ; y++)
    {
      if (x*x + y*y < rad * rad)
      my_mlx_pixel_put(&img, centerX - x, centerY - y, 0X00FF0000);
    }
  }
  for(int x = 0 ; x <= rad ; x++)
  {
    for(int y = 0; y <= rad ; y++)
    {
      if (x*x + y*y < rad * rad)
      my_mlx_pixel_put(&img, centerX - x, centerY + y, 0X00FF0000);
    }
  }
  for(int x = 0 ; x <= rad ; x++)
  {
    for(int y = 0; y <= rad ; y++)
    {
      if (x*x + y*y < rad * rad)
      my_mlx_pixel_put(&img, centerX + x, centerY - y, 0X00FF0000);
    }
  }
  */
    /*
    for (int i = 0 ; i < img_height - 1 ; ++i)
	{
		for (int j = 0 ; j < img_width - 1; ++j)
		{
			double r = (double)(img_width - j) / (img_width - 1);
			double g = (double)(i) / (img_height - 1);
			double b = 1;
			color = create_trgb(0, 255.999 * r, 255.999 * g, 255.999 * b);
      my_mlx_pixel_put(&img, j, i, color);
		}	
	}
*/

    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
    return(0);
}
