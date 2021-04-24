#include "minirt.h"
#define ERROR 1
#define DONE 0
#define R_FLAG 1
#define A_FLAG 2

int	put_err(char **line, int fd, t_list **list)
{
	write(1, "Error\n", 6);
	free(*line);
	close(fd);
	free_node(list);
	return (ERROR);
}

static void	free_split(char ***split)
{
	int k;

	k = 0;
	while (*(*split + k) != 0)
		free(*(*split + k++));
	free(*split);
}

int	count_split(char **split)
{
	int k;

	k = 0;
	while (*split++)
		k++;
	return (k);
}

int count_char(char **split, char c)
{
	int		k;
	char	*tmp;

	k = 0;
	tmp = *split;
	while (*tmp++)
	{
		if (*tmp == c)
			k++;
	}
	return (k);
}

int set_coor1(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;
	char		**tmp2;

	tmp = *split;
	tmp += seq;
	if (count_char(tmp, ',') != 2)
		return (ERROR);
	tmp2 = ft_split(*tmp, ',');
	data->coor1.x = atof(*tmp2);
	data->coor1.y = atof(*(tmp2 + 1));
	data->coor1.z = atof(*(tmp2 + 2));
	free_split(&tmp2);
	return (DONE);
}

int set_coor2(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;
	char		**tmp2;

	tmp = *split;
	tmp += seq;
	if (count_char(tmp, ',') != 2)
		return (ERROR);
	tmp2 = ft_split(*tmp, ',');
	data->coor2.x = atof(*tmp2);
	data->coor2.y = atof(*(tmp2 + 1));
	data->coor2.z = atof(*(tmp2 + 2));
	free_split(&tmp2);
	return (DONE);
}

int set_coor3(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;
	char		**tmp2;

	tmp = *split;
	tmp += seq;
	if (count_char(tmp, ',') != 2)
		return (ERROR);
	tmp2 = ft_split(*tmp, ',');
	data->coor3.x = atof(*tmp2);
	data->coor3.y = atof(*(tmp2 + 1));
	data->coor3.z = atof(*(tmp2 + 2));
	free_split(&tmp2);
	return (DONE);
}

int set_vector(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;
	char		**tmp2;

	tmp = *split;
	tmp += seq;
	if (count_char(tmp, ',') != 2)
		return (ERROR);
	tmp2 = ft_split(*tmp, ',');
	data->normalized_vector.x = atof(*tmp2);
	data->normalized_vector.y = atof(*(tmp2 + 1));
	data->normalized_vector.z = atof(*(tmp2 + 2));
	free_split(&tmp2);
	if (data->normalized_vector.x < -1\
	|| data->normalized_vector.x > 1\
	|| data->normalized_vector.y < -1\
	|| data->normalized_vector.y > 1\
	|| data->normalized_vector.z < -1\
	|| data->normalized_vector.z > 1)
		return (ERROR);
	return (DONE);
}

int set_color(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;
	char		**tmp2;

	tmp = *split;
	tmp += seq;
	if (count_char(tmp, ',') != 2)
		return (ERROR);
	tmp2 = ft_split(*tmp, ',');
	data->color.red = atof(*tmp2);
	data->color.green = atof(*(tmp2 + 1));
	data->color.blue = atof(*(tmp2 + 2));
	free_split(&tmp2);
	if (data->color.red < 0 \
	|| data->color.red > 255\
	|| data->color.green < 0\
	|| data->color.green > 255\
	|| data->color.blue < 0\
	|| data->color.blue > 255)
		return (ERROR);
	return (DONE);
}

int set_view_degree(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->view_degree = ft_atoi(*tmp);
	if (data->view_degree < 0 || data->view_degree > 180)
		return (ERROR);
	return (DONE);
}

int set_brightness(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->brightness = atof(*tmp);
	if (data->brightness < 0 || data->brightness > 1)
		return (ERROR);
	return (DONE);
}

void set_side_size(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->side_size = atof(*tmp);
}

void set_diameter(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->diameter = atof(*tmp);
}

int set_width_height(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->resolution.width = ft_atoi(*tmp);
	tmp++;
	data->resolution.height = ft_atoi(*tmp);
	if (data->resolution.width <= 0 || data->resolution.height <= 0)
		return (ERROR);
	return (DONE);
}

int set_resolution(char **split, t_list **list, int *capital)
{
	t_rt_info	data;

	*capital += R_FLAG;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "R";
	set_width_height(&split, &data, 1);
	add_node(*list, &data);
	return (DONE);
}

int set_ambient(char **split, t_list **list, int *capital)
{
	t_rt_info	data;
	int			res;

	*capital += A_FLAG;
	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "A";
	set_brightness(&split, &data, 1);
	res |= set_color(&split, &data, 2);
	add_node(*list, &data);
	return (res);
}

int set_camera(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "c";
	res |= set_coor1(&split, &data, 1);
	res |= set_vector(&split, &data, 2);
	set_view_degree(&split, &data, 3);
	add_node(*list, &data);
	return (res);
}

int set_light(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "l";
	res |= set_coor1(&split, &data, 1);
	set_brightness(&split, &data, 2);
	res |= set_color(&split, &data, 3);
	add_node(*list, &data);
	return (res);
}

int set_sphere(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "sp";
	res |= set_coor1(&split, &data, 1);
	set_diameter(&split, &data, 2);
	res |= set_color(&split, &data, 3);
	add_node(*list, &data);
	return (res);
}

int set_plane(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "pl";
	res |= set_coor1(&split, &data, 1);
	res |= set_vector(&split, &data, 2);
	res |= set_color(&split, &data, 3);
	add_node(*list, &data);
	return (res);
}

int set_square(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "sq";
	res |= set_coor1(&split, &data, 1);
	res |= set_vector(&split, &data, 2);
	set_side_size(&split, &data, 3);
	res |= set_color(&split, &data, 4);
	add_node(*list, &data);
	return (res);
}

int set_cylinder(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "cy";
	res |= set_coor1(&split, &data, 1);
	res |= set_vector(&split, &data, 2);
	set_diameter(&split, &data, 3);
	set_side_size(&split, &data, 4);
	res |= set_color(&split, &data, 5);
	add_node(*list, &data);
	return (res);
}

int set_triangle(char **split, t_list **list)
{
	t_rt_info	data;
	int			res;

	res = DONE;
	ft_memset(&data, 0, sizeof(t_rt_info));
	data.id = "tr";
	res |= set_coor1(&split, &data, 1);
	res |= set_coor2(&split, &data, 2);
	res |= set_coor3(&split, &data, 3);
	res |= set_color(&split, &data, 4);
	add_node(*list, &data);
	return (res);
}

int check_var(char ***split, t_list **list)
{
	int			k;
	static int	capital;

	k = count_split(*split);
	if (***split == 'R' && k == 3 && !(capital & R_FLAG))
		return (set_resolution(*split, list, &capital));
	else if(***split == 'A' && k == 3 && !(capital & A_FLAG))
		return (set_ambient(*split, list, &capital));
	else if(***split == 'c' && k == 4)
		return (set_camera(*split, list));
	else if(***split == 'l' && k == 4)
		return (set_light(*split, list));
	else if(***split == 's' && k == 4)
		return (set_sphere(*split, list));
	else if(***split == 'p' && k == 4)
		return (set_plane(*split, list));
	else if(***split == 's' && k == 5)
		return (set_square(*split, list));
	else if(***split == 'c' && k == 6)
		return (set_cylinder(*split, list));
	else if(***split == 't' && k == 5)
		return (set_triangle(*split, list));
	return (ERROR);
}

int main()
//int main(int argc, char *argv[])
{
	int			res;
	char		*line;
	char		**split;
	t_list		*list;

	init_list(&list);
//	if (argc == 2 && strcmp(argv[1] + strlen(argv[1]) - 3,".rt") == 0)
//	{
//		int fd = open(argv[1],O_RDWR);
	int fd = open("mini.rt",O_RDWR);

	while(get_next_line(fd, &line) >= 0)
	{
		if (*line != 0)
		{
			split = ft_split(line, ' ');
			res = check_var(&split, &list);
			free_split(&split);
			if (res)
				return (put_err(&line, fd, &list));	
		}
			free(line);
	}
	free(line);
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
	close(fd);
	free_node(&list);
//	}
//	else
//	put_err();
	//while(1);
	return 0;
}


//R, A는 필수(1개)
//c, cy 구분
//필요한 요소만 정확히 들어왔는지(슬데없는 값이 추가로 있지 않은지)
//값 범위 유효성검사


//단방향
//초기화
//삽입, 탐색
/*

char *id
s_xyz coordinates1
s_xyz coordinates2
s_xyz coordinates3
s_xyz 3d normalized orientation vector.(-1 ~ 1)
s_color color
un int view_degree (0 ~ 180)
un float brightness
un float diameter
un float side_size

*/
