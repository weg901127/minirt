#include "minirt.h"

int add_color(char **split, t_color *color)
{
	char **tmp_color;

	tmp_color = ft_split(*split, ',');
	if (count_split(tmp_color) != 3)
	{
		allo_free(tmp_color);
		return (-1);
	}
	color->red = atoi(*tmp_color);
	tmp_color++;
	color->green = atoi(*tmp_color);
	tmp_color++;
	color->blue = atoi(*tmp_color);

	tmp_color -= 2;
	allo_free(tmp_color);
	if (color->red > 255 || color->green > 255 || color->blue > 255)//unsigned int니까 0 이하는 X
		return (-1);
	return (0);
}

int add_coordinate(char **split, t_xyz *coor) //copy one for normalized vector
{
	char **coordinate;

	coordinate = ft_split(*split, ',');
	if (count_split(coordinate) != 3)
	{
		allo_free(coordinate);
		return (-1);
	}
	coor->x = atof(*coordinate);
	coordinate++;  
	coor->y = atof(*coordinate);
	coordinate++;  
	coor->z = atof(*coordinate);

	coordinate -= 2;//this too
	allo_free(coordinate);

	return (0);
}

int add_normalized_vector(char **split, t_xyz *normalized_vector) //copy one for normalized vector
{
	char **split_normal_vector;

	split_normal_vector = ft_split(*split, ',');
	normalized_vector->x = atof(*split_normal_vector);
	split_normal_vector++;
	normalized_vector->y = atof(*split_normal_vector);
	split_normal_vector++;  
	normalized_vector->z = atof(*split_normal_vector);

	split_normal_vector -= 2;//this too
	allo_free(split_normal_vector);
	if (normalized_vector->x < -1 || normalized_vector->x > 1 || normalized_vector->y < -1 ||
		normalized_vector->y > 1 || normalized_vector->z < -1 || normalized_vector->z > 1)
		return (-1);
	return (0);
}

int add_r(char **split, t_rt_info data, t_list *list)
{
	//notice : split count, element value ex) considered range and type
	data.id = "R";
	split++;
	data.resolution.width = ft_atoi(*split);
	split++;
	data.resolution.height = ft_atoi(*split);
	if (data.resolution.width < 1 || data.resolution.height < 1)//it's better be functionalize
		return (-1);

	add_node(list, data);
	return (0);
}
int add_a(char **split, t_rt_info data, t_list *list)
{
	data.id = "A";
	split++;
	data.brightness = atof(*split); //0.0 ~ 1.0
	if (data.brightness < 0 || data.brightness > 1)
		return (-1);
	split++;
	if (add_color(split, &data.color) == -1)
		return (-1);
	
	add_node(list, data);
	return (0);
}

int add_c(char **split, t_rt_info data, t_list *list)
{
  data.id = "c";
  split++;
  if (add_coordinate(split, &data.coor1) == -1)
	return (-1);
  split++;
  if (add_normalized_vector(split, &data.normalized_vector) == -1)
	return (-1);
  split++;
  data.view_degree = atoi(*split); //0~180
  if (data.view_degree < 0 || data.view_degree > 180)
	return (-1);

  add_node(list, data);
  return (0);
}

int add_l(char **split, t_rt_info data, t_list *list)
{
  data.id = "l";
  split++;
  if (add_coordinate(split, &data.coor1) == -1)
	return (-1);
  split++;
  data.brightness = atof(*split);
  if (data.brightness < 0 || data.brightness > 1)
	return (-1);
  split++;
  if (add_color(split, &data.color) == -1)
	return (-1);

  add_node(list, data);
  return (0);
}

int add_sp(char **split, t_rt_info data, t_list *list)
{
  data.id = "sp";
  split++;
  if (add_coordinate(split, &data.coor1) == -1)
	return (-1);
  split++;
  data.diameter = atof(*split);
  split++;
  if (add_color(split, &data.color) == -1)
	return (-1);
  
  add_node(list, data);
  return (0);
}
int add_pl(char **split, t_rt_info data, t_list *list)
{
	data.id = "pl";
	split++;
	if (add_coordinate(split, &data.coor1) == -1)
		return (-1);
	split++;
	if (add_normalized_vector(split, &data.normalized_vector) == -1)
		return (-1);
	split++;
	if (add_color(split, &data.color) == -1)
		return (-1);

	add_node(list, data);
	return (0);
}

int add_sq(char **split, t_rt_info data, t_list *list)
{
	data.id = "sq";
	split++;
	if (add_coordinate(split, &data.coor1) == -1)
		return (-1);
	split++;
	if (add_normalized_vector(split, &data.normalized_vector) == -1)
		return (-1);
	split++;
	data.side_size = atof(*split);
	split++;
	if (add_color(split, &data.color) == -1)
		return (-1);

	add_node(list, data);
	return (0);
}

int add_cy(char **split, t_rt_info data, t_list *list)
{
	data.id = "cy";
	split++;
	if (add_coordinate(split, &data.coor1) == -1)
		return (-1);
	split++;
	if (add_normalized_vector(split, &data.normalized_vector) == -1)
		return (-1);
	split++;
	data.diameter = atof(*split);
	split++;
	data.side_size = atof(*split);
	split++;
	if (add_color(split, &data.color) == -1)
		return (-1);

	add_node(list, data);
	return (0);
}

int add_tr(char **split, t_rt_info data, t_list *list)
{
	data.id = "tr";
	split++;
	if (add_coordinate(split, &data.coor1) == -1)
		return (-1);
	split++;
	if (add_coordinate(split, &data.coor2) == -1)
		return (-1);
	split++;
	if (add_coordinate(split, &data.coor3) == -1)
		return (-1);
	split++;
	if (add_color(split, &data.color) == -1)
		return (-1);
		
	add_node(list, data);
	return (0);
}
