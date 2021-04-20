#include "minirt.h"


static void put_err()
{
  write(1, "Error\n", 6);
}

static void	free_split(char ***split)
{
	int k;

	k = 0;
	while(*(*split + k) != 0)
		free(*(*split + k++));
	free(*split);
}

void set_coor1(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;
	char		**tmp2;

	tmp = *split;
	tmp += seq;
	tmp2 = ft_split(*tmp, ',');
	data->coor1.x = ft_atoi(*tmp2);
	data->coor1.y = ft_atoi(*(tmp2 + 1));
	data->coor1.z = ft_atoi(*(tmp2 + 2));
	free_split(&tmp2);
}

void set_coor2(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;
	char		**tmp2;

	tmp = *split;
	tmp += seq;
	tmp2 = ft_split(*tmp, ',');
	data->coor2.x = ft_atoi(*tmp2);
	data->coor2.y = ft_atoi(*(tmp2 + 1));
	data->coor2.z = ft_atoi(*(tmp2 + 2));
	free_split(&tmp2);
}

void set_coor3(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;
	char		**tmp2;

	tmp = *split;
	tmp += seq;
	tmp2 = ft_split(*tmp, ',');
	data->coor3.x = ft_atoi(*tmp2);
	data->coor3.y = ft_atoi(*(tmp2 + 1));
	data->coor3.z = ft_atoi(*(tmp2 + 2));
	free_split(&tmp2);
}

void set_vector(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;
	char		**tmp2;

	tmp = *split;
	tmp += seq;
	tmp2 = ft_split(*tmp, ',');
	data->normalized_vector.x = ft_atoi(*tmp2);
	data->normalized_vector.y = ft_atoi(*(tmp2 + 1));
	data->normalized_vector.z = ft_atoi(*(tmp2 + 2));
	free_split(&tmp2);
}

void set_color(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;
	char		**tmp2;

	tmp = *split;
	tmp += seq;
	tmp2 = ft_split(*tmp, ',');
	data->color.red = ft_atoi(*tmp2);
	data->color.green = ft_atoi(*(tmp2 + 1));
	data->color.blue = ft_atoi(*(tmp2 + 2));
	free_split(&tmp2);
}

void set_view_degree(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->view_degree = ft_atoi(*tmp);
}

void set_brightness(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->brightness = ft_atoi(*tmp);
}

void set_side_size(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->side_size = ft_atoi(*tmp);
}

void set_diameter(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->diameter = ft_atoi(*tmp);
}

void set_width_height(char ***split, t_rt_info *data, int seq)
{
	char		**tmp;

	tmp = *split;
	tmp += seq;
	data->resolution.width = ft_atoi(*tmp);
	tmp++;
	data->resolution.width = ft_atoi(*tmp);
}

static void set_resolution(char **split, t_list **list)
{
	t_rt_info	data;

	data.id = 'R';
	set_width_height(&split, &data, 1);
	add_node(*list, data);
}

static void set_ambient(char **split, t_list **list)
{
	t_rt_info	data;

	data.id = 'A';
	set_brightness(&split, &data, 1);
	set_color(&split, &data, 2);
	add_node(*list, data);
}

static void set_camera(char **split, t_list **list)
{
	t_rt_info	data;

	data.id = 'C';
	set_coor1(&split, &data, 1);
	set_vector(&split, &data, 2);
	set_view_degree(&split, &data, 3);
	add_node(*list, data);
}

static void set_light(char **split, t_list **list)
{
	t_rt_info	data;

	data.id = 'l';
	set_coor1(&split, &data, 1);
	set_brightness(&split, &data, 2);
	set_color(&split, &data, 3);
	add_node(*list, data);
}

static void set_sphere(char **split, t_list **list)
{
	t_rt_info	data;

	data.id = 's';
	set_coor1(&split, &data, 1);
	set_diameter(&split, &data, 2);
	set_color(&split, &data, 3);
	add_node(*list, data);
}

static void set_plane(char **split, t_list **list)
{
	t_rt_info	data;

	data.id = 'p';
	set_coor1(&split, &data, 1);
	set_vector(&split, &data, 2);
	set_color(&split, &data, 3);
	add_node(*list, data);
}

static void set_square(char **split, t_list **list)
{
	t_rt_info	data;

	data.id = 'q';
	set_coor1(&split, &data, 1);
	set_vector(&split, &data, 2);
	set_side_size(&split, &data, 3);
	set_color(&split, &data, 4);
	add_node(*list, data);
}

static void set_cylinder(char **split, t_list **list)
{
	t_rt_info	data;

	data.id = 'y';
	set_coor1(&split, &data, 1);
	set_vector(&split, &data, 2);
	set_diameter(&split, &data, 3);
	set_side_size(&split, &data, 4);
	set_color(&split, &data, 5);
	add_node(*list, data);
}

static void set_triangle(char **split, t_list **list)
{
	t_rt_info	data;

	data.id = 't';
	set_coor1(&split, &data, 1);
	set_coor2(&split, &data, 2);
	set_coor3(&split, &data, 3);
	set_color(&split, &data, 4);
	add_node(*list, data);
}

static void check_var(char ***split, t_list **list)
{
	int		k;
	char	**tmp;

	k = 0;
	tmp = *split;
	while (*tmp++)
		k++;
	if (***split == 'R' && k == 3)
		set_resolution(*split, list);
	else if(***split == 'A' && k == 3)
		set_ambient(*split, list);
	else if(***split == 'c' && k == 4)
		set_camera(*split, list);
	else if(***split == 'l' && k == 4)
		set_light(*split, list);
	else if(***split == 's' && k == 4)
		set_sphere(*split, list);
	else if(***split == 'p' && k == 4)
		set_plane(*split, list);
	else if(***split == 's' && k == 5)
		set_square(*split, list);
	else if(***split == 'c' && k == 6)
		set_cylinder(*split, list);
	else if(***split == 't' && k == 5)
		set_triangle(*split, list);
	else
		put_err();
}

int main()
//int main(int argc, char *argv[])
{
	char		*line;
	char		**split;
	t_list		*list;
	t_rt_info	data;

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
			check_var(&split, &list);
			free_split(&split);
		}
		free(line);
	}
	list->cur = list->head;
	while (list->cur)
	{
		printf("%c",list->cur->data.id);
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
