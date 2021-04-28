#include "minirt.h"

int add_color(char **split, t_color *color)
{
	char **tmp_color;
	int checker;

	tmp_color = ft_split(*split, ',');
	if (count_split(tmp_color) != 3)
	{
		allo_free(tmp_color);
		return (-1);
	}
	checker = 0;
	checker += check_int(*tmp_color);
	color->red = atoi(*tmp_color);
	tmp_color++;
	checker += check_int(*tmp_color);
	color->green = atoi(*tmp_color);
	tmp_color++;
	checker += check_int(*tmp_color);
	color->blue = atoi(*tmp_color);

	tmp_color -= 2;
	allo_free(tmp_color);
	if (color->red > 255 || color->green > 255 || color->blue > 255 || checker != 0)//unsigned int니까 0 이하는 X
		return (-1);
	return (0);
}

int add_coordinate(char **split, t_xyz *coor) //copy one for normalized vector
{
	char **coordinate;
	int checker;

	coordinate = ft_split(*split, ',');
	checker = 0;
	if (count_split(coordinate) != 3)
	{
		allo_free(coordinate);
		return (-1);
	}
	checker += check_double(*coordinate);
	coor->x = ft_atod(*coordinate);
	coordinate++;  
	checker += check_double(*coordinate);
	coor->y = ft_atod(*coordinate);
	coordinate++;  
	checker += check_double(*coordinate);
	coor->z = ft_atod(*coordinate);

	coordinate -= 2;//this too
	allo_free(coordinate);
	if (checker != 0)
		return (-1);
	return (0);
}

int add_normalized_vector(char **split, t_xyz *normalized_vector) //copy one for normalized vector
{
	char **split_normal_vector;
	int checker;

	split_normal_vector = ft_split(*split, ',');
	checker = 0;
	checker += check_double(*split_normal_vector);
	normalized_vector->x = ft_atod(*split_normal_vector);
	split_normal_vector++;
	checker += check_double(*split_normal_vector);
	normalized_vector->y = ft_atod(*split_normal_vector);
	checker += check_double(*split_normal_vector);
	split_normal_vector++;  
	normalized_vector->z = ft_atod(*split_normal_vector);

	split_normal_vector -= 2;//this too
	allo_free(split_normal_vector);
	if (normalized_vector->x < -1 || normalized_vector->x > 1 || normalized_vector->y < -1 ||
		normalized_vector->y > 1 || normalized_vector->z < -1 || normalized_vector->z > 1 || checker != 0)
		return (-1);
	return (0);
}

int add_r(char **split, t_rt_info data, t_list *list)
{
	int checker;

	data.id = "R";
	checker = 0 ;
	split++;
	checker = check_int(*split);
	data.resolution.width = ft_atoi(*split);
	split++;
	checker = check_int(*split);
	data.resolution.height = ft_atoi(*split);
	if (data.resolution.width < 1 || data.resolution.height < 1 || checker != 0)//it's better be functionalize
		return (-1);
	add_node(list, data);
	return (0);
}
int add_a(char **split, t_rt_info data, t_list *list)
{
	int checker;

	data.id = "A";
	checker = 0;
	split++;
	checker = check_double(*split);
	data.brightness = ft_atod(*split); //0.0 ~ 1.0
	split++;
	if (add_color(split, &data.color) == -1 || data.brightness < 0 || data.brightness > 1 || checker != 0)
		return (-1);
	add_node(list, data);
	return (0);
}

int add_c(char **split, t_rt_info data, t_list *list)
{
	int checker;

	data.id = "c";
	checker = 0;
	split++;
	if (add_coordinate(split, &data.coor1) == -1)
		return (-1);
	split++;
	if (add_normalized_vector(split, &data.normalized_vector) == -1)
		return (-1);
	split++;
	checker += check_int(*split);
	data.view_degree = ft_atoi(*split); //0~180
	if (data.view_degree < 0 || data.view_degree > 180 || checker != 0)
		return (-1);
	add_node(list, data);
	return (0);
}

int add_l(char **split, t_rt_info data, t_list *list)
{
	int checker;

	data.id = "l";
	checker = 0;
	split++;
	if (add_coordinate(split, &data.coor1) == -1)
		return (-1);
	split++;
	checker += check_double(*split);
	data.brightness = ft_atod(*split);
	split++;
	if (add_color(split, &data.color) == -1 || data.brightness < 0 || data.brightness > 1 || checker != 0)
		return (-1);

	add_node(list, data);
	return (0);
}

int add_sp(char **split, t_rt_info data, t_list *list)
{
	int checker;

	data.id = "sp";
	checker = 0;
	split++;
	if (add_coordinate(split, &data.coor1) == -1)
		return (-1);
	split++;
	checker += check_double(*split);
	data.diameter = ft_atod(*split);
	split++;
	if (add_color(split, &data.color) == -1 || checker != 0)
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
	int checker;

	data.id = "sq";
	checker = 0;
	split++;
	if (add_coordinate(split, &data.coor1) == -1)
		return (-1);
	split++;
	if (add_normalized_vector(split, &data.normalized_vector) == -1)
		return (-1);
	split++;
	checker += check_double(*split);
	data.side_size = ft_atod(*split);
	split++;
	if (add_color(split, &data.color) == -1 || checker != 0)
		return (-1);
	add_node(list, data);
	return (0);
}

int add_cy(char **split, t_rt_info data, t_list *list)
{
	int checker;

	data.id = "cy";
	checker = 0;
	split++;
	if (add_coordinate(split, &data.coor1) == -1)
		return (-1);
	split++;
	if (add_normalized_vector(split, &data.normalized_vector) == -1)
		return (-1);
	split++;
	checker += check_double(*split);
	data.diameter = ft_atod(*split);
	split++;
	checker += check_double(*split);
	data.side_size = ft_atod(*split);
	split++;
	if (add_color(split, &data.color) == -1 || checker != 0)
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
