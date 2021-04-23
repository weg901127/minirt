#include <stdio.h>
#include <fcntl.h>
#include "gnl/get_next_line.h"
#include "minirt.h"
#include <string.h>

static void put_err()
{
	write(1, "Error\n", 6);
	//many of free
}

int count_split(char **split)
{
	int i = 0;
	while (*split++ != 0)
		i++;
	return (i);
}

t_color add_color(char **split, t_color color)
{
	char **tmp_color;

	tmp_color = ft_split(*split, ',');

	color.red = atoi(*tmp_color);//0 ~ 255 나중에 리팩토링하면서 atoi 개조
	tmp_color++;
	color.green = atoi(*tmp_color);
	tmp_color++;
	color.blue = atoi(*tmp_color);

	tmp_color -= 2;//hard coding....should be repair
	allo_free(tmp_color);
	return (color);
}

t_xyz add_coordinate(char **split, t_xyz coor) //copy one for normalized vector
{
	char **coordinate;

	coordinate = ft_split(*split, ',');
	coor.x = atof(*coordinate);
	coordinate++;  
	coor.y = atof(*coordinate);
	coordinate++;  
	coor.z = atof(*coordinate);

	coordinate -= 2;//this too
	allo_free(coordinate);

	return (coor);
}

int add_r(char **split, t_rt_info data, t_list *list)
{
	//notice : split count, element value ex) considered range and type
	data.id = "R";
	split++;
	data.resolution.width = ft_atoi(*split);
	split++;
	data.resolution.height = ft_atoi(*split);
	if (data.resolution.width == 0 || data.resolution.height == 0)//it's better be functionalize
		return (-1);
	add_node(list, data);
	return (0);
}
int add_a(char **split, t_rt_info data, t_list *list)
{
	data.id = "A";
	split++;
	data.brightness = atof(*split); //0.0 ~ 1.0
	split++;
	//data.color = add_color(split, data.color); //0~255 pass add_color function
	add_color(split, data.color);
	add_node(list, data);
	return (0);
}

int add_c(char **split, t_rt_info data, t_list *list)
{
  data.id = "c";
  split++;
  data.coor1 = add_coordinate(split, data.coor1);
  split++;
  data.normalized_vector = add_coordinate(split, data.normalized_vector);//-1 ~ 1 pass~~
  split++;
  data.view_degree = atoi(*split); //0~180
  
  add_node(list, data);
  return (0);
}

int add_l(char **split, t_rt_info data, t_list *list)
{
  data.id = "l";
  split++;
  data.coor1 = add_coordinate(split, data.coor1);
  split++;
  data.brightness = atof(*split);//0 ~ 1
  split++;
  data.color = add_color(split, data.color);
  
  add_node(list, data);
  return (0);
}

int add_sp(char **split, t_rt_info data, t_list *list)
{
  data.id = "sp";
  split++;
  data.coor1 = add_coordinate(split, data.coor1);
  split++;
  data.diameter = atof(*split);
  split++;
  data.color = add_color(split, data.color);
  
  add_node(list, data);
  return (0);
}
int add_pl(char **split, t_rt_info data, t_list *list)
{
	data.id = "pl";
	split++;
	data.coor1 = add_coordinate(split, data.coor1);
	split++;
	data.normalized_vector = add_coordinate(split, data.normalized_vector);
	split++;
	data.color = add_color(split, data.color);

	add_node(list, data);
	return (0);
}

int add_sq(char **split, t_rt_info data, t_list *list)
{
	data.id = "sq";
	split++;
	data.coor1 = add_coordinate(split, data.coor1);
	split++;
	data.normalized_vector = add_coordinate(split, data.normalized_vector);
	split++;
	data.side_size = atof(*split);
	split++;
	data.color = add_color(split, data.color);

	add_node(list, data);
	return (0);
}

int add_cy(char **split, t_rt_info data, t_list *list)
{
	data.id = "cy";
	split++;
	data.coor1 = add_coordinate(split, data.coor1);
	split++;
	data.normalized_vector = add_coordinate(split, data.normalized_vector);
	split++;
	data.diameter = atof(*split);
	split++;
	data.side_size = atof(*split);
	split++;
	data.color = add_color(split, data.color);

	add_node(list, data);
	return (0);
}

int add_tr(char **split, t_rt_info data, t_list *list)
{
	data.id = "tr";
	split++;
	data.coor1 = add_coordinate(split, data.coor1);
	split++;
	data.coor2 = add_coordinate(split, data.coor2);
	split++;
	data.coor3 = add_coordinate(split, data.coor3);
	split++;
	data.color = add_color(split, data.color);
	add_node(list, data);
	return (0);
}

int split_put_data(char **split, t_rt_info data, t_list *list)
{
	int cnt;
	cnt = count_split(split);
	if (strcmp(*split, "R") == 0 && cnt == 3)
		return (add_r(split, data, list));
	else if (strcmp(*split, "A") == 0 && cnt == 3)
		return (add_a(split, data, list));
	else if (strcmp(*split, "c") == 0 && cnt == 4)
		return (add_c(split, data, list));
	else if (strcmp(*split, "l") == 0 && cnt == 4)
		return (add_l(split, data, list));    
	else if (strcmp(*split, "sp") == 0 && cnt == 4)
		return (add_sp(split, data, list));
	else if (strcmp(*split, "pl") == 0 && cnt == 4)
		return (add_pl(split, data, list));
	else if (strcmp(*split, "sq") == 0 && cnt == 5)
		return (add_sq(split, data, list));    
	else if (strcmp(*split, "cy") == 0 && cnt == 6)
		return (add_cy(split, data, list));
	else if (strcmp(*split, "tr") == 0 && cnt == 5)
		return (add_tr(split, data, list));
	else if (strcmp(*split, "") == 0)
		return (0);
	return (-1);
}

int main(int argc, char *argv[]) {
	char *line;
	char **split;
	t_list *list;
	t_rt_info data;

	init_list(&list);

	if (argc == 2 && strcmp(argv[1] + strlen(argv[1]) - 3,".rt") == 0)
	{
		int fd = open(argv[1],O_RDWR);
		while (get_next_line(fd, &line) > 0)
		{
			if (*line != '\0')
			{
				if (strcmp(line, "") == 0)
					*split = "";
				else
					split = ft_split(line, ' ');
				if (split_put_data(split, data, list) < 0)
				{
					put_err();
					break;
				}
				printf("%s\n",list->tail->data.id);
				split = allo_free(split);
			}
			free(line);
		}
		del_node(&list);
		close(fd);
	}
	else
		put_err();
	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
